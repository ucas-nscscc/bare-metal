#ifndef _ARCH_LOONGARCHREGS_H
#define _ARCH_LOONGARCHREGS_H

#define GPR_ZERO	0x0
#define GPR_RA		0x1
#define GPR_TP		0x2
#define GPR_SP		0x3
#define GPR_A0		0x4
#define GPR_A1		0x5
#define GPR_A2		0x6
#define GPR_A3		0x7
#define GPR_A4		0x8
#define GPR_A5		0x9
#define GPR_A6		0xa
#define GPR_A7		0xb
#define GPR_T0		0xc
#define GPR_T1		0xd
#define GPR_T2		0xe
#define GPR_T3		0xf
#define GPR_T4		0x10
#define GPR_T5		0x11
#define GPR_T6		0x12
#define GPR_T7		0x13
#define GPR_T8		0x14
#define GPR_R21		0x15
#define GPR_FP		0x16
#define GPR_S0		0x17
#define GPR_S1		0x18
#define GPR_S2		0x19
#define GPR_S3		0x1a
#define GPR_S4		0x1b
#define GPR_S5		0x1c
#define GPR_S6		0x1d
#define GPR_S7		0x1e
#define GPR_S8		0x1f

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
