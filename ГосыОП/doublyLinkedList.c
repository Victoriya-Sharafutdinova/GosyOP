#include<stdio.h>


struct Node
{
	int value;
	struct Node* next;
	struct Node* prev;

};

struct List
{
	struct Node* head;
	struct Node* tail;

};

struct List* list;


void addNodeDoubly(int value) {	
	struct Node* current = NULL;
	if (list->tail != NULL)
	{
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

void printDoublyList()
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
void addFirstNodeDoubly(int value)
{
	struct Node* current = NULL;
	if (list->head != NULL)
	{
		current = list->head;
		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head->next = current;
		list->head->prev = NULL;
		list->head->value = value;
		current->prev = list->head;
	}
	else
	{
		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head->next = NULL;
		list->head->prev = NULL;
		list->head->value = value;
		list->tail = list->head;
	}

}

void delLastNodeDoubly()
{
	if (list->tail != NULL) 
	{
		if (list->tail->prev == NULL) 
		{
			list->tail = NULL;
			list->head = NULL;
			return;
		}
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
}

void delFirstNodeDoubly()
{
	if (list->head != NULL)
	{
		if (list->head->next == NULL)
		{
			list->head = NULL;
			list->tail = NULL;
			return;
		}
		list->head = list->head->next;
		list->head->prev = NULL;
	}
}

int lengthDoublyList()
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

void sort()
{
	struct Node* current = NULL;
	struct Node* nextCurrent = NULL;

	int t = 0;
	int flag = 1;
	while (flag == 1)
	{
		current = list->head;
		nextCurrent = current->next;
		flag = 0;
		while (nextCurrent)
		{
			if ((current->value) > (nextCurrent->value))
			{
				t = current->value;
				current->value = nextCurrent->value;
				nextCurrent->value = t;
				flag = 1;
			}
			current = current->next;
			nextCurrent = nextCurrent->next;
		}
	}
}

void addNodeMiddleDoubly(int value)
{
	struct Node* nextCurrent = NULL;
	struct Node* prevCurrent = NULL;
	struct Node* current = NULL;


	if (list->head != NULL) 
	{
		nextCurrent = list->head;
		prevCurrent = list->tail;
		while ((nextCurrent != prevCurrent) && ((nextCurrent->next != prevCurrent)&&(nextCurrent->next!=NULL)))
		{
			nextCurrent = nextCurrent->next;
			prevCurrent = prevCurrent->prev;
		}
		if (nextCurrent == prevCurrent)
		{
			current = (struct Node*)malloc(sizeof(struct Node));
			current->next = prevCurrent->next;
			current->prev = nextCurrent;
			current->value = value;
			nextCurrent->next = current;
			prevCurrent->next->prev = current;
		}
		if (nextCurrent->next == prevCurrent)
		{
			current = (struct Node*)malloc(sizeof(struct Node));
			current->next = prevCurrent;
			current->prev = nextCurrent;
			current->value = value;
			nextCurrent->next = current;
			prevCurrent->prev = current;
		}
		

	}
	else
	{
		list->head = (struct Node*)malloc(sizeof(struct Node));
		list->head->next = NULL;
		list->head->prev = NULL;
		list->head->value = value;
		list->tail = list->head;
	}

}

void search(int value) 
{
	struct Node* current = NULL;
	struct Node* nextCurrent = NULL;

	current = list->head;
	nextCurrent = current->next;
	while (nextCurrent)
	{
		if (current->value == value)
		{
			printf("\n True");
			return;
		}
		current = current->next;
		nextCurrent = nextCurrent->next;
	}
	
	printf("\n False");
}

void initDoubly()
{
	list = (struct List*)malloc(sizeof(struct List));
	list->head = list->tail= NULL;
	addNodeDoubly(54);
	delLastNodeDoubly();

	addNodeDoubly(54);
	addNodeDoubly(72);
	addNodeDoubly(13);

	addFirstNodeDoubly(55);
	addFirstNodeDoubly(2);
	delLastNodeDoubly();
	addNodeDoubly(27);

	delFirstNodeDoubly();
	addNodeDoubly(100);
	addFirstNodeDoubly(355);

	addFirstNodeDoubly(13);
	delLastNodeDoubly();
	sort(); 
	addNodeDoubly(72);
	addNodeDoubly(32);
	addNodeDoubly(45);

	addNodeMiddleDoubly(5);

	printDoublyList();
	printf("List length: %d", lengthDoublyList());

	search(54);


	return 0;
}

