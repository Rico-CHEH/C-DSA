#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct arraylist {
  int size;    // Number of elements in the list
  int length;  // Actual length of the array
  int *array;
} arraylist;

bool isEmpty(arraylist *l);
void pop(arraylist *l, int index);
void push(arraylist *l, int item);
void set(arraylist *l, int index, int item);
int get(arraylist *l, int index);
arraylist constructor(int length);

#endif // ARRAYLIST_H
