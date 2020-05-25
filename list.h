#ifndef LIST_H
#define LIST_H

typedef struct Node
{
	void * data;
	struct Node * next;
} Node;

typedef struct List
{
	struct Node * head;
	struct Node * tail;
	int size;
} List;

int list_init(List * list);
int list_is_empty(List * list);
int list_append(List * list, void * data);
int list_remove(List * list, void * data);
int list_clear(List * list);
int list_print(List * list);

#endif /* LIST_H */
