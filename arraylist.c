#include "arraylist.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(arraylist *l) { return l->size == 0; }

int pop(arraylist *l) {
  assert(l != NULL);
  assert(l->array != NULL);

  l->size--;
  return l->array[l->size];
}

int erase(arraylist *l, int index) {
  assert(l != NULL);
  assert(l->array != NULL);
  assert(index >= 0);
  assert(index < l->size);
  // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

  int result = l->array[index];
  l->size--;  // Lazily decrease amount of elements
  for (int i = index; i < l->size; i++) {
    l->array[i] = l->array[i + 1];
  }

  return result;
}

void resize(arraylist *l) {
  assert(l != NULL);
  assert(l->array != NULL);

  l->length = l->length * 3 / 2;
  int *newArray = (int *)malloc(l->length * sizeof(int));

  for (int i = 0; i < l->size; i++) {
    newArray[i] = l->array[i];
  }

  int *temp = l->array;
  l->array = newArray;
  free(temp);
}

void push(arraylist *l, int item) {
  assert(l != NULL);
  assert(l->array != NULL);

  if (l->size >= l->length) {
    resize(l);
  }

  l->array[l->size] = item;
  l->size++;
}

void insert(arraylist *l, int index, int item) {
  assert(l != NULL);
  assert(l->array != NULL);
  assert(index >= 0);
  assert(index < l->size);

  if (l->size >= l->length) {
    resize(l);
  }

  for (int i = l->size - 1; i >= index; i--) {
    l->array[i + 1] = l->array[i];
  }
  l->array[index] = item;
  l->size++;
}

void set(arraylist *l, int index, int item) {
  assert(l != NULL);
  assert(l->array != NULL);
  assert(index >= 0);
  assert(index < l->size);

  l->array[index] = item;
}

int get(arraylist *l, int index) {
  assert(l != NULL);
  assert(l->array != NULL);
  assert(index >= 0);
  assert(index < l->size);

  return l->array[index];
}

arraylist constructor(int length) {
  assert(length >= 0);

  length = length < 10 ? 10 : length;

  arraylist l;
  l.size = 0;
  l.length = length;
  l.array = (int *)malloc(length * sizeof(int));

  return l;
}
