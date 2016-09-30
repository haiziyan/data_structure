#include <stdio.h>
#include <stdlib.h>
#include "SeqList.c"

typedef unsigned int TSeqListNode;
typedef struct _tag_SeqList
{
    int capacity;
    int length;
    TSeqListNode *ndoe;
}TSeqList;

SeqList *SeqList_create(int capacity)
{
    TSeqList *ret = NULL;
    if(capacity >= 0)
    {
    TSeqList *ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(TSeqListNode ) * capacity);
    }
    if( ret )
    {
    	ret->capacity = 0;
	ret->length = 0;
	ret->node = (TSeqListNode *)(ret + 1);
    }
    return ret ;
}

void SeqList_destory(SeqList *list)
{
    free(list);
}

void SeqList_clear(SeqList *list)
{
    TSeqList *List = (TSeqList *)list;
    if( List )
    {
    	List->length = 0;
    }
    
}

int SeqList_capacity(SeqList *list)
{
    TSeqList *List = (TSeqList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->capacity;
    }
    return ret ;
}

int SeqList_length(SeqList *list)
{
    TSeqList *List = (TSeqList *)list;
    int ret = -1;
    if( List )
    {
    	ret = List->length;
    }
    return ret ;
}

int SeqList_insert(SeqList *list, SeqListNode *node, int pos)
{
    TSeqList *List = (TSeqList *)list;
    int ret = (List != NULL);
    ret = ret && (node != NULL) && (pos >= 0) && (List->length +1 <= List->capacity);
    int i =0;
    if( ret )
    {
    	if(pos > List->length)
	{
	    pos = List->length;
	}
	for(i = List->length; i > pos; i--)
	{
	    List->node[i] = List->node[i-1];
	}
	List->node[i] = (TSeqListNode *)node;
	List->length++;
    }
    return ret ;
}

SeqListNode *SeqList_get(SeqList *list, int pos)
{
    TSeqList *List = (TSeqList *)list;
    SeqListNode *ret = NULL;
    if(List != NULL && pos >= 0 && pos < List->length )
    {
    	ret = List->node[pos];
    }
    return ret ;
}

SeqListNode *SeqList_delete(SeqList *list, int pos)
{
    TSeqList *List = (TSeqList *)list;
    SeqListNode *ret = SeqList_get(list, pos);
    int i = 0;
    if(List != NULL && pos >= 0 && pos < List->length)
    {
    	for(i = pos; i < List->length; i++)
	{
	    List->node[i-1] =List-node[i];
	}
	List->length--;
    }
    return ret ;
}
