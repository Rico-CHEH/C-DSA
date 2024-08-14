# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable names
EXECUTABLES = testsArrayList testsLinkedList testsHashMap testsDLinkedList testsBst testsUnionFind

# Object files
ARRAYLIST_OBJS = ./lists/arraylistTest.o ./lists/arraylist.o
LINKEDLIST_OBJS = ./lists/linkedlistTest.o ./lists/linkedlist.o
HASHMAP_OBJS = ./maps/hashmapTest.o ./maps/hashmap.o
DLINKEDLIST_OBJS = ./lists/dlinkedlistTest.o ./lists/dlinkedlist.o
BST_OBJS = ./trees/bstTest.o ./trees/bst.o
UNIONFIND_OBJS = ./trees/unionfindTest.o ./trees/unionfind.o
ALL =  ./lists/arraylistTest.o ./lists/arraylist.o ./lists/linkedlistTest.o ./lists/linkedlist.o ./maps/hashmapTest.o ./maps/hashmap.o ./lists/dlinkedlistTest.o ./lists/dlinkedlist.o ./trees/bstTest.o ./trees/bst.o

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

testsUnionFind: $(UNIONFIND_OBJS)
	$(CC) $(CFLAGS) -o $@ $(UNIONFIND_OBJS)

# Generic pattern rule for object files
$(ALL): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f *.exe lists/*.o maps/*.o trees/*.o
