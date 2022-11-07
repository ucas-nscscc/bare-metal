#ifndef _LED_H
#define _LED_H

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

#endif
