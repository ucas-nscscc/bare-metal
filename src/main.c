#include <soc.h>
#include <mysoc.h>
#include <funcs.h>
#include <stdio.h>
#include <traps.h>
#include <uart.h>

int main()
{
	struct soc *mysoc = mysoc_init();
	char str[10] = "hello\n";
	unsigned int crmd;
	unsigned int ecfg;
	unsigned int eentry;

	uart_init();

	uart_putc('h');
	uart_putc('e');
	uart_puts("hello");

	trap_init();
	crmd = csr_read(CSR_CRMD);
	ecfg = csr_read(CSR_ECFG);
	eentry = csr_read(CSR_EENTRY);
	uart_puts("crmd: ");
	print_hex(crmd);
	uart_puts("ecfg: ");
	print_hex(ecfg);
	uart_puts("eentry: ");
	print_hex(eentry);	

	// mysoc->led->turn_on_mask(mysoc->led, 0x7);

	horse_race_lamp(mysoc);

	fib(mysoc);

	mysoc->led_rg0->turn_on(mysoc->led_rg0, LED_RG_GREEN);
	mysoc->led_rg1->turn_on(mysoc->led_rg1, LED_RG_GREEN);
	mysoc->led->turn_off_mask(mysoc->led, 0xffff);
	mysoc->led->turn_on_num(mysoc->led, 8);
	mysoc->num->set_all(mysoc->num, 0);

	return 0;
}
