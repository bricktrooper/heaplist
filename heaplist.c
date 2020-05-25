#include <stdio.h>
#include <stdlib.h>

#include "heaplist.h"

#define ERROR     -1
#define SUCCESS    0

typedef struct Node
{
	void * data;
	struct Node * next;
} Node;

struct HeapList
{
	struct Node * head;
	struct Node * tail;
	int size;
};

static int heaplist_init(HeapList * list);
static int heaplist_is_empty(HeapList * list);
static int heaplist_append(HeapList * list, void * data);
static int heaplist_remove(HeapList * list, void * data);
static int heaplist_clear(HeapList * list);

HeapList * newlist(void)
{
	HeapList * list = malloc(sizeof(HeapList));

	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Failed to allocate memory for list\n", __func__);
#endif
		return NULL;
	}

	heaplist_init(list);
	return list;
}

void * allocate(HeapList * list, size_t size)
{
	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return NULL;
	}

	void * data = malloc(size);

	if (data == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Failed to allocate memory for data\n", __func__);
#endif
		return NULL;
	}

	if (heaplist_append(list, data) == ERROR)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Failed to add data to list\n", __func__);
#endif
		free(data);
		return NULL;
	}

	return data;
}

int deallocate(HeapList * list, void * data)
{
	if (data == NULL)
	{
		return SUCCESS;
	}

	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return ERROR;
	}

	if (heaplist_remove(list, data) == ERROR)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Failed to remove data from list\n", __func__);
#endif
		return ERROR;
	}

	return SUCCESS;
}

int freeall(HeapList * list)
{
	if (list == NULL)
	{
		return SUCCESS;
	}

	heaplist_clear(list);
	free(list);
	list = NULL;
	return SUCCESS;
}

static int heaplist_init(HeapList * list)
{
	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return ERROR;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return SUCCESS;
}

static int heaplist_is_empty(HeapList * list)
{
	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return ERROR;
	}

	return (list->size == 0 || list->head == NULL || list->tail == NULL);
}

static int heaplist_append(HeapList * list, void * data)
{
	if (data == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Data handle is null\n", __func__);
#endif
		return ERROR;
	}

	Node * node = malloc(sizeof(Node));

	if (node == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Failed to allocate memory for data node\n", __func__);
#endif
		return ERROR;
	}

	node->data = data;
	node->next = NULL;

	if (heaplist_is_empty(list))
	{
		list->head = node;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	(list->size)++;
	return SUCCESS;
}

static int heaplist_remove(HeapList * list, void * data)
{
	if (heaplist_is_empty(list))
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List is empty\n", __func__);
#endif
		return ERROR;
	}

	if (data == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): Data handle is null\n", __func__);
#endif
		return ERROR;
	}

	Node * target = NULL;

	if (list->head->data == data)
	{
		target = list->head;
		list->head = list->head->next;
		(list->size)--;
		free(target->data);
		free(target);
		return SUCCESS;
	}

	Node * current = list->head;

	while (current->next != NULL)
	{
		if (current->next->data == data)
		{
			target = current->next;
			current->next = current->next->next;
			(list->size)--;
			free(target->data);
			free(target);
			return SUCCESS;
		}

		current = current->next;
	}

#ifdef HEAPLIST_ERROR_MSG
	printf("%s(): Data entry '%p' not found\n", __func__, data);
#endif
	return ERROR;
}

static int heaplist_clear(HeapList * list)
{
	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return ERROR;
	}

	Node * current = list->head;
	Node * target = list->head;

	while (current != NULL)
	{
		target = current;
		current = current->next;
		free(target->data);
		free(target);
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return SUCCESS;
}

#ifdef HEAPLIST_DEBUG
int heaplist_print(HeapList * list)
{
	if (list == NULL)
	{
#ifdef HEAPLIST_ERROR_MSG
		printf("%s(): List handle is null\n", __func__);
#endif
		return ERROR;
	}

	if (heaplist_is_empty(list))
	{
		printf("%s(): ----- HEAPLIST -----\n", __func__);
		printf("%s(): Size: %13d\n", __func__, list->size);
		printf("%s(): --------------------\n", __func__);
		printf("%s(): EMPTY\n", __func__);
		printf("%s(): --------------------\n", __func__);
		return SUCCESS;
	}

	Node * current = list->head;

	printf("%s(): ----- HEAPLIST -----\n", __func__);
	printf("%s(): Size: %13d\n", __func__, list->size);
	printf("%s(): --------------------\n", __func__);

	while (current != NULL)
	{
		printf("%s(): %p\n", __func__, current->data);
		current = current->next;
	}

	printf("%s(): --------------------\n", __func__);
	return SUCCESS;
}
#endif
