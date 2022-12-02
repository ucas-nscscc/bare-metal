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

#define LED_ADDR		(GPIO_BASE + LED_OFFSET)
#define LED_RG0_ADDR		(GPIO_BASE + LED_RG0_OFFSET)
#define LED_RG1_ADDR		(GPIO_BASE + LED_RG1_OFFSET)
#define NUM_ADDR		(GPIO_BASE + NUM_OFFSET)
#define SWITCH_ADDR		(GPIO_BASE + SWITCH_OFFSET)
#define BTN_KEY_ADDR		(GPIO_BASE + BTN_KEY_OFFSET)
#define BTN_STEP_ADDR		(GPIO_BASE + BTN_STEP_OFFSET)
#define SW_INTER_ADDR		(GPIO_BASE + SW_INTER_OFFSET) //switch interleave

static struct gpio_chip confreg = {
	.gpio_nr = 0,
	.bitmap = 0x0,
	.name = "confreg",
};

static void led_set_all(uint value)
{
	*(volatile unsigned *)(LED_ADDR) = value;
}

static uint btn_key_get_all()
{
	return *(volatile unsigned *)(BTN_KEY_ADDR);
}

static void num_set_all(uint value)
{
	*(volatile unsigned *)(NUM_ADDR) = value;
}

static uint sw_get_all()
{
	return *(volatile unsigned *)(SWITCH_ADDR);
}

static void confreg_init_gpio_devs()
{
	int desc_idx;
	struct dev_desc *dev_desc;

#define init_gpio_dev(name, flag, write, read)			\
{								\
	desc_idx = alloc_gpio_desc(&confreg);			\
	if (desc_idx == -1) {					\
		printk("alloc gpio desc failed!\n");		\
		return;						\
	}							\
	dev_desc = &confreg.descs[desc_idx].dev_desc;		\
	init_dev_desc(dev_desc, name, flag, write, read);	\
}

	init_gpio_dev("led", DEV_WRITE, led_set_all, NULL);
	init_gpio_dev("btn key", DEV_READ, NULL, btn_key_get_all);
	init_gpio_dev("num", DEV_WRITE, num_set_all, NULL);
	init_gpio_dev("sw", DEV_READ, NULL, sw_get_all);
}

void confreg_init()
{
	confreg_init_gpio_devs();
	register_gpio_chip(&confreg);
}
