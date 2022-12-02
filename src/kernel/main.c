#include <funcs.h>
#include <myio.h>
#include <irq.h>
#include <asm/mysoc.h>
#include <asm/traps.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>

int main()
{
	uart_init();

	uart_puts("uart initialized.\n");

	struct gpio *confreg = mysoc_init();

	uart_puts("gpio initialized.\n");

	trap_init();

	uart_puts("trap initialized.\n");

	horse_race_lamp(confreg);

	fib(confreg);

	confreg->led_rg0->turn_on(confreg->led_rg0, LED_RG_GREEN);
	confreg->led_rg1->turn_on(confreg->led_rg1, LED_RG_GREEN);
	confreg->led->turn_off_mask(confreg->led, 0xffff);
	confreg->led->turn_on_num(confreg->led, 8);
	confreg->num->set_all(confreg->num, 0);

	return 0;
}
