#include <uart.h>

static char hex_digits[] = "0123456789abcdef";

void print_hex(unsigned int x)
{
	int i = 0;
	while (i < 8) {
		uart_putc(hex_digits[(x & 0xf0000000) >> 28]);
		x <<= 4;
		i++;
	}
	uart_putc('\n');
}
