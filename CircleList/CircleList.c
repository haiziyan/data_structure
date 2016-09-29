#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode *slider;
    int length;
}TCircleList;

CircleList *CircleList_create()
{
    TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
    if( ret )
    {
    	ret->header.next = NULL;
	ret->slider = NULL;
	ret->length = 0;

    }
    return ret ;
}

void CircleList_destory(CircleList *list)
{
    free(list);
}
void CircleList_clear(CircleList *list)
{
    TCircleList *List = (TCircleList *)list;
    if( List )
    {
    	ret->header.next = NULL;
	ret->slider = next;
	ret->length = 0;
    }
}

int CircleList_length(CircleList *list)
{
    TCircleList *List = (TCircleList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->List;
    }
    return ret ;
}

int CircleList_insert(CircleList *list, CircleListNode *node, int pos)
{
    TCircleList *List = (TCircleList *)list;
    int ret = (List != NULL )&&(node != NULL)(pos >= 0)
    int i = 0; 
    if( ret )
    {
    	CircleListNode *current = (CircleListNode *)List;
	for(i = 0; i < pos && current->next != NULL; i++)
	{
	    current = current->next;
	}
	node->next = current->next;
	current->next = node;
	if(List->length == 0)
	{
	    List->slider = node;
	    node->next = node;
	}
	List->length++;

    }
    return ret ;
}
CircleListNode *CircleList_get(CircleList *list, int pos)
{
    TCircleList *List = (TCircleList *)list;
    CircleListNode *ret = NULL;
    int i = 0;
    if(List != NULL && pos >= 0)
    {
    	CircleListNode *current = (CircleListNode *)List;
	for(i = 0; i < pos; i++)
	{
	    current = current->next;
	}
	ret = current->next;
    }
    return ret;
    
}
CircleListNode *CircleList_delete(CircleList *list, int pos)
{
    TCircleList *List = (TCircleList *)list;
    CircleListNode *ret = NULL;
    int i = 0;
    if(List != NULL && pos >= 0)
    {
    	CircleListNode *current = (CircleListNode *)List;
	CircleListNode *first = List->header.next;
	CircleListNode *last = (CircleListNode *)CircleList_get(list, List->lenth-1);
	for(i = 0; i < pos; i++)
	{
	    current = current->next;

	}
	ret = current->next;
	current->next = ret->next;
	List->length--;
	if(ret == first)
	{
	    List->header.next = ret->next;
	    last->next = ret->next;
	}
	if(ret == List->slider)
	{
	    List->slider = ret->next;
	}
	if(List->length == 0)
	{
	    List->header.next = NULL;
	    List->slider = NULL;
	}
    }
    return ret ;
}

CircleListNode *CircleList_deletenode(CircleList *list, CircleListNode *node)
{
    TCircleList *List = (TCircleList *)list;
    CircleListNode *ret = NULL;
    int i = 0; 
    if(List != NULL && node !- NULL)
    {
    	CircleListNode *current = (CircleListNode *)List;
	for(i = 0; i < pos; i++)
	{
	    if(current->next == node)
	    {
	    	ret = current->next;
		break;
	    }
	    current = current->next;

	}
	if( ret )
	{
	    CircleList_delete(list, i);
	}
	
    }
    return ret ;
}

CircleListNode *CircleList_reset(CircleList *list)
{
    TCircleList *List = (TCircleList *)list;
    CircleList *ret = NULL;
    if( List )
    {
    	List->slider = List->header.next;
	ret = List->slider;
    }
    return ret ;
}

CircleListNode *CircleList_current(CircleList *list)
{
    TCircleList *List = (TCircleList *)list;
    CircleListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;

    }
    return ret;
}

CircleListNode *CircleList_next(CircleList *list)
{
    TCircleList *List = (TCircleList *)list;
    CircleListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;
	List->slider = ret->next;
    }
    return ret;
}
