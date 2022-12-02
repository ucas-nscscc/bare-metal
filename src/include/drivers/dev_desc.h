#ifndef _DEV_DESC_H
#define _DEV_DESC_H

#include <types.h>
#include <string.h>

#define DEV_READ	0x1
#define DEV_WRITE	0x2

#define DEV_CLOSED	0x0
#define DEV_OPENED	0x1

typedef void (*dev_write_t)(uint);
typedef uint (*dev_read_t)(void);

struct dev_desc {
	char		name[32];
	int		flag;
	uint		opend;
	dev_write_t	write;
	dev_read_t	read;
};

#define init_dev_desc(desc, dev_name, dev_flag, dev_write, dev_read)	\
{									\
	strcpy(desc->name, dev_name);					\
	desc->flag = dev_flag;						\
	desc->opend = DEV_CLOSED;					\
	desc->write = dev_write;					\
	desc->read = dev_read;						\
}

#endif
