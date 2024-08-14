#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct tree_node {
    int value;
    struct tree_node* left;
    struct tree_node* right;
}tree_node;

typedef struct bst {
    int num_nodes;
    tree_node* root;
} bst;

bool isEmpty(bst* tree);
bool search(bst* tree, int value);
void add(bst* tree, int value);
int height(bst* tree);
tree_node** inorder(bst *tree);
bst constructor();

#endif
