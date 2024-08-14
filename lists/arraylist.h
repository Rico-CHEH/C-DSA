#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    void *item;
} node;

typedef struct arraylist {
    int size;    // Number of elements in the list
    int length;  // Actual length of the array
    node *array;
} arraylist;

bool isEmpty(arraylist *l);
void* erase(arraylist *l, int index);
void insert(arraylist *l, int index, void *item);
void* pop(arraylist *l);
void push(arraylist *l, void *item);
void set(arraylist *l, int index, void *item);
void* get(arraylist *l, int index);
arraylist constructor(int length);

#endif  // ARRAYLIST_H
