#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

typedef struct _tag_LinkStackNode
{
    LinkListNode header;
    void *item;
}TLinkStackNode;

LinkStack *LinkStack_create()
{
    return LinkList_create();
}

void LinkStack_destory(LinkStack *stack)
{
    LinkStack_clear(stack);
    LinkStack_destory(stack);
}

void LinkStack_clear(LinkStack *stack)
{
    while(LinkStack_size(stack) > 0)
    {
    	LinkStack_pop(stack);
    }
}

int LinkStack_push(LinkStack *stack, void *item)
{
    TLinkStackNode *node = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
    int ret = (node != NULL )&&(item != NULL);
    if( ret )
    {
    	node->item = item;
	ret = LinkList_insert(stack,(LinkListNode *)node, 0);
    }
    else
    {
    	free(node);
    }
    return ret ;
}

void *LinkStack_pop(LinkStack *stack)
{
    TLinkStackNode *node = (TLinkStackNode *)LinkList_delete(stack, 0);
    void *ret = NULL;
    if( node )
    {
    	ret= node->item;
	free(node);
    }
    return ret ;
}

void *LinkStack_top(LinkStack *stack)
{
    TLinkStackNode *node = (TLinkStackNode *)LinkList_get(stack, 0);
    void *ret = NULL;
    if( node )
    {
    	ret = node->item;
	free(node);
    }
    return ret ;
}

int LinkStack_size(LinkStack *stack)
{
    return LinkList_length(stack);
}
