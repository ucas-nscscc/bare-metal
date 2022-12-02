#include <drivers/timer.h>
#include <drivers/dev_desc.h>
#include <asm/mysoc.h>
#include <time.h>

#define TIMER_OFFSET		0xe000
#define TIMER_ADDR		(GPIO_BASE + TIMER_OFFSET)

uint constant_timer_read()
{
	return *(volatile unsigned *)(TIMER_ADDR);
}

void constant_timer_write(uint value)
{
	*(volatile unsigned *)(TIMER_ADDR) = value;
}

static struct timer constant_timer = {
	.dev_desc = {
		.name = "constant timer",
		.flag = DEV_READ | DEV_WRITE,
		.opend = 0x0,
		.read = constant_timer_read,
		.write = constant_timer_write,
	},
	.freq = MYSOC_TIMER_FREQ
};

void constant_timer_init()
{
	register_timer(&constant_timer);
}
