#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

List empty(){
    return NULL;
}

List addl(int e, List l){
    Node* p = malloc(sizeof(Node));
    assert(p != NULL);

    p->elem = e;
    p->next = l;
    
    return p;
}

bool is_empty(List l){
    return l == NULL;
}

int head(List l){
    assert(l != NULL);

    return l->elem;
}

List tail(List l){
    assert(l != NULL);
    Node* aux = l;

    l = l->next;
    free(aux);

    return l;
}

List addr(List l, int e){
    Node* temp = malloc(sizeof(Node));
    assert(temp != NULL);
    temp->elem = e;
    temp->next = NULL;

    assert(l != NULL);

    Node* ptr = l;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    
    ptr->next = temp;

    return l;
}

int length(List l){
    int count = 0;
    Node* ptr = l;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    return count;
}

List concat(List l, List l0){
    assert(l != NULL);
    Node* aux = l;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    aux->next = l0;

    return l;
}

int index(List l, int n){
    assert(length(l) > n);
    int count = 0;
    Node* ptr = l;

    while (ptr != NULL && count < n)
    {
        ptr = ptr->next;
        count++;
    }

    return ptr->elem;
}

List take(List l, int n){
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

List drop(List l, int n){
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

List copy_list(List l){
    assert(l != NULL);
    
    Node* new_head = malloc(sizeof(Node));
    assert(new_head != NULL);
    new_head->elem = l->elem;
    new_head->next = NULL;

    Node* curr_src = l->next;
    Node* curr_dst = new_head;
    while (curr_src != NULL) {
        Node* new_node = malloc(sizeof(Node));
        new_node->elem = curr_src->elem;
        new_node->next = NULL;
        curr_dst->next = new_node;
        curr_dst = new_node;
        curr_src = curr_src->next;
    }
    return new_head;
}

void destroy_list(List l){
    while (l != NULL)
    {
        Node* temp = l;
        l = l->next;
        free(temp);
    }
}