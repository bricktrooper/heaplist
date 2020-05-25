#include <stdio.h>
#include <stdlib.h>

#include "heaplist.h"

#define ERROR     -1
#define SUCCESS    0

int main(void)
{
	HeapList * heaplist = newlist();
	heaplist_print(heaplist);
	int * array1 = allocate(heaplist, 10 * sizeof(int));
	int * array2 = allocate(heaplist, 10 * sizeof(int));
	int ** array2d = allocate(heaplist, 3 * sizeof(int));
	array2d[0] = allocate(heaplist, 4 * sizeof(int));
	array2d[1] = allocate(heaplist, 4 * sizeof(int));
	array2d[2] = allocate(heaplist, 4 * sizeof(int));

	heaplist_print(heaplist);
	deallocate(heaplist, array2d);
	heaplist_print(heaplist);
	deallocate(heaplist, array2);
	heaplist_print(heaplist);
	deallocate(heaplist, array1);
	heaplist_print(heaplist);
	deallocate(heaplist, array2d[2]);
	heaplist_print(heaplist);

	freeall(heaplist);

	return SUCCESS;
}
