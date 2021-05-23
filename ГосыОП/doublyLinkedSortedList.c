#include <stdio.h>
#include "doublyLinkedSortedList.h"

struct Value 
{
	int id;
	float number;
};

struct Node
{
	struct Value value;
	struct Node* next;
	struct Node* prev;
};

struct List
{
	struct Node* head;
	struct Node* tail;

};

struct List* list;


void addNodeDoublySorted(struct Value value) {
	struct Node* current = NULL;
	if (list->head != NULL)
	{
		current = list->head;
		if (current->value.id >= value.id)
		{
			current = list->head;
			list->head = (struct Node*)malloc(sizeof(struct Node));
			list->head->next = current;
			list->head->prev = NULL;
			list->head->value = value;
			current->prev = list->head;
			return;
		}
		while (current->next != NULL)
		{
			current = current->next;
			if (current->value.id >= value.id)
			{
				struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
				tmp->next = current;
				tmp->prev = current->prev;
				tmp->value = value;
				current->prev = tmp;
				tmp->prev->next = tmp;
				return;
			}
		}
		current = list->tail;
		list->tail = (struct Node*)malloc(sizeof(struct Node));
		list->tail->next = NULL;
		list->tail->prev = current;
		list->tail->value = value;
		current->next = list->tail;
	}
	else
	{
		list->tail = (struct Node*)malloc(sizeof(struct Node));
		list->tail->next = NULL;
		list->tail->prev = NULL;
		list->tail->value = value;
		list->head = list->tail;
	}

}

void printDoublySortedList()
{
	struct Node* current = list->head;

	while (current != NULL)
	{
		printf("%d %f\n", current->value.id, current->value.number);
		current = current->next;
	}
}


void initDoublySorted()
{
	list = (struct List*)malloc(sizeof(struct List));
	list->head = list->tail = NULL;

	struct Value value = { 1, 12.4f };
	addNodeDoublySorted(value);
	value.id = 10;
	addNodeDoublySorted(value);
	value.id = 5;
	addNodeDoublySorted(value);
	value.id = 6;
	addNodeDoublySorted(value);
	value.id = 0;
	addNodeDoublySorted(value);
	printDoublySortedList();
}
