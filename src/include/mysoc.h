#ifndef _MYSOC_H
#define _MYSOC_H

#include <soc.h>
#include <timer.h>

#define GPIO_BASE               0xbfaf0000
#define IO_SIMU_OFFSET		0xff00
#define UART_OFFSET		0xff10
#define SIMU_FLAG_OFFSET	0xff20
#define OPEN_TRACE_OFFSET	0xff30
#define NUM_MONITOR_OFFSET	0xff40
#define LED_OFFSET		0xf020
#define LED_RG0_OFFSET		0xf030
#define LED_RG1_OFFSET		0xf040
#define NUM_OFFSET		0xf050
#define SWITCH_OFFSET		0xf060
#define BTN_KEY_OFFSET		0xf070
#define BTN_STEP_OFFSET		0xf080
#define SW_INTER_OFFSET		0xf090 //switch interleave
#define TIMER_OFFSET		0xe000

#define COM1_BAUD_DDL   0x36 // 50M CPU clk
#define COM1            0x1fe00000
#define COM1_IRQ        2

#define IO_SIMU_ADDR		(GPIO_BASE + IO_SIMU_OFFSET)
#define UART_ADDR		(GPIO_BASE + UART_OFFSET)
#define SIMU_FLAG_ADDR		(GPIO_BASE + SIMU_FLAG_OFFSET)
#define OPEN_TRACE_ADDR		(GPIO_BASE + OPEN_TRACE_OFFSET)
#define NUM_MONITOR_ADDR	(GPIO_BASE + NUM_MONITOR_OFFSET)
#define LED_ADDR		(GPIO_BASE + LED_OFFSET)
#define LED_RG0_ADDR		(GPIO_BASE + LED_RG0_OFFSET)
#define LED_RG1_ADDR		(GPIO_BASE + LED_RG1_OFFSET)
#define NUM_ADDR		(GPIO_BASE + NUM_OFFSET)
#define SWITCH_ADDR		(GPIO_BASE + SWITCH_OFFSET)
#define BTN_KEY_ADDR		(GPIO_BASE + BTN_KEY_OFFSET)
#define BTN_STEP_ADDR		(GPIO_BASE + BTN_STEP_OFFSET)
#define SW_INTER_ADDR		(GPIO_BASE + SW_INTER_OFFSET) //switch interleave
#define TIMER_ADDR		(GPIO_BASE + TIMER_OFFSET)

#define SOC_LED		(*(volatile unsigned *)LED_ADDR     )
#define SOC_LED_RG0	(*(volatile unsigned *)LED_RG0_ADDR )
#define SOC_LED_RG1	(*(volatile unsigned *)LED_RG1_ADDR )
#define SOC_NUM		(*(volatile unsigned *)NUM_ADDR     )
#define SOC_SWITCH	(*(volatile unsigned *)SWITCH_ADDR  )
#define SOC_BTN_KEY	(*(volatile unsigned *)BTN_KEY_ADDR )
#define SOC_BTN_STEP	(*(volatile unsigned *)BTN_STEP_ADDR)
#define SOC_TIMER	(*(volatile unsigned *)TIMER_ADDR   )

#define MYSOC_TIMER_FREQ	(100 MHz)
#define LED_RG_GREEN		(0x1)
#define LED_RG_RED		(0x2)
#define LED_RG_GREEN_RED 	(LED_RG_GREEN | LED_RG_RED)

static inline unsigned int
inw(unsigned int port) {
    unsigned int data = *((volatile unsigned int *) port);
    return data;
}

static inline void
outw(unsigned int port, unsigned int data) {
    *((volatile unsigned int *) port) = data;
}

struct soc *mysoc_init();

#endif
