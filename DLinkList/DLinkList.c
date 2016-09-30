#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

typedef struct _tag_DLinkList
{
    DLinkListNode header;
    DLinkListNode *slider;
    int length;
}TDLinkList;

DLinkList *DLinkList_create()
{
    TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
    if( ret )
    {
    	ret->header.next = NULL;
	ret->header.pre = NULL;
	ret->length = 0;
    }
    return ret ;
}

void DLinkList_destory(DLinkList *list)
{
    free(list);
}

void DLinkList_clear(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    if( List )
    {
    	List->header.next = NULL;
	List->header.pre = NULL;
	List->length = 0;
    }

}

int DLinkList_length(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->length;
    }
    return ret ;
}

int DLinkList_insert(DLinkList *list, DLinkListNode *node, int pos)
{
    TDLinkList *List = (TDLinkList *)list;
    int ret = (List != NULL)&&(node != NULL)&&(pos >= 0)
    if( ret )
    {
    	DLinkListNode *current = (DLinkListNode *)List;
	DLinkListNode *next = NULL;
	int i = 0;
	for(i = 0; i < pos  && current->next != NULL; i++)
	{
	    current = current->next;
	}
	next = current->next;
	node->next = next;
	current->next = node;
	if( next )
	{
	    next->pre = node;
	}
	node->pre = current;
	if(List->length == 0)
	{
	    
	    List->slider = node;
	}
	if(current == (DLinkList*)list) //判断结点是否插入到第一个结点
	{
	    node->pre = NULL;
	}
	List->length++;
    }
    return ret ;
}

DLinkListNode *DLinkList_get(DLinkList *list, int pos)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if(List != NULL && pos >= 0 && pos < List->length)
    {
    	DLinkListNode *current = (DLinkListNode *)List;
	int i = 0 ;
	for(i = 0; i < pos; i++)
	{
	    current = current->next;
	}
	ret = current->next;
    }
    return ret ;
}

DLinkListNode *DLinkList_delete(DLinkList *list, int pos)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if(List != NULL && pos >= 0 && pos <List->length)
    {
    	DLinkListNode *current = (DLinkListNode *)list;
	DLinkListNdoe *next = NULL:
	int i = 0;
	for(i = 0 ; i < pos; i++)
	{
	    current = current->next;
	}
	ret = current->next;
	next = ret->next;
	current->next = next;
	if( next )
	{
	    next->pre = current;
	    if(current == (DLinkListNode *)List)
	    {
	    	next->pre = NULL;
	    }
	    	
	}
	if(ret == List->slider)
	{
	    List->slider = ret->next;
	}
	
	List->length--;
		
    }
    return ret ;
}

DLinkListNode *DLinkList_deletenode(DLinkList *list, DLinkListNode *node)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if(List != NULL && node != NULL)
    {
    	DLinkListNode *current = (DLinkListNode *)List;
	int i = 0;
	for (i = 0; i < List->length; i++)
	{
	    if(node == current->next)
	    {
	    	ret = node;
		break;
	    }
	    current = current->next;
	}
	if( ret )
	{
	    DLinkList_delete(list, i);
	}
    }
    return ret ;
}

DLinkListNode *DLinkList_reset(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;
	List->slider = List->header.next;
    }
    return ret ;
}

DLinkListNode *DLinkList_current(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;
    }
    return ret ;
}

DLinkListNode *DLinkList_next(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;
	List->slider = ret->next;
    }
    return ret ;
}

DLinkListNode *DLinkList_pre(DLinkList *list)
{
    TDLinkList *List = (TDLinkList *)list;
    DLinkListNode *ret = NULL;
    if( List )
    {
    	ret = List->slider;
	List->slider = ret->pre;
    }
    return ret ;
}
