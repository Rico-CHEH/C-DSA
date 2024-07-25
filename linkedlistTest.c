#include <assert.h>
#include <stdio.h>

#include "linkedlist.h"

void free_helper(linkedlist *l) {
    node *cur = l->head, *removeNode = l->head;
    l->head = NULL;
    for (int i = 0; i < l->size; i++) {
        cur = cur->next;
        removeNode->next = NULL;
        free(removeNode);
        removeNode = cur;
    }
}

void test_constructor() {
    printf("================== Testing constructor ==================\n");
    linkedlist l = constructor();

    assert(l.head == NULL);
    printf("Test passed: l.head == NULL\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");

    printf(
        "================== Finished Testing constructor ==================\n");
    printf("\n");
}

void test_isEmpty() {
    printf("================== Testing isEmpty ==================\n");
    linkedlist l = constructor();

    printf("------------ Start Test 1 ------------\n");
    assert(l.head == NULL);
    printf("Test passed: l.head == NULL\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(isEmpty(&l));
    printf("Test passed: isEmpty(&l)\n");
    printf("------------ Start Test 1 ------------\n");
    printf("\n");

    push(&l, 1);
    printf("------------ Start Test 2 ------------\n");
    assert(l.head != NULL);
    printf("Test passed: l.head != NULL\n");
    assert(l.size == 1);
    printf("Test passed: l.size == 1\n");
    assert(!isEmpty(&l));
    printf("Test passed: !isEmpty(&l)\n");
    printf("------------ Start Test 2 ------------\n");

    free(l.head);
    printf("================== Finished Testing isEmpty ==================\n");
    printf("\n");
}

void test_push() {
    printf("================== Testing push ==================\n");
    linkedlist l = constructor();
    push(&l, 69);

    assert(l.size == 1);
    printf("Test passed: l.size == 1\n");
    assert(l.head != NULL);
    printf("Test passed: l.head != NULL\n");
    assert(l.head->item == 69);
    printf("Test passed: l.head->item == 69\n");
    assert(l.head->next == NULL);
    printf("Test passed: l.head->next == NULL\n");

    free(l.head);
    printf("================== Finished Testing push ==================\n");
    printf("\n");
}

void test_pop() {
    printf("================== Testing pop ==================\n");
    linkedlist l = constructor();
    push(&l, 69);
    int old = pop(&l);

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(old == 69);
    printf("Test passed:old == 69\n");
    assert(l.head == NULL);
    printf("Test passed: l.head == NULL\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    push(&l, 69);
    push(&l, 68);
    push(&l, 67);
    push(&l, 61);
    old = pop(&l);

    printf("------------ Start Test 2 ------------\n");
    assert(l.size == 3);
    printf("Test passed: l.size == 3\n");
    node *cur = l.head;
    for (int i = 0; i < 3; i++) {
        assert(cur->item == 69 - i);
        cur = cur->next;
    }
    printf("Test passed: list == {69, 68, 67}\n");
    assert(cur == NULL);
    printf("Test passed: last == NULL\n");
    assert(old == 61);
    printf("Test passed:old == 61\n");
    printf("------------ End Test 2 ------------\n");

    free_helper(&l);
    printf("================== Finished Testing pop ==================\n");
    printf("\n");
}

void test_insert() {
    printf("================== Testing insert ==================\n");
    linkedlist l = constructor();
    int insertIndex = 2;
    push(&l, 1);  // {1,2,3,4}
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    insert(&l, insertIndex, 420);

    assert(l.size == 5);
    printf("Test passed: l.size == 5\n");
    assert(l.head != NULL);
    printf("Test passed: l.head != NULL\n");
    int offset = 1;
    node *cur = l.head;
    for (int i = 0; i < 5; i++) {
        if (i == insertIndex) {
            assert(cur->item == 420);
            offset = 0;
        } else {
            assert(cur->item == i + offset);
        }
        cur = cur->next;
    }
    printf("Test passed: list = {1,2,420,3,4}\n");
    free_helper(&l);
    printf("================== Finished Testing insert ==================\n");
    printf("\n");
}

void test_erase() {
    printf("================== Testing erase ==================\n");
    linkedlist l = constructor();
    push(&l, 69);
    int old = erase(&l, 0);

    printf("------------ Start Test 1 ------------\n");
    assert(l.size == 0);
    printf("Test passed: l.size == 0\n");
    assert(l.head == NULL);
    printf("Test passed: l.head == NULL\n");
    assert(old == 69);
    printf("Test passed: old == 69\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    for (int i = 0; i < 12; i++) {
        push(&l, i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    }
    old = erase(&l, 7);

    printf("------------ Start Test 2 ------------\n");
    assert(l.size == 11);
    printf("Test passed: l.size == 11\n");
    assert(l.head != NULL);
    printf("Test passed: l.head != NULL\n");
    assert(old == 7);
    printf("Test passed: old == 7\n");

    node *cur = l.head;
    for (int i = 0; i < 7; i++) {
        assert(cur->item == i);
        cur = cur->next;
    }
    for (int i = 7; i < 11; i++) {
        assert(cur->item == i + 1);
        cur = cur->next;
    }
    printf("Test passed: list == {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11}\n");
    printf("------------ End Test 2 ------------\n");

    free_helper(&l);
    printf("================== Finished Testing erase ==================\n");
    printf("\n");
}

void test_set() {
    printf("================== Testing set ==================\n");
    linkedlist l = constructor();

    for (int i = 0; i < 12; i++) {
        push(&l, i);
    }
    set(&l, 0, 420);
    set(&l, 7, -1);
    set(&l, 11, 69);

    node *cur = l.head;
    for (int i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                assert(cur->item == 420);
                break;
            case 7:
                assert(cur->item == -1);
                break;
            case 11:
                assert(cur->item == 69);
                break;
            default:
                assert(cur->item == i);
        }
        cur = cur->next;
    }
    printf("Test passed: {420, 1, 2, 3, 4, 5, 6, -1, 8, 9, 10, 69}\n");

    free_helper(&l);
    printf("================== Finished Testing set ==================\n");
    printf("\n");
}

void test_get() {
    printf("================== Testing get ==================\n");
    linkedlist l = constructor();

    for (int i = 0; i < 12; i++) {
        push(&l, i);
    }

    assert(l.head != NULL);
    printf("Test passed: l.head != NULL\n");
    assert(get(&l, 0) == 0);
    printf("Test passed: get(&l, 0) == 0\n");
    assert(get(&l, 11) == 11);
    printf("Test passed: get(&l, 11) == 11\n");
    assert(get(&l, 7) == 7);
    printf("Test passed: get(&l, 7) == 7\n");

    free_helper(&l);
    printf("================== Finished Testing get ==================\n");
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
}
