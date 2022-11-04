#ifndef _SOC_H
#define _SOC_H

#include <led.h>
#include <num.h>
#include <sw.h>
#include <btn_key.h>
#include <timer.h>

struct soc {
        struct led *    led;
        struct led_rg * led_rg0;
        struct led_rg * led_rg1;
        struct num *    num;
        struct sw *     sw;
        struct btn_key *btn_key;
        struct timer *  timer;
};

#endif
