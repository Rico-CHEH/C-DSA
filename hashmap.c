#include <assert.h>
#include <stdlib.h>

#include "arraylist.h"

typedef enum status {
    EMPTY,
    OCCUPIED,
    DELETED
}status;

typedef struct hashEntry{
    int key;
    int value;
    status state;
}hashEntry;

typedef struct hashmap {
    int num_entries;
    int num_slots;
    arraylist list;
}hashmap;

int modulo(int a, int b) {
    int r = a % b;
    if (a >= 0 || r == 0) {
        return r;
    }
    return r + b;
}

// TODO: Add a union with "all" possible hashings
int hash_division(hashmap *map, int key){
    assert(map != NULL);
    return modulo(key, map->num_slots);
}

// TODO: Create different probings
int linear_probing(hashmap *map, int key){
    assert(map != NULL);
    assert(map->num_slots > map->num_entries);

    int i = 0;
    int pos = hash_division(map, key);

    while (((hashEntry*)get(&map->list, pos))->state != EMPTY) {
        pos = modulo(++pos, map->num_slots);
    }

    return pos;
}

void search(hashmap *map, int key) {
    assert(map != NULL);

    int i = 0;
    int pos = hash_division(map, key);
    hashEntry *entry = ((hashEntry*)get(&map->list, pos));
    status cur_state = entry->state;

    while (cur_state != EMPTY || (cur_state == OCCUPIED && entry->key == key) {
        pos = modulo(++pos, map->num_slots);
        entry = ((hashEntry*)get(&map->list, pos));
        cur_state = entry->state;
    }

    
}

hashmap constructor(int length) {
    assert(length >= 0);

    length = length < 10 ? 10 : length;

    hashmap map;
    map.list = constructor(length);
    map.num_entries = map.list.size;
    map.num_slots = map.list.length;

    return map;
}
