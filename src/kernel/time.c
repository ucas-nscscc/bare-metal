#include <types.h>
#include <time.h>
#include <drivers/timer.h>
#include <myio.h>
#include <asm/mysoc.h>

static struct timer *timer = NULL;

static uint get_ticks()
{
	if (timer == NULL) {
		printk("timer not registered!\n");
		return 0;
	}
	return timer->dev_desc.read();
}

static uint ticks_to_us(uint ticks)
{
	if (timer == NULL) {
		printk("timer not registered!\n");
		return 0;
	}
	return ticks / (timer->freq / (1 MHz));
}

static uint ticks_to_sec(uint ticks)
{
	if (timer == NULL) {
		printk("timer not registered!\n");
		return 0;
	}
	return ticks / (timer->freq / (1 MHz) * (1 MHz));
}

uint get_us()
{
	uint ticks = get_ticks();
	return ticks_to_us(ticks);
}

uint get_sec()
{
	uint ticks = get_ticks();
	return ticks_to_sec(ticks);
}

void register_timer(struct timer *timer_dev)
{
	timer = timer_dev;
	timer->dev_desc.write(0);
}

void time_init()
{
	arch_time_init();
}
