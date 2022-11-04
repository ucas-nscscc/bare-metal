#include <soc.h>
#include <mysoc.h>

void horse_race_lamp(struct soc *soc)
{
	unsigned int i = 0;
	struct led *led = soc->led;
	struct led_rg * led_rg0 = soc->led_rg0;
	struct led_rg * led_rg1 = soc->led_rg1;
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
	}
}

int main()
{
	struct soc *mysoc = mysoc_init();

	horse_race_lamp(mysoc);

	return 0;
}
