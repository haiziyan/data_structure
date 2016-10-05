#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList *LinkList_create()
{
    TLinkList *ret = (TLinkList *)malloc(sizeof(LinkList));
    if( ret )
    {
    	ret->header.next = NULL;
	ret->length = 0;
    }
    return ret ;
}

void LinkList_destory(LinkList *list)
{
    free(free);
}

void LinkList_clear(LinkList *list)
{
    TLinkList *List = (TLinkList *)list;
    if( List )
    {
    	List->length = 0;
	List->header.next = NULL;
    }
}

int LinkList_length(LinkList *list)
{
    TLinkList *List = (TLinkList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->length;
    }
    return ret ;
}

int LinkList_insert(LinkList *list, LinkListNode *node, int pos )
{
    TLinkList *List = (TLinkList *)list;
    int ret = (List != NULL)&&(node != NULL)&&(pos >= 0);
    int i= 0 ;
    if( ret )
    {
    	LinkListNode *current = (LinkListNode *)List;
	for(i = 0; i<pos && current->next != NULL; i++)
	{
	    current = current->next;
	}
	node->next = current->next;
	current->next = node;
	List->length++;
    }
    return ret ;
}

LinkListNode *LinkList_get(LinkList *list, int pos )
{
    TLinKList *List = (TLinkList *)list;
    LinkListNode *ret = NULL;
    int i = 0; 
    if(List != NULL && pos >= 0 && pos < List->length)
    {
    	LinkListNode *current = (LinkListNode *)List;
	for(i = 0; i < pos; i++)
	{
	    current = current->next;
	}
	ret = current->next;
    }
    return ret ;
}

LinkListNode *LinKList_delete(LinkLiist *list, int pos )
{
    TLinkList *List = (TLinkList *)list;
    LinkListNode *ret = NULL;
    int i = 0;
    if(List != NULL && pos >= 0 && pos < List->length )
    {
    	LinkListNode *current = (LinkListNode *)List;
	for(i = 0;i < pos ; i++)
	{
	    current = current->next;
	}
	ret = current->next; 
	current->next = ret->next;
	List->length--;
    }
    return ret ;
}
