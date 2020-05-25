#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
	List list;
	list_init(&list);
	list_print(&list);

	int * data1 = malloc(10 * sizeof(int));
	int * data2 = malloc(21 * sizeof(int));
	int * data3 = malloc(54 * sizeof(int));

	if (data1 == NULL || data2 == NULL || data3 == NULL)
	{
		printf("list-test: Failed to allocate test memory\n");
		list_clear(&list);
	}

	list_append(&list, data1);
	list_append(&list, data2);
	list_append(&list, data3);
	list_print(&list);

	list_clear(&list);
	return 0;
}
