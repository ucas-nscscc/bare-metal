#include <funcs.h>

void horse_race_lamp(struct soc *soc)
{
	unsigned int i = 0;
	struct led *led = soc->led;
	struct led_rg * led_rg0 = soc->led_rg0;
	struct led_rg * led_rg1 = soc->led_rg1;
	struct btn_key * btn_key = soc->btn_key;
	struct timer *timer = soc->timer;
	unsigned int turn_off, turn_on;

	while(1) {
		turn_off = (i + 16 - 1) % 16;
		turn_on = i % 16;

		led->turn_off_num(led, turn_off);
		led->turn_on_num(led, turn_on);

		led_rg0->turn_on(led_rg0, i % 4);
		led_rg1->turn_on(led_rg1, (i + 1) % 4);
		
		timer->delay(timer, 1);
		
		i = (i + 1) % 16;
		if (btn_key->get_one(btn_key, 0)) return;
	}
}

void fib(struct soc * soc)
{
	struct num * num = soc->num;
	struct sw * sw = soc->sw;
	struct btn_key * btn_key = soc->btn_key;

	while (1) {
		while (!btn_key->get_one(btn_key, 15)){
			if (btn_key->get_one(btn_key, 1)) return;
		}
		int end_i = sw->get_all(sw);
		
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
		num->set_all(num, sum);
	}
}
