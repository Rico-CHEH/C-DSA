#include "hashmap.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int modulo(int a, int b) {
    int r = a % b;
    if (a >= 0 || r == 0) {
        return r;
    }
    return r + b;
}

// TODO: Add a union with "all" possible hashings
int hash_division(hashmap *map, int key) {
    assert(map != NULL);
    return modulo(key, map->num_slots);
}

// TODO: Create different probings
int linear_probing(hashmap *map, int key) {
    assert(map != NULL);

    int pos = hash_division(map, key);
    hashEntry *entry = &map->array[pos];

    for (int i = 0; i < map->num_slots; i++) {
        if (entry->state == EMPTY ||
            (entry->state == OCCUPIED && entry->key == key)) {
            break;
        }
        pos = modulo(++pos, map->num_slots);
        entry = &map->array[pos];
    }
    return pos;
}

int search(hashmap *map, int key) {
    assert(map != NULL);

    int pos = linear_probing(map, key);
    hashEntry *entry = &map->array[pos];
    assert(entry->state == OCCUPIED &&
           entry->key == key);  // Making sure that the value exists

    return entry->value;
}

// TODO: Add load factor implementation
void resize(hashmap *map) {
    assert(map != NULL);

    int old_length = map->num_slots;
    int new_length = map->num_slots * 3 / 2;
    hashEntry *old_array = map->array;
    hashEntry *new_array = (hashEntry *)malloc(new_length * sizeof(hashEntry));

    for (int i = 0; i < new_length; i++) {
        new_array[i].state = EMPTY;
    }

    map->num_slots = new_length;
    map->array = new_array;
    int pos;
    for (int i = 0; i < old_length; i++) {
        pos = linear_probing(map, old_array[i].key);

        // Sanity check that state is empty
        assert(map->array[pos].state == EMPTY);
        map->array[pos] = old_array[i];
    }
    free(old_array);
}

int update(hashmap *map, int key, int value) {
    assert(map != NULL);
    int pos = linear_probing(map, key);
    hashEntry *entry = &map->array[pos];

    // Making sure the value exists
    assert(entry->state == OCCUPIED && entry->key == key);

    int old_value = entry->value;
    entry->value = value;
    return old_value;
}

void insert(hashmap *map, int key, int value) {
    assert(map != NULL);

    if (map->num_entries >= map->num_slots) {
        resize(map);
    }

    int pos = hash_division(map, key);
    hashEntry *entry = &map->array[pos];

    for (int i = 0; i < map->num_slots; i++) {
        if (entry->state == EMPTY || entry->state == DELETED) {
            break;
        }
        if (entry->state == OCCUPIED && entry->key == key) {
            break;
        }
        pos = modulo(++pos, map->num_slots);
        entry = &map->array[pos];
    }

    // Making sure the key is not in the table
    assert(entry->state == EMPTY || entry->state == DELETED);

    map->num_entries++;
    entry->key = key;
    entry->value = value;
    entry->state = OCCUPIED;
}

int erase(hashmap *map, int key) {
    assert(map != NULL);

    int pos = linear_probing(map, key);
    hashEntry *entry = &map->array[pos];
    assert(entry->state == OCCUPIED &&
           entry->key == key);  // Making sure that the value exists

    map->num_entries--;
    entry->state = DELETED;  // Lazily deleting object
    return entry->value;
}

hashmap constructor(int length) {
    assert(length >= 0);

    length = length < 10 ? 10 : length;

    hashmap map;
    map.array = (hashEntry *)malloc(length * sizeof(hashEntry));
    map.num_slots = length;
    map.num_entries = 0;

    for (int i = 0; i < length; i++) {
        map.array[i].state = EMPTY;
    }

    return map;
}
