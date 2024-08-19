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

void test_find() {
    printf("================== Testing find ==================\n");
    unionfind t = constructor(10);
    add(&t, 1, 1);
    add(&t, 3, 3);
    add(&t, 2, 1);
    add(&t, 4, 2);
    add(&t, 8, 4);
    add(&t, 6, 8);

    assert(find(&t, 1) == 1);
    printf("Test passed: &t, 1\n");
    assert(find(&t, 3) == 3);
    printf("Test passed: find(&t, 3) == 3\n");
    assert(find(&t, 4) == 1);
    printf("Test passed: find(&t, 4) == 1\n");
    assert(t.array[4].parent == 1);
    printf("Test passed: t.array[4].parent == 1\n");
    assert(find(&t, 6) == 1);
    printf("Test passed: find(&t, 6) == 1\n");
    assert(t.array[6].parent == 1);
    printf("Test passed: t.array[6].parent == 1\n");
    assert(t.array[8].parent == 1);
    printf("Test passed: t.array[8].parent == 1\n");

    free_helper(&t);
    printf("================== Finished Testing find ==================\n");
    printf("\n");
}

void test_join() {
    printf("================== Testing join ==================\n");
    unionfind t = constructor(10);
    add(&t, 1, 1);  //  1 <-- 2 <-- 4 <-- 8 <-- 6
    add(&t, 9, 9);  //  9 <-- 5
    add(&t, 5, 9);  //  ^-- 7 <-- 0
    add(&t, 7, 9);
    add(&t, 0, 7);
    add(&t, 2, 1);  // 1 <-- 2
    add(&t, 4, 2);  // ^-- 4 <-- 8 <-- 6
    add(&t, 8, 4);  // ^-- 9 <-- 5
    add(&t, 6, 8);  //     ^-- 7
    //                     ^-- 0

    join(&t, 0, 4);
    assert(t.array[2].parent == 1);
    printf("Test passed: t.array[2].parent == 1\n");
    assert(t.array[4].parent == 1);
    printf("Test passed: t.array[4].parent == 1\n");
    assert(t.array[9].parent == 1);
    printf("Test passed: t.array[9].parent == 1\n");
    assert(t.array[7].parent == 9);
    printf("Test passed: t.array[7].parent == 9\n");
    assert(t.array[0].parent == 9);
    printf("Test passed: t.array[0].parent == 9\n");
    assert(t.num_disjoint_trees == 1);
    printf("Test passed: t.num_disjoint_trees == 1\n");

    free_helper(&t);
    printf("================== Finished Testing join ==================\n");
    printf("\n");
}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");
    unionfind t = constructor(10);

    assert(isEmpty(&t) == true);
    printf("Test passed: isEmpty(&t) == true\n");
    add(&t, 2, 2);
    assert(isEmpty(&t) == false);
    printf("Test passed: isEmpty(&t) == false\n");

    free_helper(&t);
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
