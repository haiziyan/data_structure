#ifndef _SEQLIST_H
#define _SEQLIST_H

typedef void SeqList;
typedef void SeqListNode;

SeqList *SeqList_create(int capacity);
void SeqList_destory(SeqList *list);
void SeqList_clear(SeqList *list);
int SeqList_length(SeqList *list);
int SeqList_capacity(SeqList *list);
int SeqList_insert(SeqList *list, SeqListNode *node, int pos);
int SeqList_get(SeqList *list, int pos);
int SeqList_delete(SeqList *list, int pos);


#endif
