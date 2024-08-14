#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "unionfind.h"

bool isEmpty(unionfind* set) {
    assert(set != NULL);
    return set->num_items == 0;
}

int find(unionfind* set, int item) {
    assert(set != NULL);
    assert(item >= 0);
    assert(item < set->num_slots);
    assert(set->array[item].state != FREE);

    if (item == set->array[item].parent) {
        return item;
    }
    set->array[item].parent = find(set, set->array[item].parent);
    return set->array[item].parent;
}

void join(unionfind* set, int item1, int item2) {
    assert(set != NULL);
    assert(item1 >= 0);
    assert(item1 < set->num_slots);
    assert(set->array[item1].state != FREE);

    assert(item2 >= 0);
    assert(item2 < set->num_slots);
    assert(set->array[item2].state != FREE);

    if (find(set, item1) != find(set, item2)) {
        set->array[find(set, item1)].parent = find(set, item2);
        set->num_disjoint_trees--;
    }
}


// TODO: Add resize
void add(unionfind* set, int new_item, int parent) {
    assert(set != NULL);
    assert(new_item >= 0);
    assert(new_item < set->num_slots);
    assert(set->array[new_item].state == FREE);

    assert(parent >= 0);
    assert(parent < set->num_slots);

    if (parent == new_item) {
        set->array[new_item] = (node) {.parent = parent, .state = OCCUPIED};
        set->num_disjoint_trees++;
        set->num_items++;
        return;
    }

    assert(set->array[parent].state == OCCUPIED);

    // Check if it would be better to find the root of the tree
    set->array[new_item] = (node) {.parent = parent, .state = OCCUPIED};
    set->num_items++;
}

unionfind constructor(int length) {
    assert(length >= 0);

    length = length <= 10 ? 10 : length;

    node* array = (node*)calloc(length, sizeof(node));

    unionfind set = {.num_disjoint_trees = 0, .num_slots = 10, .num_items = 0, .array = array};

    return set;
}
