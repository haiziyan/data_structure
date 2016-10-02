#ifndef _SQUEUE_H
#define _SQUEUE_H

typedef void SQueue;

SQueue *SQueue_create();
void SQueue_destory(SQueue *queue);
void SQueue_clear(SQueue *queue);
int SQueue_appdend(SQueue *queue, void *item);
void *SQueueu_retrieve(SQueue *queue);
void *SQueue_header(SQueue *queue);
int SQueue_length(SQueue *queue);






#endif
