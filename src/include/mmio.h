#ifndef _MMIO_H
#define _MMIO_H

#include <types.h>

static inline unsigned int inw(ulong port) {
	unsigned int data = *((volatile uint *) port);
	return data;
}

static inline void outw(ulong port, uint data) {
	*((volatile uint *) port) = data;
}

#endif
