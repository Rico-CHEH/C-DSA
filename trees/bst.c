#include "bst.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(bst* tree) {
    return tree->num_nodes == 0;
}

bool search(bst* tree, int value) {
    assert(tree != NULL);

    tree_node *node = tree->root;
    while (node != NULL && node->value != value) {
        if (value > node->value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    return node != NULL && node->value == value;
}

void add(bst* tree, int value) {
    assert(tree != NULL);

    tree_node* node = tree->root;
    tree_node* previous = NULL;
    while (node != NULL) {
        assert(node->value != value);

        previous = node;
        if (value > node->value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    tree->num_nodes++;
    node = (tree_node*) malloc(sizeof(tree_node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;


    if (previous == NULL) {
        tree->root = node;
        return;
    }

    if (value > previous->value) {
        previous->right = node;
    } else {
        previous->left = node;
    }
}

int height_helper(tree_node* tree) {
    if (tree == NULL) {
        return 0;
    }

    int left_height = height_helper(tree->right);
    int right_height = height_helper(tree->left);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

int height(bst* tree) {
    return height_helper(tree->root);
}

int inorder_helper(tree_node* root, tree_node** array, int index) {
    if (root == NULL) {
        return index;
    }

    index = inorder_helper(root->left, array, index);
    array[index++] = root;
    return inorder_helper(root->right, array, index);
}

tree_node** inorder(bst *tree) {
    assert(tree != NULL);

    tree_node **array = (tree_node**) malloc(tree->num_nodes * sizeof(tree_node*));
    inorder_helper(tree->root, array, 0);
    return array;
}

bst constructor() {
    bst tree = {.num_nodes = 0, .root = NULL};
    return tree;
}
