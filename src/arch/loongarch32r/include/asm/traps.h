#ifndef _ARCH_TRAPS_H
#define _ARCH_TRAPS_H

#include <asm/mysoc.h>
#include <asm/loongarchregs.h>

#define UART_IRQ (0x1 << COM1_IRQ)

#define irq_enable()					\
{							\
	unsigned int __val = csr_read(CSR_CRMD);	\
	__val |= CSR_CRMD_IE;				\
	csr_write(__val, CSR_CRMD);			\
}

#define irq_disable()					\
{							\
	unsigned int __val = csr_read(CSR_CRMD);	\
	__val &= ~CSR_CRMD_IE;				\
	csr_write(__val, CSR_CRMD);			\
}

#endif
