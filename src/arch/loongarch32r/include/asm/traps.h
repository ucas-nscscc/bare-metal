#ifndef _TRAPS_H
#define _TRAPS_H

#include <asm/mysoc.h>
#include <asm/loongarchregs.h>

#define UART_IRQ (0x1 << COM1_IRQ)

#define irq_enable()					\
{							\
	unsigned int __val = csr_read(CSR_CRMD);	\
	__val |= CSR_CRMD_IE;				\
	csr_write(__val, CSR_CRMD);			\
}

#endif
