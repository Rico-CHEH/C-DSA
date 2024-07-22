all: tests

tests: arraylistTest.o arraylist.o
	gcc -Wall -g -o tests arraylistTest.o arraylist.o

arraylist.o: arraylist.c arraylist.h
	gcc -Wall -g -c arraylist.c

arraylistTest.o: arraylistTest.c arraylist.h
	gcc -Wall -g -c arraylistTest.c

clean: 
	rm -f tests arraylist.o arraylistTest.o

