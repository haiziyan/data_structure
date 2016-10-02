#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H


typedef void SeqQueneue;

SeqQueue *SeqQueue_create(int capacity);
void SeqQueue_destory(SeqQueue *queue);
void SeqQueue_clear(SeqQueue *queue);
int SeqQueue_append(SeqQueue *queue);
void *SeqQueue_retrieve(SeqQueue *queue, void *item);
void *SeqQueue_header(SeqQueue *queue);
int SeqQueue_length(SeqQueue *queue);
int SeqQueue_capacity(SeqQueue *queue);






#endif
