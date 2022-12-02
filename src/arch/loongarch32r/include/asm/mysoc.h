#ifndef _ARCH_MYSOC_H
#define _ARCH_MYSOC_H

#include <drivers/gpio.h>
#include <time.h>

#define GPIO_BASE		0xbfaf0000

#define COM1_BAUD_DDL	0x36 // 50M CPU clk
#define COM1		0x1fe00000
#define COM1_IRQ	2

#define MYSOC_TIMER_FREQ	(100 MHz)
#define LED_RG_GREEN		(0x1)
#define LED_RG_RED		(0x2)
#define LED_RG_GREEN_RED	(LED_RG_GREEN | LED_RG_RED)

#define PMEM_BASE	0x1c009000
#define PMEM_SIZE	0x00007000

void arch_gpio_init();
void arch_time_init();
void arch_mm_init(uint *pmem_base, uint *pmem_size);

extern void confreg_init();
extern void constant_timer_init();

#endif
