#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void free_helper(bst *tree) {
    tree_node **array = inorder(tree);

    tree->root = NULL;
    tree_node *node;
    for (int i = 0; i < tree->num_nodes; ++i) {
        node = array[i];
        node->left = NULL;
        node->right = NULL;
        free(node);
    }
    free(array);
}

void test_constructor() {
    printf("================== Testing constructor ==================\n");
    bst tree = constructor();

    assert(tree.num_nodes == 0);
    printf("Test passed: tree.num_nodes == 0\n");
    assert(tree.root == NULL);
    printf("Test passed: tree.root == NULL\n");

    printf(
        "================== Finished Testing constructor ==================\n");
    printf("\n");
}

void test_add() {
    printf("================== Testing add ==================\n");
    bst tree = constructor();

    printf("------------ Start Test 1 ------------\n");
    add(&tree, 1);

    assert(tree.num_nodes == 1);
    printf("Test passed: tree.num_nodes == 1\n");
    assert(tree.root != NULL);
    printf("Test passed: tree.root != NULL\n");
    assert(tree.root->left == NULL);
    printf("Test passed: tree.root->left == NULL\n");
    assert(tree.root->right == NULL);
    printf("Test passed: tree.root->right == NULL\n");

    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");
    add(&tree, 69);

    assert(tree.num_nodes == 2);
    printf("Test passed: tree.num_nodes == 2\n");
    assert(tree.root->right != NULL);
    printf("Test passed: tree.root->right != NULL\n");
    assert(tree.root->right->value == 69);
    printf("Test passed: tree.root->right->value == 69\n");
    assert(tree.root->right->left == NULL);
    printf("Test passed: tree.root->right->left == NULL\n");
    assert(tree.root->right->right == NULL);
    printf("Test passed: tree.root->right->right == NULL\n");

    printf("------------ End Test 2 ------------\n");
    printf("\n");

    printf("------------ Start Test 3 ------------\n");
    add(&tree, 420);

    assert(tree.num_nodes == 3);
    printf("Test passed: tree.num_nodes == 3\n");
    assert(tree.root->right->right != NULL);
    printf("Test passed: tree.root->right->right != NULL\n");
    assert(tree.root->right->right->value == 420);
    printf("Test passed: tree.root->right->right->value == 420\n");
    assert(tree.root->right->right->left == NULL);
    printf("Test passed: tree.root->right->right->left == NULL\n");
    assert(tree.root->right->right->right == NULL);
    printf("Test passed: tree.root->right->right->right == NULL\n");

    printf("------------ Start Test 3 ------------\n");
    printf("\n");

    printf("------------ Start Test 4 ------------\n");
    add(&tree, -69);

    assert(tree.num_nodes == 4);
    printf("Test passed: tree.num_nodes == 4\n");
    assert(tree.root->left != NULL);
    printf("Test passed: tree.root->left != NULL\n");
    assert(tree.root->left->value == -69);
    printf("Test passed: tree.root->left->value == -69\n");
    assert(tree.root->left->left == NULL);
    printf("Test passed: tree.root->left->left == NULL\n");
    assert(tree.root->left->right == NULL);
    printf("Test passed: tree.root->left->right == NULL\n");

    printf("------------ End Test 4 ------------\n");
    printf("\n");

    printf("------------ Start Test 5 ------------\n");
    add(&tree, -420);

    assert(tree.num_nodes == 5);
    printf("Test passed: tree.num_nodes == 5\n");
    assert(tree.root->left->left != NULL);
    printf("Test passed: tree.root->left->left != NULL\n");
    assert(tree.root->left->left->value == -420);
    printf("Test passed: tree.root->left->left->value == -420\n");
    assert(tree.root->left->left->left == NULL);
    printf("Test passed: tree.root->left->left->left == NULL\n");
    assert(tree.root->left->left->right == NULL);
    printf("Test passed: tree.root->left->left->right == NULL\n");

    printf("------------ End Test 5 ------------\n");
    printf("\n");

    printf("------------ Start Test 6 ------------\n");
    add(&tree, 7);

    assert(tree.num_nodes == 6);
    printf("Test passed: tree.num_nodes == 6\n");
    assert(tree.root->right->left != NULL);
    printf("Test passed: tree.root->right->left != NULL\n");
    assert(tree.root->right->left->value == 7);
    printf("Test passed: tree.root->right->left->value == 7\n");
    assert(tree.root->right->left->left == NULL);
    printf("Test passed: tree.root->right->left->left == NULL\n");
    assert(tree.root->right->left->right == NULL);
    printf("Test passed: tree.root->right->left->right == NULL\n");

    printf("------------ End Test 6 ------------\n");

    free_helper(&tree);
    printf("================== Finished Testing add ==================\n");
    printf("\n");
}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");
    bst tree = constructor();

    assert(isEmpty(&tree) == true);
    printf("Test passed: isEmpty(&tree) == true\n");

    add(&tree, 123);
    assert(isEmpty(&tree) == false);
    printf("Test passed: isEmpty(&tree) == false\n");

    free_helper(&tree);
    printf("================== Finishec Testing isEmpty ==================\n");
    printf("\n");
}

void test_height() {
    printf("================== Finished Testing height ==================\n");
    bst tree = constructor();

    assert(height(&tree) == 0);
    printf("Test passed: height(&tree) == 0\n");

    add(&tree, 1);
    assert(height(&tree) == 1);
    printf("Test passed: height(&tree) == 1\n");

    add(&tree, 2);
    assert(height(&tree) == 2);
    printf("Test passed: height(&tree) == 2\n");

    add(&tree, -60);
    assert(height(&tree) == 2);
    printf("Test passed: height(&tree) == 2\n");

    free_helper(&tree);
    printf("================== Finished Testing height ==================\n");
    printf("\n");
}

void test_search() {}

void test_inorder() {}

int main() {
    printf("\n");
    test_constructor();
    test_add();
    test_isEmpty();
    test_height();
    test_search();
    test_inorder();
}
