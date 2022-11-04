#ifndef _SW_H
#define _SW_H

struct sw{
	void *addr;
	unsigned char (*get_one)(struct sw *, unsigned int);
	unsigned char (*get_all)(struct sw *);
};

#endif