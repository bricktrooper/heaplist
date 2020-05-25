#include <stdio.h>
#include <stdlib.h>

#include "heaplist.h"

#define ERROR     -1
#define SUCCESS    0

int main(void)
{
	HeapList * heaplist = newlist();
#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif
	int * array1 = allocate(heaplist, 10 * sizeof(int));
	int * array2 = allocate(heaplist, 10 * sizeof(int));
	int ** array2d = allocate(heaplist, 3 * sizeof(int));
	array2d[0] = allocate(heaplist, 4 * sizeof(int));
	array2d[1] = allocate(heaplist, 4 * sizeof(int));
	array2d[2] = allocate(heaplist, 4 * sizeof(int));

#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif
	deallocate(heaplist, array2d);
#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif
	deallocate(heaplist, array2);
#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif
	deallocate(heaplist, array1);
#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif
	deallocate(heaplist, array2d[2]);
#ifdef HEAPLIST_DEBUG
	heaplist_print(heaplist);
#endif

	freeall(heaplist);
	return SUCCESS;
}
