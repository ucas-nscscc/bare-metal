#ifndef _TIMER_H
#define _TIMER_H

#include <drivers/dev_desc.h>

struct timer {
	struct dev_desc dev_desc;
	uint freq;
};

#endif
