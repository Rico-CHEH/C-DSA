#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "unionfind.h"

void free_helper(unionfind *t) { free(t->array); }

void test_constructor() {
    printf("================== Testing constructor ==================\n");
    unionfind t = constructor(10);

    assert(t.array != NULL);
    printf("Test passed: t.array != NULL\n");
    assert(t.num_items == 0);
    printf("Test passed: t.num_items == 0\n");
    assert(t.num_slots == 10);
    printf("Test passed: t.num_slots == 10\n");
    assert(t.num_disjoint_trees == 0);
    printf("Test passed: t.num_disjoint_trees == 0\n");

    free_helper(&t);
    printf(
        "================== Finished Testing constructor ==================\n");
    printf("\n");
}

void test_add() {
    printf("================== Testing add ==================\n");
    unionfind t = constructor(10);

    printf("------------ Start Test 1 ------------\n");
    add(&t, 1, 1);

    assert(t.array[1].state == OCCUPIED);
    printf("Test passed: t.array[1].state == OCCUPIED\n");
    assert(t.array[1].parent == 1);
    printf("Test passed: t.array[1].parent == 1\n");
    assert(t.num_disjoint_trees == 1);
    printf("Test passed: t.num_disjoint_trees == 1\n");
    assert(t.num_slots == 10);
    printf("Test passed: t.num_slots == 10\n");
    assert(t.num_items == 1);
    printf("Test passed: t.num_items == 1\n");

    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");
    add(&t, 3, 3);
    add(&t, 2, 1);

    assert(t.array[3].state == OCCUPIED);
    printf("Test passed: t.array[3].state == OCCUPIED\n");
    assert(t.array[3].parent == 3);
    printf("Test passed: t.array[3].parent == 3\n");
    assert(t.array[2].state == OCCUPIED);
    printf("Test passed: t.array[2].state == OCCUPIED\n");
    assert(t.array[2].parent == 1);
    printf("Test passed: t.array[2].parent == 1\n");
    assert(t.num_items == 3);
    printf("Test passed: t.num_items == 3\n");
    assert(t.num_slots == 10);
    printf("Test passed: t.num_slots == 10\n");
    assert(t.num_disjoint_trees == 2);
    printf("Test passed: t.num_disjoint_trees == 2\n");

    printf("------------ End Test 2 ------------\n");

    free_helper(&t);
    printf("================== Finished Testing add ==================\n");
    printf("\n");
}

void test_find() {}
void test_join() {}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");
    printf("================== Finished Testing isEmpty ==================\n");
    printf("\n");
}

int main() {
    printf("\n");
    test_constructor();
    test_add();
    test_find();
    test_join();
    test_isEmpty();
}
