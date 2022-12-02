#ifndef _DEV_DESC_H
#define _DEV_DESC_H

#include <types.h>

#define DEV_READ	0x1
#define DEV_WRITE	0x2

struct dev_desc {
	char	name[32];
	int	flag;
	uint	opend;
	void	(*write)(uint value);
	uint	(*read)();
};

#endif
