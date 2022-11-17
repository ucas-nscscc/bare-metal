#include <mysoc.h>
#include <traps.h>
#include <stdio.h>

#define COM_RX          0x1000  // In:  Receive buffer (DLAB=0)
#define COM_TX          0x1000  // Out: Transmit buffer (DLAB=0)
#define COM_DLL         0x1000  // Out: Divisor Latch Low (DLAB=1)
#define COM_DLM         0x1004  // Out: Divisor Latch High (DLAB=1)
#define COM_IER         0x1004  // Out: Interrupt Enable Register
#define COM_IER_RDI     0x01    // Enable receiver data interrupt
#define COM_IIR         0x1008  // In:  Interrupt ID Register
#define COM_FCR         0x1008  // Out: FIFO Control Register
#define COM_FCR_RST     0x06    // FCR: disable FIFO and reset
#define COM_LCR         0x100C  // Out: Line Control Register
#define COM_LCR_DLAB    0x80    // Divisor latch access bit
#define COM_LCR_WLEN8   0x03    // Wordlength: 8 bits
#define COM_MCR         0x1010  // Out: Modem Control Register
#define COM_MCR_RTS     0x02    // RTS complement
#define COM_MCR_DTR     0x01    // DTR complement
#define COM_MCR_OUT2    0x08    // Out2 complement
#define COM_LSR         0x1014  // In:  Line Status Register
#define COM_LSR_DATA    0x01    // Data available
#define COM_LSR_TXRDY   0x20    // Transmit buffer avail
#define COM_LSR_TSRE    0x40    // Transmitter off

static unsigned uart_exists = 0;

void uart_init(void)
{
	volatile unsigned char *uart = (unsigned char*)COM1;
	unsigned int reg;
	if(uart_exists)
		return ;
	uart_exists = 1;

	// Set speed; requires DLAB latch
	reg = inw(COM1 + COM_LCR);
	outw(COM1 + COM_LCR, COM_LCR_DLAB | reg);
	outw(COM1 + COM_DLL, 0xff);
	outw(COM1 + COM_DLM, 0);
	outw(COM1 + COM_DLL, (unsigned char) (COM1_BAUD_DDL));
	outw(COM1 + COM_LCR, reg);

	// 8 data bits, 1 stop bit, parity off; turn off DLAB latch
	outw(COM1 + COM_LCR, COM_LCR_WLEN8);

	// Turn off the FIFO
	outw(COM1 + COM_FCR, COM_FCR_RST);
	outw(COM1 + COM_FCR, COM_FCR_RST);

	// Enable rcv interrupts
	reg = inw(COM1 + COM_IER);
	outw(COM1 + COM_IER, COM_IER_RDI | reg);

	pic_enable(COM1_IRQ);
}

void uart_putc_sub(int c)
{
    while (!(inw(COM1 + COM_LSR) & COM_LSR_TXRDY)) {
    }
    outw(COM1 + COM_TX, c);
}

/* uart_putc - print character to uart port */
void uart_putc(int c)
{
    if (c == '\r' || c == '\n') {
        uart_putc_sub('\r');
        uart_putc_sub('\n');
    } else if (c == '\b') {
        uart_putc_sub('\b');
        uart_putc_sub(' ');
        uart_putc_sub('\b');
    } else {
        uart_putc_sub(c);
    }
}

void uart_puts(char *str)
{
	char *p = str;
	while (*p) {
		uart_putc(*p);
		p++;
	}
}

void uart_interrupt()
{
	int c;
	while (inw(COM1 + COM_LSR) & COM_LSR_DATA) {
		c = inw(COM1 + COM_RX);
		uart_putc(c);
	}
}
