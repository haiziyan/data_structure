#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

typedef struct _tag_LinkQueue
{
    struct _tag_LinkQueue *next;
    void *item;
}TLinkQueue;

typedef struct _tag_LinkQueueNode
{
    TLinkQueueNode *front;
    TLinkQueueNode *rear;
    int length;
}TLinkQueue;

LinkQueue *LinkQueue_create()
{
    TLinkQueue *ret = (TLinkQuene *)malloc(sizeof(TLinkQueue));
    if( ret )
    {
    	ret->front = NULL;
	ret->rear = NULL;
	ret->length = 0;
    }
    return ret ;
}

void LinkQueue_destory(LinkQueue *qenue)
{
    LinkQuene_clear(Queue);
    free(Queue);
}

void LinkQueue_clear(LinkQueue *Queue)
{
     while(LinkQueue_length(Queue) > 0)
     {
     	LinkQueue_retrieve(Queue);
     }
}

int LinkQueue_append(LinkQueue *Queue, void *item)
{
     TLinkQueue *Queue = (TLinkQueue *)queue;
     TLinkQueueNode *node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
     int ret = (Queue != NULL )&&(item != NULL);
     if( ret )
     {
     	node->item = item;
     	if(Queue->length > 0)
	{
	    Queue->rear.next = node;
	    Queue->rear = node;
	    node->next = NULL;
	}
	else 
	{
	    Queue->front = node;
	    Queue->rear = node;
	    node->next = NULL;
	}
	Queue->length++;
     }
     else
     {
         free(node);
     }
     return ret ;
     
}

void *LinkQueue_retrieve(LinkQueue *Queue)
{
    TLinkQueue *Queue = (TLinkQueue *)queue;
    TLinkQueueNode *node = NULL;
    void *ret = NULL;
    if( Queue )
    {
    	node = Queue->front;
	Queue->front = node->next;
	ret = node->item;
	free(node);
	Queue->length--;
	if(Queue->length == 0)
	{
	    Queue->front = NULL;
	    Queue->rear = NULL;
	}
    }
    return ret;
}

void *LinkQueue_header(LinkQueue *Queue)
{
    TLinkQueue *Queue = (TLinkQueue *)queue;
    void *ret = NULL;
    if(Queue != NULL && Queue->length > 0)
    {
    	ret = Queue->front->item;
    }
    return ret ;

}

int LinkQueue_length(LinkQueue *queue)
{
    TLinkQueue *Queue = (TLinkQueue *)queue;
    int ret = -1;
    if( Queue )
    {
    	ret = Queue->length;
    }
    return ret ;
}
