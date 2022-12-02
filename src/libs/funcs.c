#include <drivers/gpio.h>
#include <time.h>
#include <myio.h>
#include <sched.h>

int horse_race_lamp(void *arg)
{
	unsigned int i = 0;
	unsigned short led_status = 0xfffe;
	unsigned int time;
	int led = gpio_open("led", "w");
	unsigned int turn_off, turn_on;

	while(1) {
		gpio_write(led, led_status);
		time = get_sec();

		while (get_sec() - time < 1)
			yield();
		
		i = (i + 1) % 16;
		led_status = (led_status << 1) | ((led_status & 0x8000) >> 15);
		yield();
	}

	gpio_close(led);
	return 0;
}

int fib(void *arg)
{
	int num = gpio_open("num", "w");
	int btn_key = gpio_open("btn key", "r");
	int sw = gpio_open("sw", "r");

	while (1) {
		while (((gpio_read(btn_key) >> 15) & 0x1) == 0)
			yield();
		unsigned char end_i = ~gpio_read(sw);
		
		unsigned int f0 = 1, f1 = 1, f2, sum;
		if (end_i == 0) sum = 0;
		else if (end_i == 1) sum = 1;
		else if (end_i == 2) sum = 2;
		else {
			sum = f0 + f1;
			for (int i = 2; i < end_i; i++) {
				f2 = f0 + f1;
				f0 = f1;
				f1 = f2;
				sum += f2;
			}
		}
		gpio_write(num, sum);
		yield();
	}

	gpio_close(num);
	gpio_close(btn_key);
	gpio_close(sw);
	return 0;
}
