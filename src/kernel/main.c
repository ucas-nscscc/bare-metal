#include <funcs.h>
#include <myio.h>
#include <irq.h>
#include <time.h>
#include <mm.h>
#include <sched.h>
#include <asm/traps.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>

int main()
{
	irq_disable();
	uart_init();
	gpio_init();
	time_init();
	mm_init();
	sched_init();
	trap_init();
	irq_enable();

	kernel_thread(horse_race_lamp, NULL);
	kernel_thread(fib, NULL);

	while (1) {
		yield();
	}

	return 0;
}
