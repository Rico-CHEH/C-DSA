#ifndef HASHMAP_H
#define HASHMAP_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum status { EMPTY, OCCUPIED, DELETED } status;

typedef struct hashEntry {
    int key;
    int value;
    status state;
} hashEntry;

typedef struct hashmap {
    int num_entries;  // Indicates number key, value pairs currently in hashmap
    int num_slots;    // Indicates number of slots in the hashmap
    hashEntry *array;
} hashmap;

int search(hashmap *map, int key);
void resize(hashmap *map);
int update(hashmap *map, int key, int value);
void insert(hashmap *map, int key, int value);
int erase(hashmap *map, int key);
hashmap constructor(int length);
#endif
