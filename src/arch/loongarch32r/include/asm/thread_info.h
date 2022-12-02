#ifndef _ARCH_THREAD_INFO_H
#define _ARCH_THREAD_INFO_H

#include <sched.h>
#include <types.h>
#include <asm/ptrace.h>

struct thread_info {
	struct task_struct	task;
	struct pt_regs		*regs;
	struct thread_info	*next;
};

register struct thread_info *__current_thread_info __asm__("$r2");

static inline struct thread_info *current_thread_info(void)
{
	return __current_thread_info;
}

#endif
