#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t pair = NULL;

    pair = malloc(sizeof(struct s_pair_t));
    pair->fst = x;
    pair->snd = y;

    return pair;
}

elem pair_first(pair_t p){
    return p->fst;
}

elem pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    pair_t aux = NULL;

    aux = malloc(sizeof(struct s_pair_t));
    
    aux->fst = p->snd;
    aux->snd = p->fst;

    return aux;
}

pair_t pair_destroy(pair_t p){
    free(p);

    return p;
}
