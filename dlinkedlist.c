#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cstdio>

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

bool isEmpty(dlinkedlist* l) { return l->size == 0; }

void push(dlinkedlist* l, void* item) {
    assert(l != NULL);

    d_node* new_node = (d_node*)malloc(sizeof(d_node));
    new_node->item = item;
    new_node->next = l->dummy_tail;
    new_node->prev = l->dummy_tail->prev;

    l->dummy_tail->prev = new_node;
    new_node->prev->next = new_node;
}

void* pop(dlinkedlist* l) {
    assert(l != NULL);
    assert(l->size > 0);

    d_node* old_node = l->dummy_tail->prev;
    void* old_value = old_node->item;

    old_node->prev->next = old_node->next;
    old_node->next->prev = old_node->prev;
    old_node->prev = NULL;
    old_node->next = NULL;
    old_node->item = NULL;
    free(old_node);

    return old_value;
}

void insert(dlinkedlist* l, int index, void* item) {
    assert(l != NULL);
    assert(index >= 0);
    assert(l->size >= index);

    d_node* new_node = (d_node*)malloc(sizeof(d_node));
    new_node->item = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    d_node* cur;
    if (index <= l->size / 2) {
        cur = l->dummy_head->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        new_node->next = cur;
        new_node->prev = cur->prev;
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
    } else {
        cur = l->dummy_tail->prev;
        for (int i = l->size - 1; i > index; i--) {
            cur = cur->prev;
        }
        new_node->next = cur;
        new_node->prev = cur->prev;
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
    }
    l->size++;
}

void* erase(dlinkedlist* l, int index) {
    assert(l != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    d_node* cur;
    if (index <= l->size / 2) {
        cur = l->dummy_head->next;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }
    else {
        cur = l->dummy_tail->prev;
        for (int i = l->size - 1; i >= index; i--) {
            cur = cur->prev;
        }
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }

    void* old_value = cur->item;
    cur->next = NULL;
    cur->prev = NULL;
    free(cur);

    return old_value;
}

void* get(dlinkedlist* l, int index) {
    assert(l != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    d_node* cur;
    if (index <= l->size / 2) {
        cur = l->dummy_head->next;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
    }
    else {
        cur = l->dummy_tail->prev;
        for (int i = l->size - 1; i >= index; i--) {
            cur = cur->prev;
        }
    }

    return cur->item;
}

void set(dlinkedlist* l, int index, void* item) {
    assert(l != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    d_node* cur;
    if (index <= l->size / 2) {
        cur = l->dummy_head->next;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
    }
    else {
        cur = l->dummy_tail->prev;
        for (int i = l->size - 1; i >= index; i--) {
            cur = cur->prev;
        }
    }

    cur->item = item;
}

dlinkedlist constructor() {
    dlinkedlist l;
    l.size = 0;
    l.dummy_head = (d_node*) malloc(sizeof(d_node));
    l.dummy_tail = (d_node*) malloc(sizeof(d_node));

    l.dummy_head->item = NULL;
    l.dummy_head->next = l.dummy_tail;
    l.dummy_head->prev = NULL;

    l.dummy_tail->item = NULL;
    l.dummy_tail->next = NULL;
    l.dummy_tail->prev = l.dummy_head;

    return l;
}
