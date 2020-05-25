#ifndef HEAPLIST_H
#define HEAPLIST_H

#include <stddef.h>

typedef struct HeapList HeapList;

HeapList * newlist(void);
void * allocate(HeapList * list, size_t size);
int deallocate(HeapList * list, void * data);
int freeall(HeapList * list);

#endif /* HEAPLIST_H */
