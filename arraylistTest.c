#include <assert.h>
#include <stdio.h>

#include "arraylist.h"

typedef struct dataNode {
    int item;
} dataNode;


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

    dataNode a = {.item = 1};
    push(&l, &a);
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

    dataNode a = {.item = 69};
    push(&l, &a);

    assert(l.size == 1);
    printf("Test passed: l.size == 1\n");
    assert(l.length == 10);
    printf("Test passed: l.length == 10\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert((dataNode *)l.array[0].item == &a);
    printf("Test passed: (dataNode*) l.array[0].item == &a\n");
    assert(((dataNode *)l.array[0].item)->item == 69);
    printf("Test passed: ((dataNode*) l.array[0].item)->item == 69\n");

    free(l.array);
    printf("================== Finished Testing push ==================\n");
    printf("\n");
}

void test_pop() {
    printf("================== Testing pop ==================\n");
    arraylist l = constructor(10);

    dataNode a = {.item = 69};
    push(&l, &a);
    int old = ((dataNode *)pop(&l))->item;

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(old == 69);
    printf("Test passed:old == 69\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    dataNode data1 = {.item = 69};
    dataNode data2 = {.item = 67};
    dataNode data3 = {.item = 64};
    dataNode data4 = {.item = 61};

    push(&l, &data1);
    push(&l, &data2);
    push(&l, &data3);
    push(&l, &data4);
    old = ((dataNode *)pop(&l))->item;

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

    dataNode data1 = {.item = 1};
    dataNode data2 = {.item = 2};
    dataNode data3 = {.item = 3};
    dataNode data4 = {.item = 4};
    dataNode insertData = {.item = 420};

    push(&l, &data1);
    push(&l, &data2);
    push(&l, &data3);
    push(&l, &data4);
    insert(&l, insertIndex, &insertData);

    assert(l.size == 5);
    printf("Test passed: l.size == 5\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    int offset = 1;
    for (int i = 0; i < 5; i++) {
        if (i == insertIndex) {
            assert(((dataNode *)l.array[i].item)->item == 420);
            offset = 0;
            continue;
        }
        assert(((dataNode *)l.array[i].item)->item == i + offset);
    }
    printf("Test passed: l.array = {1,2,420,3,4}\n");

    free(l.array);
    printf("================== Finished Testing insert ==================\n");
    printf("\n");
}

void test_erase() {
    printf("================== Testing erase ==================\n");
    arraylist l = constructor(10);

    dataNode data = {.item = 69};
    push(&l, &data);
    int old = ((dataNode *)erase(&l, 0))->item;

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(old == 69);
    printf("Test passed:old == 69\n");
    printf("------------ End Test 1 ------------\n");

    printf("\n");

    dataNode *p_data = (dataNode *) malloc(12 * sizeof(dataNode));
    for (int i = 0; i < 12; i++) {
        p_data[i] = (dataNode) {.item = i};
        push(&l, p_data + i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }
    old = ((dataNode *)erase(&l, 7))->item;

    printf("------------ Start Test 2 ------------\n");
    assert(l.size == 11);
    printf("Test passed: l.size == 11\n");
    assert(l.length == 15);
    printf("Test passed: l.length == 15\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    printf("old=%d\n",old);
    assert(old == 7);
    printf("Test passed: old == 7\n");

    for (int i = 0; i < 7; i++) {
        assert(((dataNode *)l.array[i].item)->item == i);
    }
    for (int i = 7; i < 11; i++) {
        assert(((dataNode *)l.array[i].item)->item == i + 1);
    }
    printf("Test passed: l.array == {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11}\n");
    printf("------------ End Test 2 ------------\n");

    free(p_data);
    free(l.array);
    printf("================== Finished Testing erase ==================\n");
    printf("\n");
}

void test_set() {
    printf("================== Testing set ==================\n");
    arraylist l = constructor(10);

    dataNode *p_data = (dataNode *) malloc(12 * sizeof(dataNode));
    for (int i = 0; i < 12; i++) {
        p_data[i] = (dataNode) {.item = i};
        push(&l, p_data + i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }
    dataNode setter1 = {.item = 420};
    dataNode setter2 = {.item = -1};
    dataNode setter3 = {.item = 69};
    set(&l, 0, &setter1);
    set(&l, 7, &setter2);
    set(&l, 11, &setter3);

    for (int i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                assert(((dataNode *)l.array[i].item)->item == 420);
                break;
            case 7:
                assert(((dataNode *)l.array[i].item)->item == -1);
                break;
            case 11:
                assert(((dataNode *)l.array[i].item)->item == 69);
                break;
            default:
                assert(((dataNode *)l.array[i].item)->item == i);
        }
    }
    printf("Test passed: {420, 1, 2, 3, 4, 5, 6, -1, 8, 9, 10, 69}\n");

    free(p_data);
    free(l.array);
    printf("================== Finished Testing set ==================\n");
    printf("\n");
}

void test_get() {
    printf("================== Testing get ==================\n");
    arraylist l = constructor(10);

    dataNode *p_data = (dataNode *) malloc(12 * sizeof(dataNode));
    for (int i = 0; i < 12; i++) {
        p_data[i] = (dataNode) {.item = i};
        push(&l, p_data + i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }

    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");
    assert(((dataNode *)get(&l, 0))->item == 0);
    printf("Test passed: ((dataNode*)get(&l, 0))->item == 0\n");
    assert(((dataNode *)get(&l, 11))->item == 11);
    printf("Test passed: ((dataNode*)get(&l, 11))->item == 11\n");
    assert(((dataNode *)get(&l, 7))->item == 7);
    printf("Test passed: ((dataNode*)get(&l, 7))->item == 7\n");

    free(p_data);
    free(l.array);
    printf("================== Finished Testing get ==================\n");
    printf("\n");
}

void test_resize() {
    printf("================== Testing resize ==================\n");
    arraylist l = constructor(10);

    dataNode *p_data = (dataNode *) malloc(12 * sizeof(dataNode));
    for (int i = 0; i < 12; i++) {
        p_data[i] = (dataNode) {.item = i};
        push(&l, p_data + i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }

    assert(l.size == 12);
    printf("Test passed: l.size == 12\n");
    assert(l.length == 15);
    printf("Test passed: l.length == 15\n");
    assert(l.array != NULL);
    printf("Test passed: l.array != NULL\n");

    for (int i = 0; i < 12; i++) {
        assert(((dataNode *)l.array[i].item)->item == i);
    }
    printf("Test passed: l.array == {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}\n");

    free(p_data);
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
