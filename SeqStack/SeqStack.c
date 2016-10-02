#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

SeqStack *SeqStack_create(int capacity)
{
    return SeqList_create(capacity);
}

void SeqStack_destory(SeqStack *stack)
{
    SeqList_destory(stack);
}

void SeqStack_clear(SeqStack *stack)
{
    SeqList_clear(stack);
}

int SeqStack_push(SeqStack *stack, void *item)
{
    return SeqList_insert(stack, item, 0);
}

void *SeqStack_pop(SeqStack *stack)
{
    return SeqList_delete(stack, 0);
}

void *SeqStack_top(SeqStack *stack)
{
    return SeqList_get(stack, 0);
}

int SeqStack_size(SeqStack *stack)
{
    return SeqList_length(stack);
}

int SeqStack_capacity(SeqStack *stack)
{
    return SeqList_capacity(stack);
}
