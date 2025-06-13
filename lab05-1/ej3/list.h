#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct Node
{
    int elem;
    struct Node* next;
} Node;

typedef Node *List;

List empty();

List addl(int e, List l);

bool is_empty(List l);

int head(List l);

List tail(List l);

List addr(List l, int e);

int length(List l);

List concat(List l, List l0);

int index(List l, int n);

List take(List l, int n);

List drop(List l, int n);

List copy_list(List l);

void destroy_list(List l);

#endif