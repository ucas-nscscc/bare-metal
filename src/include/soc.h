#ifndef _SOC_H
#define _SOC_H

#include <led.h>
#include <timer.h>

struct soc {
        struct led *    led;
        struct led_rg * led_rg0;
        struct led_rg * led_rg1;
        struct num *    num;
        struct sw *     sw;
        struct btnkey * btnkey;
        struct timer *  timer;
};

#endif
