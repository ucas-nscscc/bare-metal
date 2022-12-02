#include <drivers/gpio.h>
#include <time.h>
#include <myio.h>

void horse_race_lamp()
{
	unsigned int i = 0;
	unsigned short led_status = 0xfffe;
	unsigned int time;
	int led = gpio_open("led", "w");
	int btn_key = gpio_open("btn key", "r");
	unsigned int turn_off, turn_on;

	while(1) {
		gpio_write(led, led_status);
		time = get_sec();

		while (get_sec() - time < 1) ;
		
		i = (i + 1) % 16;
		led_status = (led_status << 1) | ((led_status & 0x8000) >> 15);
		if (gpio_read(btn_key) & 0x1)
			break;
	}

	gpio_close(led);
	gpio_close(btn_key);
}

void fib()
{
	int num = gpio_open("num", "w");
	int btn_key = gpio_open("btn key", "r");
	int sw = gpio_open("sw", "r");

	while (1) {
		while (((gpio_read(btn_key) >> 15) & 0x1) == 0){
			if ((gpio_read(btn_key) >> 1) & 0x1)
				return;
		}
		unsigned char end_i = ~gpio_read(sw);
		
		unsigned int f0 = 1, f1 = 1, f2, sum;
		if (end_i == 1) sum = 1;
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
	}
}
