#include "linkedlist.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(linkedlist* l) { return l->size == 0; }

void push(linkedlist* l, void* item) {
    assert(l != NULL);

    node* newNode = (node*) malloc(sizeof(node));
    newNode->item = item;
    newNode->next = NULL;
    l->size++;

    if (l->head == NULL) {
        l->head = newNode;
        return;
    }

    node* cur = l->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = newNode;
}

void* pop(linkedlist* l) {
    assert(l != NULL);
    assert(l->head != NULL);
    assert(l->size > 0);

    void* result;

    node* cur = l->head;
    while (cur->next != NULL && cur->next->next != NULL) {
        cur = cur->next;
    }
    if (cur->next == NULL) {
        result = cur->item;
        free(cur);
        l->head = NULL;
    } else {
        result = cur->next->item;
        free(cur->next);
        cur->next = NULL;
    }
    l->size--;

    return result;
}

void insert(linkedlist* l, int index, void* item) {
    assert(l != NULL);
    assert(l->head != NULL);
    assert(index >= 0);
    assert(l->size > index);

    node* newNode = (node*)malloc(sizeof(node));
    newNode->item = item;
    newNode->next = NULL;

    node* cur = l->head;
    for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    l->size++;
}

void* erase(linkedlist* l, int index) {
    assert(l != NULL);
    assert(l->head != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    void* result;
    node* removeNode;
    l->size--;

    if (l->size == 0) {
        result = l->head->item;
        removeNode = l->head->next;
        l->head = NULL;
        free(removeNode);
        return result;
    }

    node* cur = l->head;
    for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
    }

    removeNode = cur->next;
    result = removeNode->item;
    cur->next = cur->next->next;
    removeNode->next = NULL;
    free(removeNode);
    return result;
}

void* get(linkedlist* l, int index) {
    assert(l != NULL);
    assert(l->head != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    node* cur = l->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->item;
}

void set(linkedlist* l, int index, void* item) {
    assert(l != NULL);
    assert(l->head != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(l->size > index);

    node* cur = l->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    cur->item = item;
}

linkedlist constructor() {
    linkedlist l;
    l.size = 0;
    l.head = NULL;
    return l;
}
