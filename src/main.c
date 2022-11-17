#include <soc.h>
#include <mysoc.h>
#include <funcs.h>
#include <stdio.h>
#include <traps.h>
#include <uart.h>

int main()
{
	struct soc *mysoc = mysoc_init();

	uart_init();

	uart_puts("Hello, world!\n");

	trap_init();

	horse_race_lamp(mysoc);

	fib(mysoc);

	mysoc->led_rg0->turn_on(mysoc->led_rg0, LED_RG_GREEN);
	mysoc->led_rg1->turn_on(mysoc->led_rg1, LED_RG_GREEN);
	mysoc->led->turn_off_mask(mysoc->led, 0xffff);
	mysoc->led->turn_on_num(mysoc->led, 8);
	mysoc->num->set_all(mysoc->num, 0);

	return 0;
}
