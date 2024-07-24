#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct node {
  int item;
  struct node* next;
} node;

typedef struct linkedlist {
  int size;
  node* head;
} linkedlist;

bool isEmpty(linkedlist* l) { return l == NULL; }

void push(linkedlist* l, int item) {
  assert(l != NULL);

  node* newNode;
  newNode->item = item;
  newNode->next = NULL;
  l->size++;

  if (l->head == NULL) {
    l->head = newNode;
    return;
  }

  node* cur = l->head;
  while (cur->next == NULL) {
    cur = cur->next;
  }

  cur->next = newNode;
}

linkedlist constructor() {
  linkedlist l;
  l.size = 0;
  l.head = NULL;
  return l;
}
