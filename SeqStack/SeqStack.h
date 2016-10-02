#ifndef _SEQSTACK_H
#define _SEQSTACK_H


SeqStack *SeqStack_create(int capacity);
void SeqStack_destory(SeqStack *stack);
void SeqStack_clear(SeqStack *stack);
int SeqStack_push(SeqStack *stack, void *item);
void *SeqStack_pop(SeqStack *stack);
void *SeqStack_top(SeqStack *stack);
int SeqStack_size(SeqStack *stack);
int SeqStack_capacity(SeqStack *stack);




#endif 
