#include "arraylist.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(arraylist *l) { return l->size == 0; }

void* pop(arraylist *l) {
    assert(l != NULL);
    assert(l->array != NULL);
    assert(l->size > 0);

    l->size--;
    return l->array[l->size].item;
}

void* erase(arraylist *l, int index) {
    assert(l != NULL);
    assert(l->array != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(index < l->size);
    // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

    void *result = l->array[index].item;
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
    node *newArray = (node *)malloc(l->length * sizeof(node));

    for (int i = 0; i < l->size; i++) {
        newArray[i] = l->array[i];
    }

    node *temp = l->array;
    l->array = newArray;
    free(temp);
}

void push(arraylist *l, void* item) {
    assert(l != NULL);
    assert(l->array != NULL);

    if (l->size >= l->length) {
        resize(l);
    }

    l->array[l->size] = (node) {.item = item};
    l->size++;
}

void insert(arraylist *l, int index, void *item) {
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
    l->array[index] = (node) {.item = item};
    l->size++;
}

void set(arraylist *l, int index, void *item) {
    assert(l != NULL);
    assert(l->array != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(index < l->size);

    l->array[index] = (node) {.item = item};
}

void* get(arraylist *l, int index) {
    assert(l != NULL);
    assert(l->array != NULL);
    assert(l->size > 0);
    assert(index >= 0);
    assert(index < l->size);

    return l->array[index].item;
}

arraylist constructor(int length) {
    assert(length >= 0);

    length = length < 10 ? 10 : length;

    arraylist l;
    l.size = 0;
    l.length = length;
    l.array = (node *)malloc(length * sizeof(node));

    return l;
}
