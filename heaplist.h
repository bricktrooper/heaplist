#ifndef HEAPLIST_H
#define HEAPLIST_H

#define HEAPLIST_ERROR_MSG
// #define HEAPLIST_DEBUG

#include <stddef.h>

typedef struct HeapList HeapList;

HeapList * newlist(void);
void * allocate(HeapList * list, size_t size);
int deallocate(HeapList * list, void * data);
int freeall(HeapList * list);

#ifdef HEAPLIST_DEBUG
int heaplist_print(HeapList * list);
#endif

#endif /* HEAPLIST_H */
