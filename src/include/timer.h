#ifndef _TIMER_H
#define _TIMER_H

#include <soc.h>

#define Hz * (1)
#define KHz * (1000 Hz)
#define MHz * (1000 KHz)

struct timer {
	void *addr;
	unsigned int freq;
	void (*set_count)(struct timer *, unsigned int);
	unsigned int (*get_count)(struct timer *);
	void (*delay)(struct timer *, unsigned int);
	void (*mdelay)(struct timer *, unsigned int);
	void (*udelay)(struct timer *, unsigned int);
};

#endif
