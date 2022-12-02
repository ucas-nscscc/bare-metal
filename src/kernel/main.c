#include <funcs.h>
#include <myio.h>
#include <irq.h>
#include <time.h>
#include <asm/traps.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>

int main()
{
	irq_disable();
	uart_init();
	gpio_init();
	time_init();
	trap_init();
	irq_enable();

	horse_race_lamp();

	fib();

	while (1) {
		;
	}

	return 0;
}
