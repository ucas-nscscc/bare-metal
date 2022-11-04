#ifndef _BTN_KEY_H
#define _BTN_KEY_H

struct btn_key {
	void *addr;
	unsigned char (*get_one)(struct btn_key *, unsigned int);
	unsigned short (*get_all)(struct btn_key *);
};

#endif
