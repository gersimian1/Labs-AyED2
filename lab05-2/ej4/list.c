#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct _list
{
    elem el;
    struct Node* next;
} Node;

list empty(){
    return NULL;
}

list addl(elem e, list l){
    Node* p = malloc(sizeof(Node));

    if (p == NULL) return l;

    p->el = e;
    p->next = l;
    
    return p;
}

bool is_empty(list l){
    return l == NULL;
}

elem head(list l){
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }

    return l->el;
}

list tail(list l){
    if (l == NULL) return NULL;
    Node* aux = l;

    l = l->next;
    free(aux);

    return l;
}

list addr(list l, elem e){
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) return l;
    temp->el = e;
    temp->next = NULL;

    if (l == NULL) {
        return temp;
    }

    Node* ptr = l;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    
    ptr->next = temp;

    return l;
}

int length(list l){
    int count = 0;
    Node* ptr = l;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    return count;
}

list concat(list l, list l0){
    if (l == NULL) return l0;
    Node* aux = l;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    aux->next = l0;

    return l;
}

int index(list l, int n){
    int count = 0;
    Node* ptr = l;

    while (ptr != NULL && count < n)
    {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        return -1;
    }

    return ptr->el;
}

list take(list l, int n){
    if (n <= 0 || l == NULL) {
        destroy_list(l);
        return NULL;
    }
    Node* curr = l;
    int i = 1;

    while (curr->next != NULL && i < n)
    {
        curr = curr->next;
        i++;
    }

    Node* to_free = curr->next;
    curr->next = NULL;

    while (to_free != NULL)
    {
        Node* temp = to_free;
        to_free = to_free->next;
        free(temp);
    }
    
    return l;
}

list drop(list l, int n){
    int i = 0;

    while (l != NULL && i < n)
    {
        Node* temp = l;
        l = l->next;
        free(temp);
        i++;
    }

    return l;
}

list copy_list(list l){
    if (l == NULL) return NULL;
    
    Node* new_head = malloc(sizeof(Node));
    if (new_head == NULL) return NULL;
    new_head->el = l->el;
    new_head->next = NULL;

    Node* curr_src = l->next;
    Node* curr_dst = new_head;
    while (curr_src != NULL) {
        Node* new_node = malloc(sizeof(Node));
        if (new_node == NULL) break;
        new_node->el = curr_src->el;
        new_node->next = NULL;
        curr_dst->next = new_node;
        curr_dst = new_node;
        curr_src = curr_src->next;
    }
    return new_head;
}

void destroy_list(list l){
    while (l != NULL)
    {
        Node* temp = l;
        l = l->next;
        free(temp);
    }
}