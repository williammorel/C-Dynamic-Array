cc=gcc
CFLAGS=-I.

build: Main.o Functions.o
	$(CC) -o c_linked_lists Main.o Functions.o -I.

clean:
	rm -rf c_linked_lists Main.o Functions.o
