#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100
//arreglo circular
struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty(){
    list l = NULL;
    l = malloc(sizeof(struct _list));
    l->start = 0;
    l->size = 0;

    return l;
}

list addl(elem e, list l){

    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e; 
    l->size++;
    
    return l;
}

bool is_empty(list l){
    return l->size == 0;
}

elem head(list l){
    assert(l->size != 0);
    
    return l->a[l->start];
}

list tail(list l){
    assert(l->size != 0);

    l->start = l->start + 1;
    l->size--;

    return l;
}

list addr(list l, elem e){

    int end = (l->start + l->size) % MAX_LENGTH;
    l->a[end] = e;
    l->size++;
    return l;
}

int length(list l){
    return l->size;
}

list concat(list l, list l0){

    for (int i = 0; i < l0->size; i++)
    {
        elem e = l0->a[(l0->start + i) % MAX_LENGTH];
        l->a[(l->start + l->size) % MAX_LENGTH] = e;
        l->size++;
    }
    
    return l;
}

elem index(list l, int n){
    assert(n >= 0 && n < l->size);

    return l->a[(l->start + n) % MAX_LENGTH];
}

list take(list l, int n){
    if (n > l->size) {
        n = l->size; 
    }

    list aux = NULL;
    aux = malloc(sizeof(struct _list));
    aux->size = n;
    aux->start = 0;

    for (int i = 0; i < n; i++)
    {
        aux->a[i] = l->a[((l->start + i) % MAX_LENGTH)];
    }

    free(l);

    return aux;
}

list drop(list l, int n){
    l->start = (l->start + n) % MAX_LENGTH;
    l->size = l->size - n;

    return l;
}

list copy_list(list l){
    list cpy = NULL;
    cpy = malloc(sizeof(struct _list));
    cpy->start = 0;
    cpy->size = l->size;

    for (int i = 0; i < cpy->size; i++)
    {
        elem e = l->a[((l->start + i) % MAX_LENGTH)];
        cpy->a[i] = e;
    }
    
    return cpy;
}

void destroy_list(list l){
    free(l);
}