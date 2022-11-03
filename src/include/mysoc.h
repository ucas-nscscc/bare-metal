#ifndef _MYSOC_H
#define _MYSOC_H

#include <soc.h>
#include <timer.h>

#define IO_SIMU_ADDR		0xbfafff00
#define UART_ADDR		0xbfafff10
#define SIMU_FLAG_ADDR		0xbfafff20
#define OPEN_TRACE_ADDR		0xbfafff30
#define NUM_MONITOR_ADDR	0xbfafff40
#define LED_ADDR		0xbfaff020
#define LED_RG0_ADDR		0xbfaff030
#define LED_RG1_ADDR		0xbfaff040
#define NUM_ADDR		0xbfaff050
#define SWITCH_ADDR		0xbfaff060
#define BTN_KEY_ADDR		0xbfaff070
#define BTN_STEP_ADDR		0xbfaff080
#define SW_INTER_ADDR		0xbfaff090 //switch interleave
#define TIMER_ADDR		0xbfafe000

#define SOC_LED		(*(volatile unsigned *)LED_ADDR     )
#define SOC_LED_RG0	(*(volatile unsigned *)LED_RG0_ADDR )
#define SOC_LED_RG1	(*(volatile unsigned *)LED_RG1_ADDR )
#define SOC_NUM		(*(volatile unsigned *)NUM_ADDR     )
#define SOC_SWITCH	(*(volatile unsigned *)SWITCH_ADDR  )
#define SOC_BTN_KEY	(*(volatile unsigned *)BTN_KEY_ADDR )
#define SOC_BTN_STEP	(*(volatile unsigned *)BTN_STEP_ADDR)
#define SOC_TIMER	(*(volatile unsigned *)TIMER_ADDR   )

#define MYSOC_TIMER_FREQ (100 MHz)

struct soc *mysoc_init();

#endif
