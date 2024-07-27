#include <stdio.h>
#include <assert.h>

#include "hashmap.h"

/*
printf("Test passed:\n");
*/

void test_constructor() {
    printf("================== Testing constructor ==================\n");
    hashmap map = constructor(10);

    assert(map.num_entries == 0);
    printf("Test passed: map.num_entries == 0\n");
    assert(map.num_slots == 10);
    printf("Test passed: map.num_slots == 10\n");
    assert(map.array != NULL);
    printf("Test passed: map.array != NULL\n");
    for (int i = 0; i < 10; ++i) {
        assert(map.array[i].state == EMPTY);
    }
    printf("Test passed: state == EMPTY\n");

    free(map.array);
    printf("================== Finished Testing constructor ==================\n");
    printf("\n");
}

void test_insert() {
    printf("================== Testing insert ==================\n");
    hashmap map = constructor(10);

    printf("------------ Start Test 1 ------------\n");
    insert(&map, 1, 5);       // Should go to index 1
    insert(&map, 2, 5);       // Should go to index 2
    insert(&map, 11, 5);      // Should go to index 3
    insert(&map, -1, 420);    // Should go to index 9
    insert(&map, -2, 69);     // Should go to index 8

    assert(map.num_entries == 5);
    printf("Test passed: map.num_entries == 4\n");
    assert(map.num_slots == 10);
    printf("Test passed: map.num_slots == 10\n");

    assert(map.array[1].key == 1);
    printf("Test passed: map.array[1].key == 1\n");
    assert(map.array[1].value == 5);
    printf("Test passed: map.array[1].value == 5\n");
    assert(map.array[1].state == OCCUPIED);
    printf("Test passed: map.array[1].state == OCCUPIED\n");

    assert(map.array[2].key == 2);
    printf("Test passed: map.array[2].key == 2\n");
    assert(map.array[2].value == 5);
    printf("Test passed: map.array[2].value == 5\n");
    assert(map.array[2].state == OCCUPIED);
    printf("Test passed: map.array[2].state == OCCUPIED\n");

    assert(map.array[3].key == 11);
    printf("Test passed: map.array[3].key == 11\n");
    assert(map.array[3].value == 5);
    printf("Test passed: map.array[3].value == 5\n");
    assert(map.array[3].state == OCCUPIED);
    printf("Test passed: map.array[3].state == OCCUPIED\n");

    assert(map.array[8].key == -2);
    printf("Test passed: map.array[8].key == -2\n");
    assert(map.array[8].value == 69);
    printf("Test passed: map.array[8].value == 69\n");
    assert(map.array[8].state == OCCUPIED);
    printf("Test passed: map.array[8].state == OCCUPIED\n");

    assert(map.array[9].key == -1);
    printf("Test passed: map.array[9].key == -1\n");
    assert(map.array[9].value == 420);
    printf("Test passed: map.array[9].value == 420\n");
    assert(map.array[9].state == OCCUPIED);
    printf("Test passed: map.array[9].state == OCCUPIED\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");
    int value1 = insert(&map, 1, 25);
    int value2 = insert(&map, 11, 25);
    int value3 = insert(&map, -1, 420);

    assert(value1 == 5);
    printf("Test passed: value1 == 5\n");
    assert(map.array[1].key == 1);
    printf("Test passed: map.array[1].key == 1\n");
    assert(map.array[1].value == 25);
    printf("Test passed: map.array[1].value == 25\n");
    assert(map.array[1].state == OCCUPIED);
    printf("Test passed: map.array[1].state == OCCUPIED\n");

    assert(value2 == 5);
    printf("Test passed: value2 == 5\n");
    assert(map.array[3].key == 11);
    printf("Test passed: map.array[3].key == 11\n");
    assert(map.array[3].value == 25);
    printf("Test passed: map.array[3].value == 25\n");
    assert(map.array[3].state == OCCUPIED);
    printf("Test passed: map.array[3].state == OCCUPIED\n");

    assert(value3 == 420);
    printf("Test passed: value3 == 420\n");
    assert(map.array[9].key == -1);
    printf("Test passed: map.array[9].key == -1\n");
    assert(map.array[9].value == 420);
    printf("Test passed: map.array[9].value == 420\n");
    assert(map.array[9].state == OCCUPIED);
    printf("------------ End Test 2 ------------\n");
    printf("\n");

    free(map.array);
    printf("================== Finished Testing insert ==================\n");
    printf("\n");
}

