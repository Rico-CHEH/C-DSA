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
  printf("================== Finished Testing constructor ==================\n");
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
  pop(&l, 0);

  printf("------------ Start Test 1 ------------\n");
  assert(l.size == 0);
  printf("Test passed: l.size == 0\n");
  assert(l.array != NULL);
  printf("Test passed: l.array != NULL\n");
  assert(l.array[0] == 69);
  printf("Test passed: l.array[0] == 69\n");
  printf("------------ End Test 1 ------------\n");

  printf("\n");

  for (int i = 0; i < 12; i++) {
    push(&l, i);  // list should be {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
  }
  pop(&l, 7);

  printf("------------ Start Test 2 ------------\n");
  assert(l.size == 11);
  printf("Test passed: l.size == 10\n");
  assert(l.length == 15);
  printf("Test passed: l.length == 15\n");
  assert(l.array != NULL);
  printf("Test passed: l.array != NULL\n");

  for (int i = 0; i < 7; i++) {
    assert(l.array[i] == i);
  } 
  for (int i = 7; i < 11; i++) {
    assert(l.array[i] == i+1);
  } 
  printf("Test passed: l.array == {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11}\n");
  printf("------------ End Test 2 ------------\n");

  free(l.array);
  printf("================== Finished Testing push ==================\n");
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
  test_constructor();
  test_isEmpty();
  test_push();
  test_pop();
  test_get();
  test_resize();

  return 0;
}
