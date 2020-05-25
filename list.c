#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define ERROR     -1
#define SUCCESS    0

int list_init(List * list)
{
	if (list == NULL)
	{
		printf("[heaplist] %s(): List handle is null\n", __func__);
		return ERROR;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return SUCCESS;
}

int list_is_empty(List * list)
{
	if (list == NULL)
	{
		printf("[heaplist] %s(): List handle is null\n", __func__);
		return ERROR;
	}

	return (list->size == 0 && list->head == NULL && list->tail == NULL);
}

int list_append(List * list, void * data)
{
	if (data == NULL)
	{
		printf("[heaplist] %s(): Data handle is null\n", __func__);
		return ERROR;
	}

	Node * node = malloc(sizeof(Node));

	if (node == NULL)
	{
		printf("[heaplist] %s(): Failed to allocate memory for data node\n", __func__);
		return ERROR;
	}

	node->data = data;
	node->next = NULL;

	if (list_is_empty(list))
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

int list_remove(List * list, void * data)
{
	if (list_is_empty(list))
	{
		printf("[heaplist] %s(): List is empty\n", __func__);
		return ERROR;
	}

	if (data == NULL)
	{
		printf("[heaplist] %s(): Data handle is null\n", __func__);
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
	}

	return ERROR;
}

int list_clear(List * list)
{
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

int list_print(List * list)
{
	if (list_is_empty(list))
	{
		printf("[heaplist] %s(): List is empty\n", __func__);
		return SUCCESS;
	}

	Node * current = list->head;

	while (current != NULL)
	{
		printf("[heaplist] %s(): ------- LIST -------\n", __func__);
		printf("[heaplist] %s(): %p\n", __func__, current->data);
		printf("[heaplist] %s(): --------------------\n", __func__);
		current = current->next;
	}

	return SUCCESS;
}
