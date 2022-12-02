#include <drivers/gpio.h>
#include <asm/mysoc.h>

// #pragma region led
// void led_turn_on_num(struct led *this, unsigned int num)
// {
// 	(this->status) &= ~(1 << (num % 16));
// 	*(volatile unsigned *)(this->addr) = (unsigned int)this->status;
// }

// void led_turn_off_num(struct led *this, unsigned int num)
// {
// 	(this->status) |= (1 << (num % 16));
// 	*(volatile unsigned *)(this->addr) = (unsigned int)(this->status);
// }

// void led_turn_on_mask(struct led *this, unsigned short mask)
// {
// 	(this->status) &= ~(mask);
// 	*(volatile unsigned *)(this->addr) = (unsigned int)this->status;
// }

// void led_turn_off_mask(struct led *this, unsigned short mask)
// {
// 	(this->status) |= (mask);
// 	*(volatile unsigned *)(this->addr) = (unsigned int)(this->status);
// }

// static struct led mysoc_led = {
// 	.addr		= (void*)LED_ADDR,
// 	.turn_on_num	= led_turn_on_num,
// 	.turn_off_num	= led_turn_off_num,
// 	.turn_on_mask	= led_turn_on_mask,
// 	.turn_off_mask	= led_turn_off_mask,
// };
// #pragma endregion led

// #pragma region led_rg
// void led_rg_turn_on(struct led_rg *this, unsigned int color)
// {
// 	*(volatile unsigned *)(this->addr) = color;
// }

// void led_rg_turn_off(struct led_rg *this)
// {
// 	*(volatile unsigned *)(this->addr) = 0;
// }

// static struct led_rg mysoc_led_rg0 = {
// 	.addr		= (void*)LED_RG0_ADDR,
// 	.turn_on	= led_rg_turn_on,
// 	.turn_off	= led_rg_turn_off,
// };
// static struct led_rg mysoc_led_rg1 = {
// 	.addr		= (void*)LED_RG1_ADDR,
// 	.turn_on	= led_rg_turn_on,
// 	.turn_off	= led_rg_turn_off,
// };
// #pragma endregion led_rg

// #pragma region num
// void num_set_one(struct num * this, unsigned int pos, unsigned char value)
// {
// 	unsigned mask = ~(0xf << (pos << 2));
// 	unsigned realvalue = value << (pos << 2);
// 	unsigned allvalue  = mask & this->cur_value | realvalue;
// 	this->set_all(this, allvalue);
// }

// void num_set_all(struct num * this, unsigned int value)
// {
// 	this->cur_value = value;
// 	*(volatile unsigned *)(this->addr) = value;
// }

// static struct num mysoc_num = {
// 	.addr		= (void*)NUM_ADDR,
// 	.cur_value	= 0,
// 	.set_one	= num_set_one,
// 	.set_all	= num_set_all,
// };
// #pragma endregion num

// #pragma region sw
// unsigned char sw_get_one(struct sw * this, unsigned int pos)
// {
// 	unsigned char allvalue = this->get_all(this);
// 	return (allvalue & (1 << pos)) != 0;
// }

// unsigned char sw_get_all(struct sw * this)
// {
// 	/** NOTE: switch on is zero, but we return 1 when switch on */
// 	return ~(*(volatile unsigned *)(this->addr));
// }

// static struct sw mysoc_sw = {
// 	.addr		= (void*)SWITCH_ADDR,
// 	.get_one	= sw_get_one,
// 	.get_all	= sw_get_all,
// };
// #pragma endregion sw

// #pragma region btn_key
// unsigned char btn_key_get_one(struct btn_key * this, unsigned int pos)
// {
// 	unsigned short allvalue = this->get_all(this);
// 	return (allvalue & (1 << pos)) != 0;
// }

// unsigned short btn_key_get_all(struct btn_key * this)
// {
// 	return *(volatile unsigned *)(this->addr);
// }

// static struct btn_key mysoc_btn_key = {
// 	.addr		= (void*)BTN_KEY_ADDR,
// 	.get_one	= btn_key_get_one,
// 	.get_all	= btn_key_get_all,
// };
// #pragma endregion btn_key

// #pragma region timer
// static inline unsigned int tick_to_sec(unsigned int tick)
// {
// 	return tick / MYSOC_TIMER_FREQ;
// }

// static inline unsigned int sec_to_tick(unsigned int sec)
// {
// 	return sec * MYSOC_TIMER_FREQ;
// }

// static inline void timer_set_count(struct timer *timer, unsigned int val)
// {
// 	*(volatile unsigned *)(timer->addr) = val;
// }

// static inline unsigned int timer_get_count(struct timer *timer)
// {
// 	return *(volatile unsigned *)(timer->addr);
// }

// static inline void timer_delay(struct timer *timer, unsigned int sec)
// {
// 	timer_set_count(timer, 0);
// 	while (tick_to_sec(timer_get_count(timer)) < sec) ;
// }

// static struct timer mysoc_timer = {
// 	.addr		= (void*)TIMER_ADDR,
// 	.freq		= MYSOC_TIMER_FREQ,
// 	.set_count	= timer_set_count,
// 	.get_count	= timer_get_count,
// 	.delay		= timer_delay,
// };
// #pragma endregion timer


// static struct gpio confreg = {
// 	.led	= &mysoc_led,
// 	.led_rg0= &mysoc_led_rg0,
// 	.led_rg1= &mysoc_led_rg1,
// 	.num	= &mysoc_num,
// 	.sw 	= &mysoc_sw,
// 	.btn_key= &mysoc_btn_key,
// 	.timer  = &mysoc_timer,
// };

// struct gpio *mysoc_init()
// {
// 	// turn off all LEDs
// 	confreg.led->turn_off_mask(confreg.led, 0xffff);
// 	confreg.led_rg0->turn_off(confreg.led_rg0);
// 	confreg.led_rg1->turn_off(confreg.led_rg1);

// 	return &confreg;
// }

void arch_gpio_init()
{
	confreg_init();
}
