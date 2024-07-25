#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct arraylist {
    int size;    // Number of elements in the list
    int length;  // Actual length of the array
    int *array;
} arraylist;

bool isEmpty(arraylist *l);
int erase(arraylist *l, int index);
void insert(arraylist *l, int index, int item);
int pop(arraylist *l);
void push(arraylist *l, int item);
void set(arraylist *l, int index, int item);
int get(arraylist *l, int index);
arraylist constructor(int length);

#endif  // ARRAYLIST_H
