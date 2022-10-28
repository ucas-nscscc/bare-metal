#ifndef _SOC_H
#define _SOC_H

#include <led.h>
#include <timer.h>

struct soc {
        struct led *led;
        struct timer *timer;
};

#endif
