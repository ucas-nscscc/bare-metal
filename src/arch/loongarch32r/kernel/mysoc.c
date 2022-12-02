#include <drivers/gpio.h>
#include <asm/mysoc.h>

void arch_gpio_init()
{
	confreg_init();
}

void arch_time_init()
{
	constant_timer_init();
}

void arch_mm_init(uint *pmem_base, uint *pmem_size)
{
	*pmem_base = PMEM_BASE;
	*pmem_size = PMEM_SIZE;
}
