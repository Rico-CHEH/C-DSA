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

void erase(bst* tree, int value) {
    assert(tree != NULL);
    assert(tree->root != NULL);

    tree_node *node = tree->root;
    while (node != NULL && node->value != value) {
        if (value > node->value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    assert(node != NULL);
    tree->num_nodes--;

    // 3 cases:
    // case 1 => node->right = NULL
    // case 2 => node->right->left = NULL
    // case 3 => node->right->left->...->left = NULL
    tree_node* var;
    if (node->right == NULL) {
        var = node->left;
        node->value = node->left->value;
        node->right = node->left->right;
        node->left = node->left->left;

    } else if (node->right->left == NULL) {
        var = node->right;
        node->value = node->right->value;
        node->right = node->right->right;
        node->left = node->right->left;
    } else {
        tree_node* cur = node->right;
        while (cur->left->left != NULL) {
            cur = cur->left;
        }
        node->value = cur->left->value;
        node->right = cur->left->right;
        node->left = cur->left->left;

        var = cur->left;
        cur->left = NULL;
    }

    var->left = NULL;
    var->right = NULL;
    free(var);
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
    assert(tree != NULL);
    if (tree == NULL) {
        return 0;
    }

    int left_height = height_helper(tree->right);
    int right_height = height_helper(tree->left);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

int height(bst* tree) {
    assert(tree != NULL);
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
