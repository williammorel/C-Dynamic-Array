cc=gcc
CFLAGS=-I.

build: test.o test2.o
	$(CC) -o test test.o test2.o -I.
