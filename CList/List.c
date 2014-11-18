#include "List.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	/*next node*/
	nodePtr next;
	/*previous node*/
	nodePtr prev;
	/*data pointer*/
	void* data;
} node;

typedef struct List {
	/*list size variable*/
	int size;
	/*first node*/
	nodePtr first;
	/*last node*/
	nodePtr last;
} List;

int createList(ListPtr* list) {
	/*memory allocation for the new list*/
	*list = malloc(sizeof(List));
	if (*list == NULL) {
		perror("Malloc for createList");
		return -1;
	}
	/*variables initialization*/
	(*list)->size = 0;
	(*list)->first = NULL;
	(*list)->last = NULL;
	return 1;
}

int getSizeList(ListPtr list) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	return list->size;
}

int pushFrontList(ListPtr list, void* _data) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	/*memory allocation for the new node*/
	nodePtr temp = malloc(sizeof(node));
	if (temp == NULL) {
		perror("Malloc for insertData : node creation");
		return -1;
	}
	/*prepare node||first->next is always NULL!*/
	temp->data = _data;
	temp->next = NULL;
	if (list->size == 0 && list->first == NULL && list->last == NULL) {
		/*case of empty list*/
		temp->prev = NULL;
		list->first = temp;
		list->last = temp;
	} else {
		/*case of non-empty list*/
		list->first->next = temp;
		temp->prev = list->first;
		list->first = temp;
	}
	list->size = list->size + 1;
	return 1;
}

int pushBackList(ListPtr list, void* _data) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	/*memory allocation for the new node*/
	nodePtr temp = malloc(sizeof(node));
	if (temp == NULL) {
		perror("Malloc for insertData : node creation");
		return -1;
	}
	/*prepare node||last->prev is always NULL!*/
	temp->data = _data;
	temp->prev = NULL;
	if (list->size == 0 && list->first == NULL && list->last == NULL) {
		/*case of empty list*/
		temp->next = NULL;
		list->first = temp;
		list->last = temp;
	} else {
		/*case of non-empty list*/
		list->last->prev = temp;
		temp->next = list->last;
		list->last = temp;
	}
	list->size = list->size + 1;
	return 1;
}

int popFrontList(ListPtr list) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if (list->size == 0) {
		printf("This list is empty!\n");
		return -1;
	}
	list->size = list->size - 1;
	/*temporary pointer for destroying the poped node*/
	nodePtr temp = list->first;
	list->first = list->first->prev;
	free(temp);
	if (list->first != NULL) {
		/*case of non-empty list*/
		list->first->next = NULL;
	} else {
		/*case of empty list*/
		list->last = NULL;
	}
	return 1;
}

int popAndGetFrontList(ListPtr list, void** _data) {
	/*get data from first node*/
	if (getFirstList(list, _data) < 0) {
		return -1;
	}
	/*then pop the first node*/
	if (popFrontList(list) < 0) {
		return -1;
	}
	return 1;
}

int popBackList(ListPtr list) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if (list->size == 0) {
		printf("This list is empty!\n");
		return -1;
	}
	list->size = list->size - 1;
	/*temporary pointer for destroying the poped node*/
	nodePtr temp = list->last;
	list->last = list->last->next;
	free(temp);
	if (list->last != NULL) {
		/*case of non-empty list*/
		list->last->prev = NULL;
	} else {
		/*case of empty list*/
		list->first = NULL;
	}
	return 1;
}

int popAndGetBackList(ListPtr list, void** _data) {
	/*get data from last node*/
	if (getLastList(list, _data) < 0) {
		return -1;
	}
	/*then pop the last node*/
	if (popBackList(list) < 0) {
		return -1;
	}
	return 1;
}

int getFirstList(ListPtr list, void** _data) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if (list->size == 0) {
		printf("This list is empty!\n");
		return -1;
	}
	/*get data*/
	*_data = list->first->data;
	return 1;
}

int getLastList(ListPtr list, void** _data) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if (list->size == 0) {
		printf("This list is empty!\n");
		return -1;
	}
	/*get data*/
	*_data = list->last->data;
	return 1;
}

int destroyList(ListPtr* list) {
	if (*list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if ((*list)->size > 0) {
		printf("This list was not emptied...\n");
		return 0;
	}
	/*memory deallocation*/
	free(*list);
	*list = NULL;
	printf("This list was succesfully destroyed!\n");
	return 1;
}

int invertList(ListPtr list) {
	if (list == NULL) {
		printf("This list is not even created...\n");
		return -1;
	}
	if (list->size == 0) {
		printf("This list is empty!\n");
		return -1;
	}
	/*temp1 is used as an iterator*/
	nodePtr temp1 = list->first;
	/*temp2 is used just as a temporary pointer*/
	nodePtr temp2;
	while (temp1 != NULL) {
		/*alter pointers at each node*/
		temp2 = temp1->prev;
		temp1->prev = temp1->next;
		temp1->next = temp2;
		/*go to the "previous" node*/
		temp1 = temp1->next;
	}
	/*alter list->first with list->last*/
	temp2 = list->first;
	list->first = list->last;
	list->last = temp2;
	return 1;
}
