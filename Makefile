# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable names
EXECUTABLES = testsArrayList testsLinkedList testsHashMap testsDLinkedList testsBst

# Object files
ARRAYLIST_OBJS = arraylistTest.o arraylist.o
LINKEDLIST_OBJS = linkedlistTest.o linkedlist.o
HASHMAP_OBJS = hashmapTest.o hashmap.o
DLINKEDLIST_OBJS = dlinkedlistTest.o dlinkedlist.o
BST_OBJS = bstTest.o bst.o

# Default target
all: $(EXECUTABLES)

# Executable targets
testsArrayList: $(ARRAYLIST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(ARRAYLIST_OBJS)

testsLinkedList: $(LINKEDLIST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(LINKEDLIST_OBJS)

testsHashMap: $(HASHMAP_OBJS)
	$(CC) $(CFLAGS) -o $@ $(HASHMAP_OBJS)

testsDLinkedList: $(DLINKEDLIST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(DLINKEDLIST_OBJS)

testsBst: $(BST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BST_OBJS)

# Generic pattern rule for object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Clean target
clean:
	rm -f $(EXECUTABLES) *.o
