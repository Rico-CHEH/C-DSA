all: testsArrayList testsLinkedList testsHashMap

testsArrayList: arraylistTest.o arraylist.o
	gcc -Wall -g -o testsArrayList arraylistTest.o arraylist.o

arraylist.o: arraylist.c arraylist.h
	gcc -Wall -g -c arraylist.c

arraylistTest.o: arraylistTest.c arraylist.h
	gcc -Wall -g -c arraylistTest.c

testsLinkedList: linkedListTest.o linkedList.o
	gcc -Wall -g -o testsLinkedList linkedListTest.o linkedList.o

linkedList.o: linkedList.c linkedList.h
	gcc -Wall -g -c linkedList.c

linkedListTest.o: linkedListTest.c linkedList.h
	gcc -Wall -g -c linkedListTest.c

testsHashMap: hashmapTest.o hashmap.o
	gcc -Wall -g -o testsHashMap hashmapTest.o hashmap.o

hashmap.o: hashmap.c hashmap.h
	gcc -Wall -g -c hashmap.c

hashmapTest.o: hashmapTest.c hashmap.h
	gcc -Wall -g -c hashMapTest.c

clean: 
	rm -f tests*.exe *.o
