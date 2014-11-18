#ifndef _List_H_
#define _List_H_

typedef struct node* nodePtr;

typedef struct List* ListPtr;

int createList(ListPtr* list);

int getSizeList(ListPtr list);

int pushFrontList(ListPtr list, void* _data);

int pushBackList(ListPtr list, void* _data);

int popFrontList(ListPtr list);

int popAndGetFrontList(ListPtr list, void** _data);

int popBackList(ListPtr list);

int popAndGetBackList(ListPtr list, void** _data);

int getFirstList(ListPtr list, void** _data);

int getLastList(ListPtr list, void** _data);

int destroyList(ListPtr* list);

int invertList(ListPtr list);

#endif
