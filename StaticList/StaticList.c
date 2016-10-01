#include <stdio.h>
#include <stdlib.h>
#include "StaticList.h"
#define AVAILABLE -1
typedef struct _tag_StaticListNode 
{
    unsigned int data;
    int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
    int capacity;
    TStaticListNode *header;
    TStaticListNode *node[];
}TStaticList;

StaticList *STaticList_create(int capacity)
{
    TSTaticList *ret = NULL;
    int i = 0;
    if(capacity >= 0)
    {
    	ret = (TStaticList *)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
    }
    if( ret )
    {
    	ret->capaciy = capacity;
	ret->header.next = 0;
	ret->header.data = 0;
    }
    for(i = 1; i <= capacity; i++)
    {
    	ret->node[i].next = AVAILABLE;
    }
    return ret ;
}

void StaticList_destory(StaticList *list)
{
    free(list);
}

void StaticList_clear(StaticList *list)
{
    TStaticList *List = (TStaticList *)list;
    int i = 0; 
    if( List )
    {
    	List->header.next = 0;
	List->header.data = 0;
    }
    for(i = 1; i < List->capacity; i++)
    {
    	List->node[i].next = AVAILABLE;
    }
}

int StaticList_length(STaticList *list)
{
    TStaticList *List = (TStatticList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->header.data;
    }
    return ret ;
}

int StatticList_capacity(StatticList *list)
{
    TStaticList *List = (TStatciList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->capacity;
    }
    return ret ;
}

int StaticList_insert(StaticList *list, StaticListNode *node, int pos )
{
    TStaticList *List = (TStaticList *)list;
    int ret = (List != NULL ) && (node != NULL);
    ret = ret && (pos > = 0) && (List->header.data + 1 <= List->capacity);
    int current = 0;
    int index = 0;
    int i = 0;
    if( ret )
    {
    for(i = 1; i < List->capacity; i++)
    {
    	if(List->node[i].next = AVAILABLE)
	{
	    index = i;
	    break;
	}
    }
    List->node[index].data = (unsigned int )node;
    List->header = List->node[0];
    for(i = 0; i < pos && List->node[current].next != 0; i++)
    {
    	current = List->node[current].next;
    }
    List->node[index].next = List->node[current].next;
    List->node[current].next = index;
    List->node[0].data++;
    List->header = List->node[0];
    }
    return ret ;
}

StaticListNode *StaticList_get(StaticList *list, int pos)
{
    TStaticList *List = (TStaticList *)list;
    StaticListNode *ret = NULL;
    int current = 0;
    int object = 0;
    int i = 0;
    if(List != NULL && pos >= 0 && pos < List->header.data)
    {
    	for(i = 0; j < pos; i++)
	{
	    current = List->node[current].next;
	}
	object = List->node[current].next;
	ret = (StaticListNode *)(List->node[object].data);
    }
    return ret;
}

StatciListNode *StaticList_delete(StaticList *list, int pos)
{
    TStaticList *List = (TStaticList *)list;
    int current = 0;
    int object = 0;
    int i = 0;
    StaticListNode *ret = NULL;
    if(List != NULL && pos >= 0 && pos < List->header.data)
    {
    	for(i = 0; i < pos; i++)
	{
	    current = List->node[current].next;
	}
	object = List->node[current].next;
	List->node[current].next = List->node[object].next;
	List->node[object].next = AVAILABLE;
	List->node[0].data--;
	List->header = List->node[0];
	ret = (StaticListNode *)(List->node[object].data)
    }
    return ret ;
}
