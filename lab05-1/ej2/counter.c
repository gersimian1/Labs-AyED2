#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(struct _counter)); 
    c->count = 0;

    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    bool c_is_init = false;

    if (c->count == 0)
    {
        c_is_init = true;
    }
    
    return c_is_init;
}

void counter_dec(counter c) {
    c->count--;
}

counter counter_copy(counter c) {
    counter ctr_cpy;
    ctr_cpy = c;

    return ctr_cpy;
}

void counter_destroy(counter c) {
    free(c);
}
