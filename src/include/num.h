#ifndef _NUM_H
#define _NUM_H

struct num {
        void *addr;
        unsigned cur_value;
        void (*set_one)(struct num *, unsigned int, unsigned char);
        void (*set_all)(struct num *, unsigned int);
};

#endif