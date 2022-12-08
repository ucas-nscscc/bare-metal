#ifndef _SCHED_H
#define _SCHED_H

#include <types.h>

struct task_struct {
	uint	pid;
	void	*kernel_sp;
	void	*user_sp;
}__attribute__((aligned(4)));

void sched_init();
void kernel_thread(int (*fn)(void *), void *arg);
void yield();

#endif
