#include<stdio.h>
#include<stdlib.h>
#include"list.h"


List * newList()
{
	List * list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->index = 0;
	list->insert = insertList;
	list->read = readData;
	list->remove = removeData;
	list->delete = deleteList;
	return list;
}


void insertList(List * list, int index, Data value)
{
	if(list->index == 0)
	{
		Node * p = malloc(sizeof(Node));
                p->data = value;
                list->head = p;
                list->tail = p;
                list->head->prev = NULL;
                list->tail->next = NULL;
                list->index = list->index + 1;
	}
	else if(list->index <= index)
	{
		Node * p = malloc(sizeof(Node));
                p->data = value;
                list->tail->next = p;
                p->prev = list->tail;
                p->next = NULL;
                list->tail = p;
                list->index = list->index+1;
	}
	
}


Data * readData(List * list, int index){

	while(index <= list->index)
	{
		Node * p = list->head;
                int i = 0;
                while(p->next != NULL && i < index )
                {
                        p->next->prev = p;
                        p = p->next;
                        i++;
                }
                return &p->data;
	}
	return NULL;
}


void deleteList(List * list)
{

	Node* p = list -> head;
	Node* next;

	while(p != NULL){
    	next = p->next;
    	free(p);
    	p = next;
  	}


	free(list);
}


void removeData(List * list, int index){

	if(index >= list->index)
	{
		return;
	}
	else
	{
		if(list->head == list->tail)
		{
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
			return;
		}
		else if(index == 0)
		{
			Node * q = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free(q);
			q = NULL;
			list->index = list->index - 1;
			return;
		}
		else if(index == (list->index - 1))
		{
			Node * q = list->tail;
			list->tail->prev->next = NULL;
			list->tail = list->tail->prev;
			free(q);
			q = NULL;
			list->index = list->index - 1;
			return;
		}
		else if(index > 0)
		{
			Node * q = list->head;
			int i = 0;
			while(i != index)
			{
				q = q->next;
				i++;
			}
			q->next->prev = q->prev;
			q->prev->next = q->next;
			free(q);
			q = NULL;
			list->index = list->index - 1;
			return;
		}
		else if(list->index == 0)
        	{
        			return;
       		}
                	
	}
}