CC = gcc

CFLAGS += -Wall
CFLAGS += -Wpedantic
CFLAGS += -std=c99

test: heaplist.o test.c
	$(CC) $(CFLAGS) heaplist.o test.c -o test

heaplist.o: heaplist.c heaplist.h
	$(CC) $(CFLAGS) -c heaplist.c

clean:
	rm -rf *.o test
