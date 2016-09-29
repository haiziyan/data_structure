#ifndef CIRCLELIST_H
#define CIRCLELIST_H


typedef void CircleList;
typedef struct _tag_CircleListNode 
{
    struct _tag_CircleListNode *next;

}CircleListNode;

CircleList *CircleList_create();
void CircleList_destory(CircleList *list);
void CircleList_clear(CircleList *list);
int CircleList_length(CircleList *list);
int CircleList_insert(CircleList *list, CircleListNost *node, int pos);
CircleListNode *CircleList_get(CircleList *list, int pos);
CirclstListNode *CircleList_delete(CircleList *list, int pos);
CircleListNode *CircleList_deletenode(CircleList *list, CircleListNode *node);
CircleListNode *CircleList_reset(CircleList *list);
CircleListNode *CircleList_current(CircleList *list);
CircleListNode *CircleList_next(CircleList *list);

#endif
