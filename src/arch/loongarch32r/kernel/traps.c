#include <asm/loongarchregs.h>
#include <asm/traps.h>
#include <myio.h>
#include <drivers/uart.h>

extern void trap_entry(void);

void pic_enable(unsigned int irq)
{
	unsigned int old = csr_read(CSR_ECFG);
	old = old | (0x1 << irq);
	csr_write(old, CSR_ECFG);
}

void trap_handler()
{
	unsigned int era = csr_read(CSR_ERA);
	unsigned int prmd = csr_read(CSR_PRMD);
	unsigned int estat = csr_read(CSR_ESTAT);
	unsigned int ecfg = csr_read(CSR_ECFG);

	switch(estat & ecfg)
	{
	case UART_IRQ:
		uart_interrupt();
		break;
	default:
		while(1) ;
		break;
	}

	csr_write(era, CSR_ERA);
	csr_write(prmd, CSR_PRMD);
}

void trap_init()
{
	csr_write((unsigned int)trap_entry, CSR_EENTRY);
}