void test_resize(){
    printf("================== Testing resize ==================\n");
    hashmap map = constructor(10);

    insert(&map, 12, 12);
    insert(&map, 11, 11);
    insert(&map, 10, 10);
    insert(&map, 0, 0);
    insert(&map, 3, 3);
    insert(&map, 7, 7);
    insert(&map, 8, 8);
    insert(&map, 15, 15);
    insert(&map, 20, 20);
    insert(&map, 9, 9);

    
    
    printf("------------ Start Test 1 ------------\n");

    assert(map.num_entries = 10);
    assert(map.num_slots = 10);

    assert(map.array[2].key == 12);
    assert(map.array[2].value == 12);
    assert(map.array[2].state == OCCUPIED);

    assert(map.array[1].key == 11);
    assert(map.array[1].value == 11);
    assert(map.array[1].state == OCCUPIED);

    assert(map.array[0].key == 10);
    assert(map.array[0].value == 10);
    assert(map.array[0].state == OCCUPIED);

    assert(map.array[3].key == 0);
    assert(map.array[3].value == 0);
    assert(map.array[3].state == OCCUPIED);

    assert(map.array[4].key == 3);
    assert(map.array[4].value == 3);
    assert(map.array[4].state == OCCUPIED);

    assert(map.array[7].key == 7);
    assert(map.array[7].value == 7);
    assert(map.array[7].state == OCCUPIED);

    assert(map.array[8].key == 8);
    assert(map.array[8].value == 8);
    assert(map.array[8].state == OCCUPIED);

    assert(map.array[5].key == 15);
    assert(map.array[5].value == 15);
    assert(map.array[5].state == OCCUPIED);

    assert(map.array[6].key == 20);
    assert(map.array[6].value == 20);
    assert(map.array[6].state == OCCUPIED);

    assert(map.array[9].key == 9);
    assert(map.array[9].value == 9);
    assert(map.array[9].state == OCCUPIED);

    printf("Test passed: array is {10, 11, 12, 0, 3, 15, 20, 7, 8, 9}\n");
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");
    insert(&map, 1, 1);

    assert(map.num_entries == 11);
    assert(map.num_slots == 15);

    assert(map.array[12].key == 12);
    assert(map.array[12].value == 12);
    assert(map.array[12].state == OCCUPIED);

    assert(map.array[11].key == 11);
    assert(map.array[11].value == 11);
    assert(map.array[11].state == OCCUPIED);

    assert(map.array[10].key == 10);
    assert(map.array[10].value == 10);
    assert(map.array[10].state == OCCUPIED);

    assert(map.array[0].key == 0);
    assert(map.array[0].value == 0);
    assert(map.array[0].state == OCCUPIED);

    assert(map.array[3].key == 3);
    assert(map.array[3].value == 3);
    assert(map.array[3].state == OCCUPIED);

    assert(map.array[7].key == 7);
    assert(map.array[7].value == 7);
    assert(map.array[7].state == OCCUPIED);

    assert(map.array[8].key == 8);
    assert(map.array[8].value == 8);
    assert(map.array[8].state == OCCUPIED);

    assert(map.array[1].key == 15);
    assert(map.array[1].value == 15);
    assert(map.array[1].state == OCCUPIED);

    assert(map.array[5].key == 20);
    assert(map.array[5].value == 20);
    assert(map.array[5].state == OCCUPIED);

    assert(map.array[9].key == 9);
    assert(map.array[9].value == 9);
    assert(map.array[9].state == OCCUPIED);

    assert(map.array[2].key == 1);
    assert(map.array[2].value == 1);
    assert(map.array[2].state == OCCUPIED);

    assert(map.array[2].key == 1);
    assert(map.array[2].value == 1);
    assert(map.array[2].state == OCCUPIED);

    printf("Test passed: array is {0, 15, 1, 3, null, 20, null, 7, 8, 9, 10, 11, 12, null}\n");
    printf("------------ End Test 2 ------------\n");

    free(map.array);
    printf("================== Finished Testing resize ==================\n");
    printf("\n");

}
void test_erase(){
    printf("================== Testing erase ==================\n");
    hashmap map = constructor(10);

    insert(&map, 12, 12);
    insert(&map, 11, 11);
    insert(&map, 10, 10);
    erase(&map, 12);

    printf("------------ Start Test 1 ------------\n");
    assert(map.array[2].key == 12);
    assert(map.array[2].value == 12);
    assert(map.array[2].state == DELETED);

    assert(map.array[1].key == 11);
    assert(map.array[1].value == 11);
    assert(map.array[1].state == DELETED);

    assert(map.array[0].key == 10);
    assert(map.array[0].value == 10);
    assert(map.array[0].state == DELETED);
    printf("------------ End Test 1 ------------\n");
    printf("\n");

    printf("------------ Start Test 2 ------------\n");

    printf("------------ End Test 2 ------------\n");

    printf("================== Finished Testing erase ==================\n");
    printf("\n");
}
void test_search(){}


int main() {
    test_constructor();
    test_insert();
    test_resize();
    test_erase();
    test_search();

    return 0;
}
