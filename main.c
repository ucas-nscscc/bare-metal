#define UART_BASE	0x1fe001e0
#define UART_RX		0   /* In:  Receive buffer */
#define UART_TX		0   /* Out: Transmit buffer */
#define UART_LSR	5   /* In:  Line Status Register */
#define UART_LSR_TEMT	0x40 /* Transmitter empty */
#define UART_LSR_THRE	0x20 /* Transmit-hold-register empty */
#define UART_LSR_DR	0x01 /* Receiver data ready */

void uart_put_c(char c) {
	while (!(*((volatile char*)UART_BASE + UART_LSR) & (UART_LSR_THRE)));
	*((volatile char*)UART_BASE + UART_TX) = c;
}

void print_s(const char *c) {
	while (*c) {
		uart_put_c(*c);
		c ++;
	}
}

#define IO_SIMU_ADDR            0xbfafff00
#define UART_ADDR               0xbfafff10
#define SIMU_FLAG_ADDR          0xbfafff20
#define OPEN_TRACE_ADDR		0xbfafff30
#define NUM_MONITOR_ADDR	0xbfafff40
#define LED_ADDR		0xbfaff020
#define LED_RG0_ADDR            0xbfaff030
#define LED_RG1_ADDR            0xbfaff040
#define NUM_ADDR                0xbfaff050
#define SWITCH_ADDR             0xbfaff060
#define BTN_KEY_ADDR            0xbfaff070
#define BTN_STEP_ADDR           0xbfaff080
#define SW_INTER_ADDR           0xbfaff090 //switch interleave
#define TIMER_ADDR              0xbfafe000

#define SOC_LED		(*(volatile unsigned *)LED_ADDR     )
#define SOC_LED_RG0	(*(volatile unsigned *)LED_RG0_ADDR )
#define SOC_LED_RG1	(*(volatile unsigned *)LED_RG1_ADDR )
#define SOC_NUM		(*(volatile unsigned *)NUM_ADDR     )
#define SOC_SWITCH	(*(volatile unsigned *)SWITCH_ADDR  )
#define SOC_BTN_KEY	(*(volatile unsigned *)BTN_KEY_ADDR )
#define SOC_BTN_STEP	(*(volatile unsigned *)BTN_STEP_ADDR)
#define SOC_TIMER	(*(volatile unsigned *)TIMER_ADDR   )

int main()
{
	// print_s("\nHere is my first bare-metal machine program on LoongArch32!\n\n");
	SOC_LED = 0xaaaa;
	SOC_LED_RG0 = 0x2;
	SOC_LED_RG1 = 0x2;
	SOC_NUM = 0x55555555;

	return 0;
}
