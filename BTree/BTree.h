#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#define BT_LEFT 0
#define BT_RIGHT 1

typedef unsigned long long BTpos;
typedef void BTree;

typedef struct _tag_BTreeNode
{
    struct _tag_BTreeNode *left;
    struct _tag_BTreeNode *right;
}BTreeNode;

typedef void (BTree_printf)(BTreeNode *);

BTree *BTree_create();
void BTree_destory(BTree *tree);
void BTree_clear(BTree *tree);

int BTree_insert(BTree *tree, BTreeNode *node, BTpos pos, int count,int flag);

BTreeNode *BTree_delete(BTree *tree, BTpos pos, int count );

BTreeNode *BTree_get(BTree *tree, BTpos pos, int count);

int BTree_hight(BTree *tree);
int BTree_count(BTree *tree);
int BTree_degree(BTree *tree);
BTreeNode *BTree_root(BTree *tree);
void BTree_display(BTree *tree, BTree_printf *pFunc, int gap, char div);
#endif // BTREE_H_INCLUDED
