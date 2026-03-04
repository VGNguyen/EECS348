# CC=gcc

# main: main.o isEven.o 
# 	$(CC) main.o isEven.o -o main

# main.o: main.c
# 	$(CC) main.c

#isEven.o: isEven.c
# 	$(CC) isEven.c

main.o: isEven.c isOdd.c main.c 
	gcc isEven.c isOdd.c main.c -o main.o

clean:
	rm -rf *.o 