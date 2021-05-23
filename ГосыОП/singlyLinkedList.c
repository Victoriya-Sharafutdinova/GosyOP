// ГосыОП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<stdio.h>



struct Node
{
	int value;
	struct Node* next;
};

struct List
{
	struct Node* head;
};

struct List* list;


void addNode(int value) {
	struct Node* current = NULL;
	 if (list->head != NULL)
	 {
		 current = list->head;
	 }
	 else 
	 {
		 list->head = (struct Node*)malloc(sizeof(struct Node));
		 list->head->value = value;
		 list->head->next = NULL;
		 return;
	 }
	
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (struct Node*)malloc(sizeof(struct Node));
	current->next->value = value;
	current->next->next = NULL;
}

void printList() 
{
	struct Node* current = list->head;

	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

// Получение длины списка

// Удаление последнего элемента списка

// Удаление первого элемента списка


// Добавление первого элемента списка
void addFirstNode(int value)
{
	struct Node* current = NULL;
	if (list->head != NULL)
	{
		current = list->head;
		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head->next = current;
		list->head->value = value;

	}
	else
	{
		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head->next = NULL;
		list->head->value = value;
	}

}

void delLastNode()
{
	struct Node* current = NULL;
	struct Node* last = NULL;
	if (list->head != NULL)
	{
		current = list->head;
		if (current->next == NULL) 
		{
			list->head = NULL;
			return;
		}
		while (current->next != NULL)
		{
			last = current;
			current = current->next;
		}
		last->next = NULL;
	}
}

void delFirstNode()
{
	struct Node* current = NULL;
	struct Node* last = NULL;
	if (list->head != NULL)
	{
		if (list->head->next == NULL) 
		{
			list->head = NULL;
			return;
		}
		list->head = list->head->next;
	}
}

int lengthList()
{
	struct Node* current = NULL;
	int length = 0;
	if (list->head != NULL)
	{
		current = list->head;
		length++;
	}
	else
	{
		return length;
	}

	while (current->next != NULL)
	{
		current = current->next;
		length++;
	}
	return length;
}

void init()
{
	list = (struct List*)malloc(sizeof(struct List));
	list->head = NULL;
	addNode(54);
	delLastNode();

	addNode(54);
	addNode(72);
	addNode(13);
	addFirstNode(2);
	addFirstNode(55);
	delLastNode();
	delFirstNode();

	printList();
	printf("List length: %d", lengthList());
	return 0;
}

