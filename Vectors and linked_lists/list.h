#ifndef list_h
#define list_h
#include "data.h"
typedef struct node
{
	Data data;
	struct node * next, *prev;
}Node;


typedef struct list
{
	Node * head,* tail;
	void (*insert)(struct list *, int, Data);
	Data* (*read)(struct list *, int);
	void (*remove)(struct list *, int);
	void (*delete)(struct list *);
	int index;
}List;

List * newList();

void insertList(List * , int , Data );

void removeData(List * , int );

Data * readData(List * , int );

void deleteList(List *);


#endif
