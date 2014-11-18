#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct node* nodePtr;

typedef struct myList* myListPtr;

int createMyList(myListPtr* list);

int getSizeMyList(myListPtr list);

int pushFrontMyList(myListPtr list, void* _data);

int pushBackMyList(myListPtr list, void* _data);

int popFrontMyList(myListPtr list);

int popAndGetFrontMyList(myListPtr list, void** _data);

int popBackMyList(myListPtr list);

int popAndGetBackMyList(myListPtr list, void** _data);

int getFirstMyList(myListPtr list, void** _data);

int getLastMyList(myListPtr list, void** _data);

int destroyMyList(myListPtr* list);

int invertMyList(myListPtr list);

#endif