#include <assert.h>
#include <stdio.h>

#include "arraylist.h"

void test_constructor() {
    printf("================== Testing constructor ==================\n");
    arraylist l = constructor(10);

    assert(l.size == 0);

    printf("Test passed: l.size == 0\n");
    assert(l.length == 10);
    printf("Test passed: l.length == 10\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");

    free(l.array);
    printf(
        "================== Finished Testing constructor ==================\n");
    printf("\n");
}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");
    arraylist l = constructor(10);

    printf("------------ Start Test 1 ------------\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(isEmpty(&l));
    printf("Test passed: isEmpty(&l)\n");
    printf("------------ Start Test 1 ------------\n");
    printf("\n");

    push(&l, 1);
    printf("------------ Start Test 2 ------------\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(l.size == 1);
    printf("Test passed: l.size == 1\n");
    assert(!isEmpty(&l));
    printf("Test passed: !isEmpty(&l)\n");
    printf("------------ Start Test 2 ------------\n");

    free(l.array);
    printf("================== Finished Testing resize ==================\n");
    printf("\n");
}

void test_push() {
    printf("================== Testing push ==================\n");
    arraylist l = constructor(10);
    push(&l, 69);

    assert(l.size == 1);
    printf("Test passed: l.size == 1\n");
    assert(l.length == 10);
    printf("Test passed: l.length == 10\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(l.array[0] == 69);
    printf("Test passed: l.array[0] == 69\n");

    free(l.array);
    printf("================== Finished Testing push ==================\n");
    printf("\n");
}

void test_pop() {
    printf("================== Testing pop ==================\n");
    arraylist l = constructor(10);
    push(&l, 69);
    int old = pop(&l);

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(old == 69);
    printf("Test passed:old == 69\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    push(&l, 69);
    push(&l, 67);
    push(&l, 64);
    push(&l, 61);
    old = pop(&l);

    printf("------------ Start Test 2 ------------\n");
    assert(l.size == 3);
    printf("Test passed: l.size == 3\n");
    assert(old == 61);
    printf("Test passed:old == 61\n");
    printf("------------ End Test 2 ------------\n");
    free(l.array);
    printf("================== Finished Testing pop ==================\n");
    printf("\n");
}

void test_insert() {
    printf("================== Testing insert ==================\n");
    arraylist l = constructor(10);
    int insertIndex = 2;
    push(&l, 1);  // {1,2,3,4}
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    insert(&l, insertIndex, 420);

    assert(l.size == 5);
    printf("Test passed: l.size == 5\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    int offset = 1;
    for (int i = 0; i < 5; i++) {
        if (i == insertIndex) {
            assert(l.array[i] == 420);
            offset = 0;
            continue;
        }
        assert(l.array[i] == i + offset);
    }
    printf("Test passed: l.array = {1,2,420,3,4}\n");
    free(l.array);
    printf("================== Finished Testing insert ==================\n");
    printf("\n");
}

void test_erase() {
    printf("================== Testing erase ==================\n");
    arraylist l = constructor(10);
    push(&l, 69);
    int old = erase(&l, 0);

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(old == 69);
    printf("Test passed:old == 69\n");
    printf("------------ End Test 1 ------------\n");

    printf("\n");

    for (int i = 0; i < 12; i++) {
        push(&l, i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }
    old = erase(&l, 7);

    printf("------------ Start Test 2 ------------\n");
    assert(l.size == 11);
    printf("Test passed: l.size == 11\n");
    assert(l.length == 15);
    printf("Test passed: l.length == 15\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(old == 7);
    printf("Test passed: old == 7\n");

    for (int i = 0; i < 7; i++) {
        assert(l.array[i] == i);
    }
    for (int i = 7; i < 11; i++) {
        assert(l.array[i] == i + 1);
    }
    printf("Test passed: l.array == {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11}\n");
    printf("------------ End Test 2 ------------\n");

    free(l.array);
    printf("================== Finished Testing erase ==================\n");
    printf("\n");
}

void test_set() {
    printf("================== Testing set ==================\n");
    arraylist l = constructor(10);

    for (int i = 0; i < 12; i++) {
        push(&l, i);
    }
    set(&l, 0, 420);
    set(&l, 7, -1);
    set(&l, 11, 69);

    for (int i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                assert(l.array[0] == 420);
                break;
            case 7:
                assert(l.array[7] == -1);
                break;
            case 11:
                assert(l.array[11] == 69);
                break;
            default:
                assert(l.array[i] == i);
        }
    }
    printf("Test passed: {420, 1, 2, 3, 4, 5, 6, -1, 8, 9, 10, 69}\n");

    free(l.array);
    printf("================== Finished Testing set ==================\n");
    printf("\n");
}

void test_get() {
    printf("================== Testing get ==================\n");
    arraylist l = constructor(10);

    for (int i = 0; i < 12; i++) {
        push(&l, i);
    }

    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(get(&l, 0) == 0);
    printf("Test passed: get(&l, 0) == 0\n");
    assert(get(&l, 11) == 11);
    printf("Test passed: get(&l, 11) == 11\n");
    assert(get(&l, 7) == 7);
    printf("Test passed: get(&l, 7) == 7\n");

    free(l.array);
    printf("================== Finished Testing get ==================\n");
    printf("\n");
}

void test_resize() {
    printf("================== Testing resize ==================\n");
    arraylist l = constructor(10);

    for (int i = 0; i < 12; i++) {
        push(&l, i);
    }

    assert(l.size == 12);
    printf("Test passed: l.size == 12\n");
    assert(l.length == 15);
    printf("Test passed: l.length == 15\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");

    for (int i = 0; i < 12; i++) {
        assert(l.array[i] == i);
    }
    printf("Test passed: l.array == {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}\n");

    free(l.array);
    printf("================== Finished Testing resize ==================\n");
    printf("\n");
}

int main() {
    printf("\n");
    test_constructor();
    test_isEmpty();
    test_push();
    test_pop();
    test_insert();
    test_erase();
    test_set();
    test_get();
    test_resize();

    return 0;
}
