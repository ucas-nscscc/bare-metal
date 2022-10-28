#ifndef _TIMER_H
#define _TIMER_H

#include <soc.h>

#define Hz * (1)
#define KHz * (1000 Hz)
#define MHz * (1000 KHz)

struct timer {
	unsigned int freq;
	void (*set_count)(unsigned int);
	unsigned int (*get_count)();
	void (*delay)(unsigned int);
	void (*mdelay)(unsigned int);
	void (*udelay)(unsigned int);
};

#endif
