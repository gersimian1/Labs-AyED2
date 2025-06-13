#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100
//CAMBIAR WHILE POR FOR
struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(){
    list l = NULL;
    l = malloc(sizeof(struct _list));
    l->size = 0;

    return l;
}

list addl(elem e, list l){

    if (l->size == 0)
    {
        l->elems[0] = e;
        l->size = 1;
    }
    else
    {
        for (int i = l->size - 1; i >= 0; i--)
        {
            l->elems[i + 1] = l->elems[i];
        }
        l->elems[0] = e;
        l->size++;

    }
    
    return l;
    
}

bool is_empty(list l){
    return l->size == 0;
}

elem head(list l){
    assert(l->size != 0);
    
    return l->elems[0];
}

list tail(list l){
    assert(l->size != 0);

    for (int i = 0; i < l->size - 1; i++)
    {
        l->elems[i] = l->elems[i + 1];
    }

    l->size--;

    return l;
}

list addr(list l, elem e){

    if (l->size == 0)
    {
        l->elems[0] = e;
        l->size = 1;
    }
    else
    {
        l->elems[l->size] = e;
        l->size++;
    }

    return l;
}

int length(list l){
    return l->size;
}

list concat(list l, list l0){
    int i = 0, j = 0;

    l->size += l0->size;

    while (i < l->size)
    {
        i++;
    }
    
    while (j < l0->size)
    {
        l->elems[i] = l0->elems[j];
        j++;
    }
    
    return l;
}

elem index(list l, int n){
    assert(n >= 0 && n < l->size);

    return l->elems[n];
}

list take(list l, int n){
    int i = 0;
    if (n > l->size) n = l->size;
    list aux = NULL;

    aux = malloc(sizeof(struct _list));
    aux->size = n;

    while (i < n)
    {
        aux->elems[i] = l->elems[i];
        i++;
    }

    free(l);

    return aux;
}

list drop(list l, int n){
    int i = 0;

    list aux = NULL;
    aux = malloc(sizeof(struct _list));
    aux->size = l->size - n;

    while (i < aux->size)
    {
        aux->elems[i] = l->elems[n];
        n++;
        i++;
    }
    
    free(l);

    return aux;
}

list copy_list(list l){
    int i = 0;

    list cpy = NULL;
    cpy = malloc(sizeof(struct _list));
    cpy->size = l->size;

    while (i < l->size)
    {
        cpy->elems[i] = l->elems[i];
    }
    
    return cpy;
}

void destroy_list(list l){
    free(l);
}