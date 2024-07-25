#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = newNode;
}

int pop(linkedlist* l) {
  assert(l != NULL);
  assert(l->size >= 0);

  int result;

  node* cur = l->head;
  while (cur->next != NULL && cur->next->next != NULL) {
    cur = cur->next;
  }
  if (cur->next == NULL) {
    result = cur->item;
    free(cur);
    l->head = NULL;
  } else {
    result = cur->item;
    free(cur->next);
    cur->next = NULL;
  }
  
  return result;
}

void insert(linkedlist *l, int index, int item) {

}

int erase(linkedlist *l, int index) {
  return ;
}

int get(linkedlist* l, int index) {
  assert(l != NULL);
  assert(l->size >= 0);
  assert(l->size > index);

  node *cur = l->head;
  for (int i = 0; i < index; i++) {
    cur = cur->next;
  }
  return cur->item;
}

void set(linkedlist* l, int index, int item) {
  assert(l != NULL);
  assert(l->size >= 0);
  assert(l->size > index);

  node *cur = l->head;
  for (int i = 0; i < index; i++) {
    cur = cur->next;
  }
  cur->item = item;
}

linkedlist constructor() {
  linkedlist l;
  l.size = 0;
  l.head = NULL;
  return l;
}
