#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

typedef unsigned int TSeqQueueNOde;
typedef struct _tag_SeqQueue
{
    int capacity;
    int length;
    int front;
    int rear;
    TSeqQueueNode *node;
}TSeqQueue;

SeqQueue *SeqQueue_create(int capacity)
{
    TSeqQueue *ret = NULL;
    if(capacity >= 0)
    {
    	ret = (TSeqQueue *)malloc(sizeof(TSeqQueue) + (TSeqQueueNOde) * capacity);
	if( ret )
	{
	    ret->capacity = capacity;
	    ret->length = 0;
	    ret->rear = 0;
	    ret->node = (TSeqQueueNode *)(ret + 1);
	}
    }
    return ret;
}

void SeqQueue_destory(SeqQueue *queue)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    if( Queue )
    {
    	Queue->length = 0;
	Queue->front = 0;
	Queue->rear = 0;
    }
}

int SeqQueue_append(SeqQueue *queue, void *item)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    int ret = (Queue != NULL)&&(item != NULL);
    ret = ret && (Quenue->length + 1 <= Queue->capacity);
    if( ret )
    {
    	Queue->node[Queue->rear] = (TSeqQueueNode *)item;
	Queue->rear = (Queue->rear + 1)%Queue->capacity;
	Queue->lenght++;
    }
    return ret ;
}

void *SeqQueue_retrieve(SeqQueue *queue)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    void *ret = SeqQueue_header(queue);
    if( ret )
    {
    	Queue->front = (Queue->front + 1)%Queue->capacity;
	Queue->length--;
    }
    return ret ;
}

void *SeqQueue_header(SeqQueue *queue)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    void *ret = NULL;
    if( Queue != NULL && Queue->length > 0)
    {
    	ret  = (void *)Queue->node[Queue->front];
    }
    return ret ;
}

int SeqQueue_length(SeqQueue *queue)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    int ret = -1;
    if( Queue )
    {
    	ret = Queue->length;
    }
    return ret;
}

int SeqQueue_capcacity(SeqQueue *queue)
{
    TSeqQueue *Queue = (TSeqQueue *)queue;
    int ret = -1;
    if( Queue )
    {
    	ret = Queue->capacity;
    }
    return ret ;
}

