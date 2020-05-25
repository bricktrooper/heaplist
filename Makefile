CC = gcc

CFLAGS += -Wall
CFLAGS += -Wpedantic
CFLAGS += -std=c99

list-test: list.o list-test.o
	$(CC) $(CFLAGS) list.o list-test.o -o list-test

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

list-test.o: list-test.c list.h
	$(CC) $(CFLAGS) -c list-test.c

clean:
	rm *.o
