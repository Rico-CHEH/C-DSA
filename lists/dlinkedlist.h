#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct d_node {
    void* item;
    struct d_node* next;
    struct d_node* prev;
} d_node;

typedef struct dlinkedlist {
    int size;
    d_node* dummy_head;
    d_node* dummy_tail;
} dlinkedlist;


bool isEmpty(dlinkedlist* l);
void push(dlinkedlist* l, void* item);
void* pop(dlinkedlist* l);
void insert(dlinkedlist* l, int index, void* item);
void* erase(dlinkedlist* l, int index);
void* get(dlinkedlist* l, int index);
void set(dlinkedlist* l, int index, void* item);
dlinkedlist constructor();

#endif
