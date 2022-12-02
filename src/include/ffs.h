#ifndef _FFS_H
#define _FFS_H

#include <types.h>

static inline int ffs(uint val)
{
	int ret = 0;
	if (val == 0) {
		return -1;
	}
	while (val & 0x1 == 0) {
		val >>= 1;
		ret++;
	}
	return ret;
}

static inline int ffz(uint val)
{
	int ret = 0;
	while (val & 0x1 == 1) {
		val >>= 1;
		ret++;
	}
	return ret;
}

#endif
