#ifndef DLINKLIST_H
#define DLINKLIST_H

typedef void DLinkList;
typedef struct _tag_DLinkListNode 
{
    struct _tag_DLinkListNode *next;
    struct _taf_DLinkListNode *pre;
}

DLinkList *DLinkList_create();
void DLinkList_destory(DLinkList *list);
void DLinkList_clear(DLinkList *list);
int DLinkList_length(DLinkList *list);
int DLinkList_insert(DLinkList *list, DLinkListNode *node, int pos);
DLinkListNode *DLinkList_get(DLinkList *list, int pos);
DLinkListNOde *DLinkList_delete(DLinkList *list, int pos);
DLinkListNode *DLinkList_deletenode(DLinkList *list, DLinkListNode *node );
DLinkListNode *DLinkList_reset(DLinkList *list);
DLinkListNode *DLinkList_current(DLinkList *list);
DLinkListNode *DLinkList_next(DLinkList *list);
DLinkListNode *DLinkList_pre(DLinkList *list);








#endif
