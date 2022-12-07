#include "types.h"
#include <asm/thread_info.h>
#include <ffs.h>
#include <mm.h>
#include <sched.h>
#include <asm/ptrace.h>
#include <asm/loongarchregs.h>
#include <myio.h>

extern void switch_context(struct thread_info *prev, struct thread_info *next);

static uint pnum = 1;
static struct task_struct kernel = {
	.pid = 0,
};
static struct thread_info kthread = {
	.task = &kernel,
	.next = NULL,
};
static struct thread_info *ready_queue = NULL;

static uint alloc_pid()
{
	// printk("alloc pid: %d\n", pnum);
	return pnum++;
}

void kernel_thread(int (*fn)(void *), void *arg)
{
	ulong new_page;
	ulong kernel_sp;
	struct thread_info *thread;
	struct task_struct *task; 
	struct task_frame *frame;
	int i;

	new_page = (ulong)alloc_page();
	kernel_sp = new_page + PAGE_SIZE;

	thread = (struct thread_info *)new_page;
	kernel_sp -= sizeof(struct task_struct);
	task = (struct task_struct *)kernel_sp;
	kernel_sp -= sizeof(struct task_frame);
	frame = (struct task_frame *)kernel_sp;

	thread->task = task;
	thread->next = ready_queue;
	ready_queue = thread;

	task->kernel_sp = (void *)kernel_sp;
	task->pid = alloc_pid();

	frame->ra = (ulong)fn;
	frame->tp = (ulong)thread;
	frame->a0 = (ulong)arg;
	for (i = 0; i <= GPR_S8 - GPR_S0; i++)
		frame->s[i] = 0;
}

void sched_init()
{
	__current_thread_info = &kthread;
}

void yield()
{
	struct thread_info *next = ready_queue;
	struct thread_info *prev = current_thread_info();
	struct thread_info *last = ready_queue;
	if (next == NULL)
		return;
	
	while (last->next != NULL)
		last = last->next;
	// add prev to the tail of ready queue
	if (prev->task->pid != 0) {
		last->next = prev;
		prev->next = NULL;
	}
	// dequeue next from ready queue
	ready_queue = next->next;
	next->next = NULL;

	// printk("switch %d to %d\n", prev->task->pid, next->task->pid);

	switch_context(prev, next);
}
