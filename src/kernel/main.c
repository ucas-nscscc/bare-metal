#include <funcs.h>
#include <myio.h>
#include <irq.h>
#include <asm/traps.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>

int main()
{
	irq_disable();
	uart_init();
	gpio_init();
	// struct gpio *confreg = mysoc_init();
	trap_init();
	irq_enable();

	int led = gpio_open("led", "w");

	print_hex(led);
	gpio_write(led, 0xf);

	gpio_close(led);

	horse_race_lamp();

	// fib(confreg);

	// confreg->led_rg0->turn_on(confreg->led_rg0, LED_RG_GREEN);
	// confreg->led_rg1->turn_on(confreg->led_rg1, LED_RG_GREEN);
	// confreg->led->turn_off_mask(confreg->led, 0xffff);
	// confreg->led->turn_on_num(confreg->led, 8);
	// confreg->num->set_all(confreg->num, 0);

	return 0;
}
