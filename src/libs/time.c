#include <mysoc.h>
#include <time.h>

unsigned long _get_count()
{
    unsigned long _contval;
    _contval = SOC_TIMER;
    return  _contval;
}

unsigned long get_count()
{
    return  _get_count();
}

unsigned long get_clock()
{
    unsigned long n=0;
    n=_get_count();
    return n;
}

unsigned long get_ns(void)
{
    unsigned long n=0;
    n = _get_count();
    n=n*(NSEC_PER_USEC/CPU_COUNT_PER_US);
    return n;
}


unsigned long get_us(void)
{
    unsigned long n=0;
    n = _get_count();
    n=n/CPU_COUNT_PER_US;
    return n;
}