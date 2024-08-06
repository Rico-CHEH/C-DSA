#include <stdbool.h>
#include <stdlib.h>

typedef enum status {
    OCCUPIED,
    EMPTY,
} status;

typedef struct bst {
    int value;
    status state;
    struct bst* left;
    struct bst* right;
} bst;

bool search(bst* tree, int value) {
    while (tree != NULL && tree->state != EMPTY && tree->value != value) {
        if (tree->value < value) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree != NULL && tree->state != EMPTY && tree->value == value;
}

bool remove(bst* tree, int value) {
    while (tree != NULL && tree->state != EMPTY && tree->value != value) {
        if (tree->value < value) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    if (tree != NULL || tree->state == EMPTY) {
        return true;
    }

}

bool add(bst* tree, int value) {
    if (tree == NULL) {
        tree = (bst*)malloc(sizeof(bst));
        tree->value = value;
        tree->state = OCCUPIED;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (tree->state == EMPTY) {
        tree->value = value;
        tree->state = OCCUPIED;
    }
    else if (tree->value < value) {
        add(tree->left, value);
    }
    else if (tree->value > value) {
        add(tree->right, value);
    }
    else {
        return false;
    }
    return true;
}

bst constructor() {
    bst tree = {.state = EMPTY, .left = NULL, .right = NULL};
    return tree;
}
