#include <assert.h>
#include <stdlib.h>

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
    int numEntries;
    int numSlots;
    hashEntry *array;
}hashmap;

// TODO: Add a union with "all" possible hashings
int hash_division(hashmap *map, int key){
    assert(map != NULL);
    int r = key % map->numSlots;
    if (key >= 0 || r == 0) {
        return r;
    }
    return r + map->numSlots;
}

int linear_probing(hashmap *map, int key){
}

hashmap constructor(int length) {
    assert(length >= 0);

    length = length < 10 ? 10 : length;

    hashmap map;
    map.numEntries = 0;
    map.numSlots = length;
    map.array = (hashEntry*) malloc(length * sizeof(hashEntry));

    return map;
}
