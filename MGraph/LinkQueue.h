#ifndef _LinkQueue_H
#define _LinkQueue_H

typedef void LinkQueue;

LinkQueue *LinkQueue_create();
void LinkQueue_destory(LinkQueue *queue);
void LinkQueue_clear(LinkQueue *queue);
int LinkQueue_append(LinkQuenur *queue, void *item);
void *LinkQueue_retrieve(LinkQueue *queue);
void *LinkQueue_header(LinkQueue *queue);
int LinkQueue_length(LinkQueue *queue);








#endif
