#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int item;
    struct node* next;
} node;

typedef struct linkedlist {
    int size;
    node* head;
} linkedlist;

bool isEmpty(linkedlist* l);
void push(linkedlist* l, int item);
int pop(linkedlist* l);
void insert(linkedlist* l, int index, int item);
int erase(linkedlist* l, int index);
void set(linkedlist* l, int index, int item);
int get(linkedlist* l, int index);
void set(linkedlist* l, int index, int item);
linkedlist constructor();
#endif
