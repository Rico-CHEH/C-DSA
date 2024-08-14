#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <stdbool.h>

typedef enum status {
    FREE,
    OCCUPIED,
} status;

typedef struct node {
    int parent;
    status state;
} node;

typedef struct unionfind {
    int num_disjoint_trees;
    int num_slots;
    int num_items;
    node* array;
} unionfind;

bool isEmpty(unionfind* set);
int find(unionfind* set, int item);
void join(unionfind* set, int item1, int item2);
void add(unionfind* set, int new_item, int parent);
unionfind constructor(int length);

#endif
