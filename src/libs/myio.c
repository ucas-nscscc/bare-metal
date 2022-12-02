#include <drivers/uart.h>
#include <stdarg.h>
#include <types.h>
#include <string.h>

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

static int itoa(int i, char *buf)
{
	int neg = 0, len;
	char *buf_begin = buf;
	char temp;

	if (i < 0) {
		neg = 1;
		i = -i;
	}

	do {
		*buf++ = (i % 10) + '0';
		i /= 10;
	} while (i > 0);

	if (neg == 1) {
		*buf++ = '-';
	}

	*buf = '\0';
	len = buf - buf_begin;
	
	for (buf--; buf > buf_begin; buf--, buf_begin++) {
		temp = *buf;
		*buf = *buf_begin;
		*buf_begin = temp;
	}

	return len;
}

int vsprintk(char *out, const char *fmt, va_list ap) {
	int ret = 0;
	char buf[24], ch;
	char *str = NULL;

	while ((ch = *(fmt++))) {
		int len = 1;
		if (ch == '%') {
			ch = *(fmt++);
			switch (ch) {
				case 'd':
					len = itoa(va_arg(ap, int), buf);
					strcpy(&out[ret], buf);
					break;
				case 'c':
					str = va_arg(ap, char*);
					out[ret] = str[0];
					break;
				case 's':
					str = va_arg(ap, char*);
					len = strlen(str);
					strcpy(&out[ret], str);
					break;
				default:
					break;
			}
		} else {
			out[ret] = ch;
		}
		ret += len;
	}
	out[ret] = '\0';
	return ret;
}

int printk(const char *fmt, ...) {
	char buf[256];
	int ret;
	va_list ap;

	va_start(ap, fmt);
	ret = vsprintk(buf, fmt, ap);
	va_end(ap);

	uart_puts(buf);
	return ret;
}

int sprintk(char *out, const char *fmt, ...) {
	int ret;
	va_list ap;
	
	va_start(ap, fmt);
	ret = vsprintk(out, fmt, ap);
	va_end(ap);

	return ret;
}

int snprintk(char *out, size_t n, const char *fmt, ...) {
	// panic("Not implemented");
	return 0;
}

int vsnprintk(char *out, size_t n, const char *fmt, va_list ap) {
	// panic("Not implemented");
	return 0;
}
