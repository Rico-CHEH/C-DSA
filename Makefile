all: testsArrayList testsLinkedList

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

clean: 
	rm -f testsLinkedList.exe testsArrayList.exe  *.o
