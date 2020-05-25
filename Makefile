CC = gcc

CFLAGS += -Wall
CFLAGS += -Wpedantic
CFLAGS += -std=c99

heaplist.o: heaplist.c heaplist.h
	@echo CC heaplist.c
	@$(CC) $(CFLAGS) -c heaplist.c

test.o: test.c heaplist.h
	@echo CC test.c
	@$(CC) $(CFLAGS) -c test.c

test: heaplist.o test.o
	@echo LD heaplist.o
	@echo LD test.o
	@$(CC) $(CFLAGS) heaplist.o test.c -o test

clean:
	@echo RM heaplist.o
	@echo RM test.o
	@echo RM test
	@rm -rf *.o test
