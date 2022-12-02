#include <asm/thread_info.h>
#include <ffs.h>
#include <mm.h>
#include <sched.h>
#include <asm/ptrace.h>
#include <asm/loongarchregs.h>
#include <myio.h>

extern void switch_context(struct thread_info *prev, struct thread_info *next);

static struct thread_info pcbs[32];
static uint pcb_bitmap = 0;
static struct thread_info kernel = {
	.task = {
		.pid = 0,
	},
	.next = NULL,
};
static struct thread_info *ready_queue = NULL;
static struct thread_info *current_thread = &kernel;

static struct thread_info *alloc_pcb()
{
	uint pid = ffz(pcb_bitmap);
	if (pid >= 32) {
		return NULL;
	}
	pcb_bitmap |= (0x1 << pid);
	printk("pid: %d, pcb bitmap: %d\n", pid, pcb_bitmap);
	return &pcbs[pid];
}

void kernel_thread(int (*fn)(void *), void *arg)
{
	struct thread_info *pcb = alloc_pcb();
	char *kernel_sp = (char *)((uint)alloc_page() + PAGE_SIZE);
	struct pt_regs *regs;
	int i;

	pcb->next = ready_queue;
	ready_queue = pcb;

	kernel_sp = (char *)((uint)kernel_sp - (uint)sizeof(struct pt_regs));
	pcb->task.kernel_sp = (void *)kernel_sp;
	regs = (struct pt_regs *)kernel_sp;

	regs->gpr[GPR_RA] = (uint) fn;
	regs->gpr[GPR_TP] = (uint) pcb;
	regs->gpr[GPR_A0] = (uint) arg;
	for (i = GPR_S0; i <= GPR_S8; i++)
		regs->gpr[i] = 0;
}

void sched_init()
{
	int i;
	for (i = 0; i < 32; i++)
		pcbs[i].task.pid = i + 1;
}

void yield()
{
	struct thread_info *next = ready_queue;
	struct thread_info *prev = current_thread;
	struct thread_info *last = ready_queue;
	if (next == NULL)
		return;
	
	while (last->next != NULL)
		last = last->next;
	// add prev to the tail of ready queue
	if (prev->task.pid != 0) {
		last->next = prev;
		prev->next = NULL;
	}
	// dequeue next from ready queue
	ready_queue = next->next;
	next->next = NULL;

	current_thread = next;

	switch_context(prev, next);
}
