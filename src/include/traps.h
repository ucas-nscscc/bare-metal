#ifndef _TRAPS_H
#define _TRAPS_H

#include <mysoc.h>
#include <loongarchregs.h>

#define UART_IRQ (0x1 << COM1_IRQ)

void pic_enable(unsigned int irq);
void trap_init(void);

#define irq_enable()					\
{							\
	unsigned int __val = csr_read(CSR_CRMD);	\
	__val |= CSR_CRMD_IE;				\
	csr_write(__val, CSR_CRMD);			\
}

#endif
