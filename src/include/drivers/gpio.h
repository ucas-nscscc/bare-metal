#ifndef _GPIO_H
#define _GPIO_H

#include <types.h>

#define GPIO_READ	0x1
#define GPIO_WRITE	0x2

#define GPIO_CLOSED	0x0
#define GPIO_OPENED	0x1

typedef uint gpio_desc_bitmap_t;
typedef uint gdev_num_t;

struct gpio_desc {
	char	name[32];
	int	flag;
	uint	gpio;
	uint	opend;
	void	(*set_all)(uint value);
	uint	(*get_all)();
};

#define MAX_GPIO_DESCS 16

struct gpio_chip {
	struct gpio_desc	descs[MAX_GPIO_DESCS];
	gpio_desc_bitmap_t	bitmap;
	uint			gpio_nr;
	char			name[32];
};

void gpio_init();

int gpio_open(const char *name, const char *prem);
void gpio_close(int gpio);
void gpio_write(gdev_num_t gpio, uint value);
uint gpio_read(gdev_num_t gpio);

void register_gpio_chip(struct gpio_chip *chip);
int alloc_gpio_desc(struct gpio_chip *chip);
void free_gpio_desc(struct gpio_chip *chip, int sub_gpio);

#endif
