#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* item;
    struct node* next;
} node;

typedef struct linkedlist {
    int size;
    node* head;
} linkedlist;

bool isEmpty(linkedlist* l);
void push(linkedlist* l, void* item);
void* pop(linkedlist* l);
void insert(linkedlist* l, int index, void* item);
void* erase(linkedlist* l, int index);
void* get(linkedlist* l, int index);
void set(linkedlist* l, int index, void* item);
linkedlist constructor();
#endif
