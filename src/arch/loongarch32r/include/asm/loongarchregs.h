#ifndef _LOONGARCHREGS_H
#define _LOONGARCHREGS_H

#define CSR_CRMD			0x0
#define CSR_PRMD			0x1
#define CSR_CRMD_IE_SHIFT		2
#define CSR_CRMD_IE			(0x1 << CSR_CRMD_IE_SHIFT)
#define CSR_ECFG			0x4
#define CSR_ESTAT			0x5
#define CSR_ERA				0x6
#define CSR_EENTRY			0xc

#define csr_read(reg)			\
({					\
	unsigned int __val;		\
	asm volatile (			\
		"csrrd %0, %1 \n\t"	\
		: "=r" (__val)		\
		: "I" (reg)		\
		: "memory");		\
	__val;				\
})

#define csr_write(val, reg)		\
({					\
	unsigned int __val = val;	\
	__asm__ volatile (		\
		"csrwr %0, %1 \n\t"	\
		: "=r" (__val)		\
		: "I" (reg)		\
		: "memory");		\
})

#define gpr_read(reg) 					\
({							\
	register unsigned int __val __asm__("$r"#reg);	\
	__val;						\
})

static inline unsigned int
inw(unsigned int port) {
	unsigned int data = *((volatile unsigned int *) port);
	return data;
}

static inline void
outw(unsigned int port, unsigned int data) {
	*((volatile unsigned int *) port) = data;
}

#endif
