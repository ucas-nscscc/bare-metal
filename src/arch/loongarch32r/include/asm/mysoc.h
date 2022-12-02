#ifndef _MYSOC_H
#define _MYSOC_H

#include <drivers/gpio.h>
#include <time.h>

#define GPIO_BASE		0xbfaf0000
#define LED_OFFSET		0xf020
#define LED_RG0_OFFSET		0xf030
#define LED_RG1_OFFSET		0xf040
#define NUM_OFFSET		0xf050
#define SWITCH_OFFSET		0xf060
#define BTN_KEY_OFFSET		0xf070
#define BTN_STEP_OFFSET		0xf080
#define SW_INTER_OFFSET		0xf090 //switch interleave
#define TIMER_OFFSET		0xe000

#define COM1_BAUD_DDL	0x36 // 50M CPU clk
#define COM1		0x1fe00000
#define COM1_IRQ	2

#define LED_ADDR		(GPIO_BASE + LED_OFFSET)
#define LED_RG0_ADDR		(GPIO_BASE + LED_RG0_OFFSET)
#define LED_RG1_ADDR		(GPIO_BASE + LED_RG1_OFFSET)
#define NUM_ADDR		(GPIO_BASE + NUM_OFFSET)
#define SWITCH_ADDR		(GPIO_BASE + SWITCH_OFFSET)
#define BTN_KEY_ADDR		(GPIO_BASE + BTN_KEY_OFFSET)
#define BTN_STEP_ADDR		(GPIO_BASE + BTN_STEP_OFFSET)
#define SW_INTER_ADDR		(GPIO_BASE + SW_INTER_OFFSET) //switch interleave
#define TIMER_ADDR		(GPIO_BASE + TIMER_OFFSET)

#define MYSOC_TIMER_FREQ	(100 MHz)
#define LED_RG_GREEN		(0x1)
#define LED_RG_RED		(0x2)
#define LED_RG_GREEN_RED 	(LED_RG_GREEN | LED_RG_RED)

struct gpio *mysoc_init();

#endif
