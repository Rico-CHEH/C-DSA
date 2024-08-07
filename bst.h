#ifndef BST_H
#define BST_H

typedef struct bst {
    int value;
    struct bst* left;
    struct bst* right;
} bst;

bool search(bst* tree, int value);
void remove(bst* tree, int value);
void add(bst* tree, int value);
int height(bst* tree);
bst* constructor();

#endif
