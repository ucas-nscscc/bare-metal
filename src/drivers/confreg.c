#include <drivers/gpio.h>
#include <asm/mysoc.h>
#include <drivers/uart.h>
#include <myio.h>
#include <string.h>

#define LED_OFFSET		0xf020
#define LED_RG0_OFFSET		0xf030
#define LED_RG1_OFFSET		0xf040
#define NUM_OFFSET		0xf050
#define SWITCH_OFFSET		0xf060
#define BTN_KEY_OFFSET		0xf070
#define BTN_STEP_OFFSET		0xf080
#define SW_INTER_OFFSET		0xf090 //switch interleave
#define TIMER_OFFSET		0xe000

#define LED_ADDR		(GPIO_BASE + LED_OFFSET)
#define LED_RG0_ADDR		(GPIO_BASE + LED_RG0_OFFSET)
#define LED_RG1_ADDR		(GPIO_BASE + LED_RG1_OFFSET)
#define NUM_ADDR		(GPIO_BASE + NUM_OFFSET)
#define SWITCH_ADDR		(GPIO_BASE + SWITCH_OFFSET)
#define BTN_KEY_ADDR		(GPIO_BASE + BTN_KEY_OFFSET)
#define BTN_STEP_ADDR		(GPIO_BASE + BTN_STEP_OFFSET)
#define SW_INTER_ADDR		(GPIO_BASE + SW_INTER_OFFSET) //switch interleave
#define TIMER_ADDR		(GPIO_BASE + TIMER_OFFSET)

static struct gpio_chip confreg = {
	.gpio_nr = 0,
	.bitmap = 0x0,
	.name = "confreg",
};

static void led_set_all(uint value)
{
	*(volatile unsigned *)(LED_ADDR) = value;
}

static uint confreg_init_gpio_devs()
{
	int desc_idx;
	uint gpio_nr = 0;

	desc_idx = alloc_gpio_desc(&confreg);
	strcpy(confreg.descs[desc_idx].name, "led");
	confreg.descs[desc_idx].flag = GPIO_WRITE;
	confreg.descs[desc_idx].opend = GPIO_CLOSED;
	confreg.descs[desc_idx].set_all = led_set_all;
	gpio_nr++;

	return gpio_nr;
}

void confreg_init()
{
	uint gpio_nr;

	uart_puts("enter confreg_init\n");
	gpio_nr = confreg_init_gpio_devs();
	print_hex(gpio_nr);
	register_gpio_chip(&confreg);
	uart_puts("exit confreg_init\n");
}
