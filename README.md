# Implementations of DSA in C
> But why in C?
> Idk, It's fun

This repo is mainly here to help me better understand ***DSA, C, memory, and those pesky pointers*** ${\tiny \textrm{and Neovim (btw)}}$.

My current goal is to write generic implementations data structures. Here is how I achieved it for now:
```C
typedef struct {
    // The item is set as a void pointer, this way we can
    // make it point to anything.
    void *item;
} node;

typedef struct arraylist {
    int size;    // Number of elements in the list
    int length;  // Actual length of the array
    node *array;
} arraylist;
```
And I would use the data structure as such:
```C
typedef struct data {
    int number;
    char word[50];
} data;

arraylist l = constructor(10);
data my_data = {.number = 42, .word = "ANSWER"};  // FUN FACT: you can initialize a struct like this
push(&l, &my_data);
```
Note:
- It is a little unpractical for now, and it is subject to change since I plan on exploring other ways of implementing generics.
- If you do think something could be improved, do let me know, I truly want to become better at writing C.

Implemented Data Structures:
- [x] Arraylist
- [x] Singly Linkedlist
- [x] Doubly Linkedlist
- [x] HashMap (Only Open Adressing, Without generics)
- [ ] Trees
- [ ] Heaps
