#ifndef _UART_H
#define _UART_H

void uart_init(void);
void uart_putc_sub(int c);
void uart_putc(int c);
void uart_puts(char *str);
void uart_interrupt();

#endif
