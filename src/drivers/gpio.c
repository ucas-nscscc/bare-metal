#include <drivers/gpio.h>
#include <ffs.h>
#include <asm/mysoc.h>
#include <myio.h>
#include <string.h>
#include <drivers/uart.h>

static struct gpio_chip *gpio_chips[16];
static int gpio_chips_ptr = 0;
static uint gpio_bitmap = 0;

void gpio_init()
{
	arch_gpio_init();
}

void register_gpio_chip(struct gpio_chip *chip)
{
	gpio_chips[gpio_chips_ptr] = chip;
	gpio_chips_ptr++;
}

int alloc_gpio_desc(struct gpio_chip *chip)
{
	int sub_gpio = 0, gpio;

	sub_gpio = ffz(chip->bitmap);
	if (sub_gpio >= MAX_GPIO_DESCS) {
		return -1;
	}
	gpio = ffz(gpio_bitmap);
	if (gpio >= sizeof(typeof(gpio_bitmap)) * 8) {
		return -1;
	}

	gpio_bitmap |= (0x1 << gpio);
	chip->bitmap |= (0x1 << sub_gpio);
	chip->gpio_nr++;
	chip->descs[sub_gpio].gpio = gpio;
	return sub_gpio;
}

void free_gpio_desc(struct gpio_chip *chip, int sub_gpio)
{
	uint gpio;
	if (sub_gpio <= 0 || sub_gpio > MAX_GPIO_DESCS)
		return;
	if ((chip->bitmap >> sub_gpio) & 0x1 == 0)
		return;
	gpio = chip->descs[sub_gpio].gpio;
	gpio_bitmap &= ~(0x1 << gpio);
	chip->bitmap &= ~(0x1 << sub_gpio);
	chip->gpio_nr--;
}

static struct gpio_desc *gpio_to_desc(gdev_num_t gpio)
{
	gpio_desc_bitmap_t bitmap;
	struct gpio_chip *chip;
	int i, j;
	for (i = 0; i < gpio_chips_ptr; i++) {
		chip = gpio_chips[i];
		bitmap = chip->bitmap;
		for (j = 0; j < MAX_GPIO_DESCS; bitmap >>= 1, j++) {
			if (bitmap & 0x1 == 0)
				continue;
			if (gpio == chip->descs[j].gpio)
				return &chip->descs[j];
		}
	}
	return NULL;
}

int gpio_open(const char *name, const char *perm)
{
	uint flag = 0x0;
	gpio_desc_bitmap_t bitmap;
	struct gpio_chip *chip;
	struct gpio_desc *gdesc;
	struct dev_desc *ddesc;
	int i, j;

	while (*perm) {
		switch (*perm)
		{
		case 'r':
			flag |= DEV_READ;
			break;
		case 'w':
			flag |= DEV_WRITE;
			break;
		default:
			break;
		}
		perm++;
	}

	for (i = 0; i < gpio_chips_ptr; i++) {
		chip = gpio_chips[i];
		bitmap = chip->bitmap;
		for (j = 0; j < MAX_GPIO_DESCS; bitmap >>= 1, j++) {
			if (bitmap & 0x1 == 0)
				continue;
			gdesc = &chip->descs[j];
			ddesc = &gdesc->dev_desc;
			if (strcmp(name, ddesc->name) == 0) {
				if (flag == ddesc->flag) {
					if (ddesc->opend == GPIO_CLOSED) {
						ddesc->opend = GPIO_OPENED;
						return gdesc->gpio;
					}
					printk("gpio %d is already opened!\n", gdesc->gpio);
					goto open_failed;
				}
				printk("gpio %d permission denied!\n", gdesc->gpio);
				goto open_failed;
			}
		}
	}
open_failed:
	return -1;
}

void gpio_close(int gpio)
{
	struct gpio_desc *gdesc = gpio_to_desc(gpio);
	if (gdesc == NULL) {
		uart_puts("no such gpio device!\n");
		return;
	}
	gdesc->dev_desc.opend = GPIO_CLOSED;
}

void gpio_write(gdev_num_t gpio, uint value)
{
	struct gpio_desc *gdesc = gpio_to_desc(gpio);
	if (gdesc == NULL) {
		uart_puts("no such gpio device!\n");
		return;
	}

	gdesc->dev_desc.write(value);
}

uint gpio_read(gdev_num_t gpio)
{
	struct gpio_desc *gdesc = gpio_to_desc(gpio);
	if (gdesc == NULL) {
		uart_puts("no such gpio device!\n");
		return 0;
	}

	return gdesc->dev_desc.read();
}
