#ifndef _MYIO_H
#define _MYIO_H

#include <stdarg.h>
#include <types.h>

void print_hex(unsigned int x);
int printk (const char *format, ...);
int sprintk (char *str, const char *format, ...);
int snprintk (char *str, size_t size, const char *format, ...);
int vsprintk (char *str, const char *format, va_list ap);
int vsnprintk (char *str, size_t size, const char *format, va_list ap);

#endif
