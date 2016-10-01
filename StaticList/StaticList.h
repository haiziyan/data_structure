#ifndef _STATICLIST_H
#define _STATICLIST_H

typedef void StaticList;
typedef void StaticListNode;

StaticList *StaticList_create(int capacity);
void StaticList_destory(StaticList *list);
void StaticList_clear(StaticList *list);
int StaticList_length(StaticList *list);
int StaticList_capacity(StaticList *list);
int StaticList_insert(StaticList *list, StaticListNode *node, int pos);
StaticListNode *StaticList_get(StatciList *list, int pos);
StaticListNode *StaticList_delete(StaticList *list, int pos);



#endif
