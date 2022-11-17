#include <loongarchregs.h>
#include <stdio.h>
#include <traps.h>
#include <uart.h>

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

	// uart_puts("handle interrupt");

	// uart_puts("ecfg: ");
	// print_hex(ecfg);
	// uart_puts("estat: ");
	// print_hex(estat);
	// uart_puts("era: ");
	// print_hex(era);


	switch(estat & ecfg)
	{
	case UART_IRQ:
		uart_interrupt();
		break;
	default:
		while(1) ;
		break;
	}

	uart_puts("era: ");
	print_hex(era);
	csr_write(era, CSR_ERA);
	csr_write(prmd, CSR_PRMD);
}

void trap_init()
{
	csr_write((unsigned int)trap_entry, CSR_EENTRY);
	irq_enable();
}
