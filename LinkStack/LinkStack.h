#ifndef _LINKSTACK_H
#define _LINKSTACK_H

typedef void LinkStack;

LinkStack *LinkStack_create();
void LinkStack_destory(LinkStack *stack);
void LinkStack_clear(LinkStack *stack);
int LinkStack_push(LinkStack *stack, void *item);
void *LinkStack_pop(LinkStack *stack);
void *LinkStack_top(LinkStack *stack);
int *LinkStack_size(LinkStack *stack);

#endif
