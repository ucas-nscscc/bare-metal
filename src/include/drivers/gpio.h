#ifndef _GPIO_H
#define _GPIO_H

struct led {
	void *addr;
	unsigned short status;
	void (*turn_on_num)(struct led *, unsigned int);
	void (*turn_off_num)(struct led *, unsigned int);
	void (*turn_on_mask)(struct led *, unsigned short);
	void (*turn_off_mask)(struct led *, unsigned short);
};

struct led_rg {
	void *addr;
	void (*turn_on)(struct led_rg *, unsigned int color);
	void (*turn_off)(struct led_rg *);
};

struct num {
	void *addr;
	unsigned cur_value;
	void (*set_one)(struct num *, unsigned int, unsigned char);
	void (*set_all)(struct num *, unsigned int);
};

struct sw{
	void *addr;
	unsigned char (*get_one)(struct sw *, unsigned int);
	unsigned char (*get_all)(struct sw *);
};

struct timer {
	void *addr;
	unsigned int freq;
	void (*set_count)(struct timer *, unsigned int);
	unsigned int (*get_count)(struct timer *);
	void (*delay)(struct timer *, unsigned int);
	void (*mdelay)(struct timer *, unsigned int);
	void (*udelay)(struct timer *, unsigned int);
};

struct btn_key {
	void *addr;
	unsigned char (*get_one)(struct btn_key *, unsigned int);
	unsigned short (*get_all)(struct btn_key *);
};

struct gpio {
	struct led *led;
	struct led_rg *led_rg0;
	struct led_rg *led_rg1;
	struct num *num;
	struct sw *sw;
	struct btn_key *btn_key;
	struct timer *timer;
};

#endif
