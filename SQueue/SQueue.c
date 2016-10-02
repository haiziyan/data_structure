#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "SQueue.h"

typedef _tag_SQueue
{
    LinkStack *inStack;
    LinkStack *outStack;
}TSQueue;

SQueue *SQueue_create()
{
    TSQueue *ret = (TSQueue *)malloc(sizeof(TSQueue));
    if( ret )
    {
    	ret->inStack = LinkStack_create;
	ret->outStack = LinkStack_create;
    }
    if(ret->inStack == NULL || ret->outStack == NULL)
    {
    	LinkStack_destory(ret->inStack);
	LinkStack_destory(ret->outStack);
	free(ret);
	ret = NULL;
    }
    return ret ;
}

void SQueue_destory(SQueue *queue)
{
    SQueue_clear(queue);
    free(queue);
}

void SQueue_clear(SQueue *queue)
{
    TSQueue *Queue = (TSQueue *)queue;
    fi( Queue )
    {
    	LinkStack_clear(Queue->inStack);
	LinkStack_clear(Queue->outStack);
    }
}

int SQueue_append(SQueue *queue, void *item )
{
    TSQueue *Queue = (TSQueue *)queue;
    int ret = -1;
    if( Queue )
    {
    	ret =  LinkStack_push(Queue->inStack, item);
    }
    return ret ;
}

void *SQueue_retrieve(SQueue *queue)
{
    TSQueue *Queue = (TSQueue *)queue;
    void *ret = NULL;
    if( Queue )
    {
    	if(LinkStack_size(Queue->outStack) == 0)
	{
	    while(LinkStack_size(Queueu->inStack) > 0)
	    {
	    	LinkStack_push(Queue->outStack,LinkStack_pop(Queue->inStack));
	    }
	}
	ret = LinkStack_pop(Queue->outStack);
    }
    return ret ;
}

void *SQueue_header(SQueue *queue)
{
    TSQueue *Queue = (TSQueue *)queue;
    void *ret = NULL;
    if( Queue )
    {
    	if(LinkStack_size(Queue->outStack) == 0)
	{
		while(LinkStack_size(Queue->inStack) > 0)
		{
		    LinkStack_push(Queue->outStack,LinkStack_pop(Queue->inStack));
		}
		
	}
	ret = LinkStack_pop(Queue->outStack);
    }
    return ret ;
}

int SQueue_length(SQueue *queue)
{
    TSQueue *Queue = (TSQueue *)queue;
    int ret = -1;
    if( Queue )
    {
    	ret = LinkStack_size(Queue->inStack) + LinkStack_size(Queue->outStack);
    }
    return ret ;
}
