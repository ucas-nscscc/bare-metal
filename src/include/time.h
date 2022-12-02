#ifndef _TIME_H
#define _TIME_H

#include <types.h>
#include <drivers/timer.h>

#define Hz * (1)
#define KHz * (1000 Hz)
#define MHz * (1000 KHz)

void time_init();

void register_timer(struct timer *timer_dev);

uint get_us();
uint get_sec();

#endif
