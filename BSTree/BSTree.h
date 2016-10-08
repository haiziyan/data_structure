#ifndef _BSTREE_H
#define _BSTREE_H

typedef void BSTree;
typedef void BSkey;

typedef struct _tag_BSTreeNode
{
    BSTree *key;
    BSTreeNode *left;
    BSTreeNode *right;
}BSTreeNode;

typedef void (BSTree_printf)(BSTreeNode *);
typedef int (BSTree_compare)(BSkey *, BSkey *);

BSTree *BStree_create();
void BSTree_destory(BSTree *tree);
void BSTree_clear(BSTree *tree);
int BSTree_insert(BSTree *tree, BSTreeNode *node, BSTree_compare *compare);
BSTreeNode *BSTree_delete(BSTree *tree, BSkey *key, BSTree_compare *compare);
BSTreeNode *BSTree_get(BSTree *tree, BSkey *key,BSTree_compare *compare);
BSTreeNode *BSTree_root(BSTree *tree);
int BSTree_hight(BSTree *tree);
int BSTree_count(BSTree *tree);
int BSTree_degree(BSTree *tree);
void BSTree_display(BSTree *tree, BSTree_printf *pFunc, int gap,char div);


#endif
