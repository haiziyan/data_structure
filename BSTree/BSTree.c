#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

typedef struct _tag_BSTree
{
    int count;
    BSTreeNode *root;
}TBSTree;

static int recrusive_insert(BSTreeNode *root,BSTreeNode *node, BSTree_compare *compare *compare)
{
    int ret = 1;
    int r =compare(node->key, root->key);
    if( r == 0)
    {
    	ret = 0;
    }
    else if( r < 0 )
    {
    	if( root->left != NULL)
        {
    	    ret = recursive_insert(root->left, node, compare);
	}
	else
	{
	    root->left = node;
	}
    }
    else
    {
    	if( root->right != NULL)
	{
	    ret = recursive_insert(root->right, node,compare);
	}
	else
	{
	    root->right = node;
	}
    }
    return ret ;
}

static BSTreeNode *delete_node(BSTreeNode **root)
{
    BSTreeNode *ret = NULL;
    if((*root)->right == NULL)
    {
    	*root = (*root)->left; 
    }
    else if((*root)->left == NULL)
    {
    	*root = (*root)->right;
    }
    else
    {
    	BSTreeNode *g = *root;
	BSTreeNode *c = (*root)->left;
	while(c->right != NULL)
	{
	    g = c;
	    c = c->right;
	}
	if(g == *root)
	{
	    g->right = c->left;
	}
	else
	{
	    c->left = (*root)->left;
	    c->right = (*root)->right;
	}
	*root = c;
    }
    return ret ;
}
static BSTreeNode *recursive_delete(BSTreeNode **root, BSkey *key, BSTree_compare *compare)
{
    BSTreeNode *ret = NULL;
    if(root && *root)
    {
    	int r = compare(key, (*root)->key);
	if(r == 0)
	{
	    ret = delete_node(root);
	}
	else if(r < 0)
	{
	     ret = recursive_delete(&((*root)->left),key,compare);
	}
	else
	{
	    ret = recursive_delete(&((*root)->right),key, compare);
	}
    }
    return ret ;
}

static BSTreeNode *recursive_get(BSTreeNode *root,BSkey *key, BSTree_compare *compare)
{
    BSTreeNode *ret = NULL;
    if( root )
    {
    	int r = compare(key,root->key);
	if( r == 0)
	{
	    ret = root;
	}
	else if ( r < 0 )
	{
	    ret = recursive_get(root->left, key,compare);
	}
	else
	{
	    ret = recursive_get(root->right, key, compare);
	}

    }
    return ret ;
}

static int recursive_hight(BSTreeNode *root)
{
    int ret = 0;
    if( root )
    {
    	int lh = recursive_hight(root->left);
	int rh = recursive_hight(root->right);
	ret = ((lh > rh)?lh:rh)+1;
    }
    return ret;
}

static int recursive_degree(BSTreeNode *root)
{
    int ret = 0;
    if( root )
    {
    	if(root->left != NULL)
	{
	    ret++;
	}
	if(root->right != NULL)
	{
	    ret++;
	}
	if(ret == 1)
	{
	    int ld = recursive_degree(root->left);
	    int rd = recursive_degree(root->right);
	    if( ret < ld)
	    {
	    	ret = ld;
	    }
	    if(ret < rd)
	    {
	    	ret = rd;
	    }
	}

    }
    return ret ;
}

static void recursive_display(BTreeNode *node, BSTree_printf *pFunc, int format,int gap,char div)
{
    int i = 0;
    if(node && pFunc)
    {
    	for(i = 0;i < format; i++)
	{
	    printf("%c",div);
	}
	pFunc(node);
	printf("\n");
	if(node->left != NULL || node->right != NULL)
	{
	    recursive_display(node->left,pFunc,format+gap,gap,div);
	    retursive_display(node->right,pFunc,format+gap,gap,div);
	}
    }
    else
    {
    	for(i = 0; i < format; i++)
	{
	    printf("%c",div);
	}
	printf("\n");
    }
}
BStree *BSTree_create()
{
    TBStree *ret = (TBSTree *)malloc(sizeof(TBSTree));
    if( ret )
    {
    	ret->count = 0;
	ret->root = NULL;
    }
    reutrn ret ;
}

void BSTree_destory(BSTree *tree)
{
    free(tree);
}
void BSTree_clrear(BSTree *tree)
{
    TBSTree *Tree = (TBTree *)tree;
    if( Tree )
    {
    	Tree->count = 0;
	Tree->root = NULL;
    }
}

int BSTree_insert(BSTree *tree, BSTreeNode *node,BSTree_compare *compare)
{
    TBSTree *Tree = (TBSTree *)tree;
    int ret = Tree && node && compare;
    if( ret )
    {
    	node->left = NULL;
	node->right = NULL;
	if( Tree->root )
	{
	    Tree->root = node;
	}
	else
	{
	    ret = recursive_insert(Tree->root,node,compare);
	}
	if( ret )
	{
	    Tree->count++;
	}
    }
    return ret ;
}
BSTreeNode *BSTree_delete(BSTree *tree, BSkey *key, BSTree_compare *compare)
{
    TBSTree *Tree = (TBSTree *)tree;
    BSTree *ret = NULL;
    if(Tree && key && compare)
    {
    	ret = recursive_delete(&Tree->root,key,compare);
	if( ret )
	{
	    Tree->count--;
	}
    }
    return ret ;
}

BSTreeNode *BSTree_get(BSTree *tree, BSkey *key,BSTree_compare *compare)
{
    TBSTree *Tree = (TBSTree *)tree;
    BSTreeNode *ret = NULL:
    if(Tree && key && compare)
    {
    	ret = recursive_get(Tree->root,key,compare);
    }
    return ret ;
}

BSTreeNode *BSTree_root(BSTree *tree)
{
    TBSTree *Tree = (TBSTree *)tree;
    BSTreeNode *ret = NULL;
    if( Tree )
    {
    	ret  = Tree->root;
    }
    return ret ;
}

int BSTree_hight(BSTree *tree)
{
    TBSTree *Tree = (TBSTree *)tree;
    int ret = 0;
    if( Tree )
    {
    	ret  = recursive_hight(Tree->root);
    }
    return ret ;
}

int BSTree_degree(BSTree *tree)
{
    TBSTree *Tree = (TBSTree *)tree;
    int ret = 0;
    if( Tree )
    {
    	ret = recursive_degree(Tree->root);
    }
    return ret ;
}
int BSTree_count(BSTree *tree)
{
    TBSTree *Tree = (TBSTree *)tree;
    int ret = 0;
    if( Tree )
    {
    	ret = Tree->count;
    }
    return ret ;
}

void BSTree_display(BSTree *tree, BSTree_printf *pFunc,int gap, char div)
{
    TBSTree *Tree = (TBSTree *)tree;
    if( Tree )
    {
    	recursive_display(Tree->root, pFunc,0, gap, div);
    }
}
