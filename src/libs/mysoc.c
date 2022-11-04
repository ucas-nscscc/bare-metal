#include <led.h>
#include <timer.h>
#include <mysoc.h>
#include <soc.h>

#pragma region led
void led_turn_on_num(struct led *this, unsigned int num)
{
	(this->status) &= ~(1 << (num % 16));
	*(volatile unsigned *)(this->addr) = (unsigned int)this->status;
}

void led_turn_off_num(struct led *this, unsigned int num)
{
	(this->status) |= (1 << (num % 16));
	*(volatile unsigned *)(this->addr) = (unsigned int)(this->status);
}

void led_turn_on_mask(struct led *this, unsigned short mask)
{
	(this->status) &= ~(mask);
	*(volatile unsigned *)(this->addr) = (unsigned int)this->status;
}

void led_turn_off_mask(struct led *this, unsigned short mask)
{
	(this->status) |= (mask);
	*(volatile unsigned *)(this->addr) = (unsigned int)(this->status);
}

static struct led mysoc_led = {
	.addr		= (void*)LED_ADDR,
	.turn_on_num	= led_turn_on_num,
	.turn_off_num	= led_turn_off_num,
	.turn_on_mask	= led_turn_on_mask,
	.turn_off_mask	= led_turn_off_mask,
};
#pragma endregion led

#pragma region led_rg
void led_rg_turn_on(struct led_rg *this, unsigned int color)
{
	*(volatile unsigned *)(this->addr) = color;
}

void led_rg_turn_off(struct led_rg *this)
{
	*(volatile unsigned *)(this->addr) = 0;
}

static struct led_rg mysoc_led_rg0 = {
	.addr		= (void*)LED_RG0_ADDR,
	.turn_on	= led_rg_turn_on,
	.turn_off	= led_rg_turn_off,
};
static struct led_rg mysoc_led_rg1 = {
	.addr		= (void*)LED_RG1_ADDR,
	.turn_on	= led_rg_turn_on,
	.turn_off	= led_rg_turn_off,
};
#pragma endregion led_rg

#pragma region timer
static inline unsigned int tick_to_sec(unsigned int tick)
{
	return tick / MYSOC_TIMER_FREQ;
}

static inline unsigned int sec_to_tick(unsigned int sec)
{
	return sec * MYSOC_TIMER_FREQ;
}

static inline void timer_set_count(struct timer *timer, unsigned int val)
{
	*(volatile unsigned *)(timer->addr) = val;
}

static inline unsigned int timer_get_count(struct timer *timer)
{
	return *(volatile unsigned *)(timer->addr);
}

static inline void timer_delay(struct timer *timer, unsigned int sec)
{
	timer_set_count(timer, 0);
	while (tick_to_sec(timer_get_count(timer)) < sec) ;
}

static struct timer mysoc_timer = {
	.addr		= (void*)TIMER_ADDR,
	.freq		= MYSOC_TIMER_FREQ,
	.set_count	= timer_set_count,
	.get_count	= timer_get_count,
	.delay		= timer_delay,
};
#pragma endregion timer


static struct soc mysoc = {
	.led	= &mysoc_led,
	.led_rg0= &mysoc_led_rg0,
	.led_rg1= &mysoc_led_rg1,
	.timer  = &mysoc_timer,
};

struct soc *mysoc_init()
{
	// turn off all LEDs
	mysoc.led->turn_off_mask(mysoc.led, 0xffff);
	mysoc.led_rg0->turn_off(mysoc.led_rg0);
	mysoc.led_rg1->turn_off(mysoc.led_rg1);

	return &mysoc;
}
