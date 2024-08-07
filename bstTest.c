#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

// TODO: Remove print statements
void free_helper(bst *tree) {
    tree_node **array = inorder(tree);

    tree->root = NULL;
    tree_node *node;
    for (int i = 0; i < tree->num_nodes; ++i) {
        node = array[i];
        printf("%d ", node->value);
        node->left = NULL;
        node->right = NULL;
        free(node);
    }
    printf("\n");
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

void test_erase() {
    printf("================== Testing erase ==================\n");

    printf("------------ Start Test 1 ------------\n");
    bst tree1 = constructor();
    add(&tree1, 1);
    erase(&tree1, 1);

    assert(tree1.num_nodes == 0);
    printf("Test passed: tree1.num_nodes == 0\n");
    assert(tree1.root == NULL);
    printf("Test passed: tree1.root == NULL\n");

    free_helper(&tree1);
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");
    bst tree2 = constructor();
    add(&tree2, 1);
    add(&tree2, 69);  //                       |----------(1)----------|
    add(&tree2, -1);  //              |------(-1)                      (69)
    add(&tree2, -2);  //        |---(-2)
    add(&tree2, -3);  //      (-3)
    erase(&tree2, 1);

    assert(tree2.num_nodes == 4);
    printf("Test passed: tree2.num_nodes == 4\n");
    assert(tree2.root->value == 69);
    printf("Test passed: tree2.root->value == 69\n");
    assert(tree2.root->right == NULL);
    printf("Test passed: tree2.root->right == NULL\n");

    assert(tree2.root->left->value == -1);
    printf("Test passed: tree2.root->left->value == -1\n");
    assert(tree2.root->left->right == NULL);
    printf("Test passed: tree2.root->left->right == NULL\n");

    assert(tree2.root->left->left->value == -2);
    printf("Test passed: tree2.root->left->left->value == -2\n");
    assert(tree2.root->left->left->right == NULL);
    printf("Test passed: tree2.root->left->left->right == NULL\n");

    assert(tree2.root->left->left->left->value == -3);
    printf("Test passed: tree2.root->left->left->left->value == -3\n");
    assert(tree2.root->left->left->left->right == NULL);
    printf("Test passed: tree2.root->left->left->left->right == NULL\n");
    assert(tree2.root->left->left->left->right == NULL);
    printf("Test passed: tree2.root->left->left->left->right == NULL\n");

    free_helper(&tree2);
    printf("------------ End Test 2 ------------\n");
    printf("\n");

    // Testing case 1
    printf("------------ Start Test 3 ------------\n");
    bst tree3 = constructor();
    add(&tree3, 1);
    add(&tree3, 69);  //                       |----------(1)----------|
    add(&tree3, -1);  //              |------(-1)                      (69)
    add(&tree3, -2);  //        |---(-2)
    add(&tree3, -3);  //      (-3)
    erase(&tree3, -1);

    assert(tree3.num_nodes == 4);
    printf("Test passed: tree3.num_nodes == 4\n");
    assert(tree3.root->value == 1);
    printf("Test passed: tree3.root->value == 1\n");
    assert(tree3.root->right == NULL);
    printf("Test passed: tree3.root->right == NULL\n");

    assert(tree3.root->left->value == -2);
    printf("Test passed: tree3.root->left->value == -2\n");
    assert(tree3.root->left->right == NULL);
    printf("Test passed: tree3.root->left->right == NULL\n");

    assert(tree3.root->left->left->value == -3);
    printf("Test passed: tree3.root->left->left->value == -3\n");
    assert(tree3.root->left->left->right == NULL);
    printf("Test passed: tree3.root->left->left->right == NULL\n");
    assert(tree3.root->left->left->left == NULL);
    printf("Test passed: tree3.root->left->left->left == NULL\n");

    free_helper(&tree3);
    printf("------------ End Test 3 ------------\n");
    printf("\n");

    // Testing case 2
    printf("------------ Start Test 4 ------------\n");
    bst tree4 = constructor();
    add(&tree4, 1);
    add(&tree4, 69);  //                       |----------(1)----------|
    add(&tree4, -1);  //              |------(-1)------|              (69)
    add(&tree4, -2);  //        |---(-2)              (0)
    add(&tree4, -3);  //      (-3)
    add(&tree4, 0);
    erase(&tree4, -1);

    assert(tree4.num_nodes == 5);
    printf("Test passed: tree4.num_nodes == 5\n");
    assert(tree4.root->value == 1);
    printf("Test passed: tree4.root->value == 1\n");

    assert(tree4.root->right->value == 69);
    printf("Test passed: tree4.root->right->value == 69\n");
    assert(tree4.root->right->right == NULL);
    printf("Test passed: tree4.root->right->right == NULL\n");
    assert(tree4.root->right->left == NULL);
    printf("Test passed: tree4.root->right->left == NULL\n");

    assert(tree4.root->left->value == -1);
    printf("Test passed: tree4.root->left->value == -1\n");

    assert(tree4.root->left->right->value == 0);
    printf("Test passed: tree4.root->left->right->value == 0\n");
    assert(tree4.root->left->right->right == NULL);
    printf("Test passed: tree4.root->left->right->right == NULL\n");
    assert(tree4.root->left->right->left == NULL);
    printf("Test passed: tree4.root->left->right->left == NULL\n");

    assert(tree4.root->left->left->value == -2);
    printf("Test passed: tree4.root->left->left->value == -2\n");
    assert(tree4.root->left->left->right == NULL);
    printf("Test passed: tree4.root->left->left->right == NULL\n");
    assert(tree4.root->left->left->left->value == -3);
    printf("Test passed: tree4.root->left->left->left->value == -3\n");
    assert(tree4.root->left->left->left->right == NULL);
    printf("Test passed: tree4.root->left->left->left->right == NULL\n");
    assert(tree4.root->left->left->left->left == NULL);
    printf("Test passed: tree4.root->left->left->left->left == NULL\n");

    free_helper(&tree4);
    printf("------------ End Test 4 ------------\n");
    printf("\n");

    // Testing case 3
    printf("------------ Start Test 5 ------------\n");
    bst tree5 = constructor();
    add(&tree5, 1);
    add(&tree5, 69);     //                       |----------(1)----------|
    add(&tree5, -4);     //              |------(-4)------|              (69)
    add(&tree5, -420);   //     |---(-420)           |---(0)
    add(&tree5, -4269);  //(-4269)                 (-2)
    add(&tree4, 0);
    add(&tree4, -2);
    erase(&tree5, -4);

    assert(tree5.num_nodes == 6);
    printf("Test passed: tree5.num_nodes == 6\n");
    assert(tree5.root->value == 1);
    printf("Test passed: tree5.root->value == 1\n");

    assert(tree5.root->right->value == 69);
    printf("Test passed: tree5.root->right->value == 69\n");
    assert(tree5.root->right->right == NULL);
    printf("Test passed: tree5.root->right->right == NULL\n");
    assert(tree5.root->right->left == NULL);
    printf("Test passed: tree5.root->right->left == NULL\n");

    assert(tree5.root->left->value == -2);
    printf("Test passed: tree5.root->left->value == -2\n");

    assert(tree5.root->left->right->value == 0);
    printf("Test passed: tree5.root->left->right->value == 0\n");
    assert(tree5.root->left->right->right == NULL);
    printf("Test passed: tree5.root->left->right->right == NULL\n");
    assert(tree5.root->left->right->left == NULL);
    printf("Test passed: tree5.root->left->right->left == NULL\n");

    assert(tree5.root->left->left->value == -420);
    printf("Test passed: tree5.root->left->left->value == -420\n");
    assert(tree5.root->left->left->right == NULL);
    printf("Test passed: tree5.root->left->left->right == NULL\n");

    assert(tree5.root->left->left->left->value == -4269);
    printf("Test passed: tree5.root->left->left->left->value == -4269\n");
    assert(tree5.root->left->left->left->right == NULL);
    printf("Test passed: tree5.root->left->left->left->right == NULL\n");
    assert(tree5.root->left->left->left->left == NULL);

    free_helper(&tree5);
    printf("------------ End Test 5 ------------\n");
    printf("\n");

    printf("------------ Start Test 6 ------------\n");
    bst tree6 = constructor();
    add(&tree6, 1);
    add(&tree6, 69);  //                       |----------(1)----------|
    add(&tree6, -1);  //                     (-1)                      (69)
    erase(&tree6, -1);

    assert(tree6.num_nodes == 2);
    printf("Test passed: tree6.num_nodes == 2\n");
    assert(tree6.root->value == 1);
    printf("Test passed: tree6.root->value == 1\n");

    assert(tree6.root->left == NULL);
    printf("Test passed: tree6.root->left == NULL\n");
    assert(tree6.root->right->value == 69);
    printf("Test passed: tree6.root->right->value == 69\n");
    assert(tree6.root->right->right == NULL);
    printf("Test passed: tree6.root->right->right == NULL\n");
    assert(tree6.root->right->left == NULL);
    printf("Test passed: tree6.root->right->left == NULL\n");

    free_helper(&tree6);
    printf("------------ End Test 6 ------------\n");

    printf("================== Finished Testing erase ==================\n");
    printf("\n");
}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");

    printf("================== Finishec Testing isEmpty ==================\n");
}

void test_height() {
    printf("================== Finished Testing height ==================\n");

    printf("================== Finished Testing height ==================\n");
}

void test_search() {}

void test_inorder() {}

int main() {
    printf("\n");
    test_constructor();
    test_add();
    test_erase();
    test_isEmpty();
    test_height();
    test_search();
    test_inorder();
}
