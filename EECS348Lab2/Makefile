# This is a comment line
CC=gcc
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall
OBJFILES= 

all: prog

prog: main.c isEven.c isEven.h 
	$(CC) main.c isEven.c isEven.h -o prog

main.o: main.c
	$(CC) $(CFLAGS) main.c

isEven.o: isEven.c
	$(CC) $(CFLAGS) isEven.c

clean:
	rm -rf *.o