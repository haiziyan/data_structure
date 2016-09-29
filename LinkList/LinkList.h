#ifndef LINKLIST_H
#define LINKLIST_H


typedef void LinkList;
typedef struct _tag_LinkListNode
{
    struct _tag_LinkListNode *next;
}LinkListNode;

LinkList *LinkList_create();
void LinkList_destory(LinkList *list);
void LinkList_clear(LinkList *list);
int LinkList_length(LinkList *list);
int LinkList_insert(LinkList *list,LinkListNode *node, int pos);
LinkListNode *LinkList_delete(LinkList *list, int pos);
LinkListNode *LinkList_get(LinkList *list, int pos);


#endif
