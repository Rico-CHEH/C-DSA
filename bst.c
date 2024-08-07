#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bst {
    int value;
    struct bst* left;
    struct bst* right;
} bst;

bool search(bst* tree, int value) {
    assert(tree != NULL);

    while (tree != NULL && tree->value != value) {
        if (tree->value < value) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree != NULL && tree->value == value;
}

void remove(bst* tree, int value) {
    assert(tree != NULL);

    bst* previous;
    while (tree != NULL && tree->value != value) {
        previous = tree;
        if (tree->value < value) {
            tree = tree->left;
        } else {
            tree = tree->left;
        }
    }

    assert(tree != NULL);

    // 3 cases:
    // case 1 => tree->right = NULL
    // case 2 => tree->right->left = NULL
    // case 3 => tree->right->left->...->left = NULL
    bst* var;
    if (tree->right == NULL) {
        var = tree->left;
        tree->value = tree->left->value;
        tree->right = tree->left->right;
        tree->left = tree->left->left;

    } else if (tree->right->left == NULL) {
        var = tree->right;
        tree->value = tree->right->value;
        tree->right = tree->right->right;
        tree->left = tree->right->left;
    } else {
        bst* cur = tree->right;
        while (cur->left->left != NULL) {
            cur = cur->left;
        }
        tree->value = cur->left->value;
        tree->right = cur->left->right;
        tree->left = cur->left->left;

        var = cur->left;
        cur->left = NULL;
    }

    var->left = NULL;
    var->right = NULL;
    free(var);
}

void add(bst* tree, int value) {
    if (tree == NULL) {
        tree = (bst*)malloc(sizeof(bst));
        tree->left = NULL;
        tree->right = NULL;
    }

    assert(tree->value != value);
    if (tree->value < value) {
        add(tree->left, value);
    } else {
        add(tree->right, value);
    }
}

int height(bst* tree) {
    if (tree == NULL) {
        return 0;
    }

    return max(height(tree->right), height(tree->left)) + 1;
}

bst* constructor() { return NULL; }
