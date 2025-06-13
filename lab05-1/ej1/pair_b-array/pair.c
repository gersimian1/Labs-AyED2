#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t pair;
    pair.values[0] = x;
    pair.values[1] = y;

    return pair;
}

int pair_first(pair_t p){
    return p.values[0];
}

int pair_second(pair_t p){
    return p.values[1];
}

pair_t pair_swapped(pair_t p){
    pair_t aux = p;

    p.values[0] = p.values[1];
    p.values[1] = aux.values[0];

    return p;
}

pair_t pair_destroy(pair_t p){
    return p;
}