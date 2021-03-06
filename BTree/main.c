#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "LinkQueue.c"
struct Node
{
    BTreeNode header;
    char v;
};
void printf_data(BTreeNode *node)
{
    if(node != NULL)
    {
        printf("%c",((struct Node*)node)->v);
    }
}
//前序遍历
void pre_order_traversal(BTreeNode *root)
{
    if(root != NULL)
    
    {
    	printf("%c",((struct Node *)root)->v);
	pre_order_traversal(root->left);
	pre_order_traversal(root->right);
    }
}
//中序遍历
void middle_order_traversal(BTreeNode *root)
{
    if(root != NULL)
    {
    	middle_order_traversal(root->left);
	printf("%c",((struct Node *)root)->v);
	middle_order_traversal(root->right);
    }
}
//后序遍历
void post_order_traversal(BTreeNode *root)
{
    if(root != NULL)
    {
    	post_order_traversal(root->left);
	post_order_traversal(root->right);
	printf("%c",((struct Node *)root)->v);
    }
}
//层次遍历二叉树#利用队列#
void level_order_traversal(BTreeNode *root)
{
    if(root != NULL)
    {
    	LinkQueue *queue = LinkQueue_Create();
	if(queue != NULL)
	{
	    LinkQueue_Append(queue,root);
	    while(LinkQueue_length(queue)>0)
	    {
	    	struct Node *node = (struct Node *)LinkQueue_Retrieve(queue);
		printf("%c",node->v);
		LinkQueue_Append(queue,node->header.left);
		LinkQueue_Append(queue,node->header.right);

	    }
	}
	LinkQueue_Destory(queue);
    }
}
//线索化二叉树#利用结点中的空结点#
void thread_via_left(BTreeNode *root, BTreeNode **pp)
{
    if(root != NULL && pp != NULL)
    {
    	if(*pp != NULL)
	{
	    (*pp)->left = root;
	    *pp = NULL;
	}
	if(root->left == NULL)
	{
	    *pp = root ;
	}
	thread_via_left(root->left,pp);
	thread_via_left(root->right, pp);
    }
}
//线索化二叉树#运用线性表#
void thread_via_list(BTreeNode *root, SeqList *list)
{
    if(root != NULL && list != NULL)
    {
    	SeqList_Insert(list, (SeqListNode *)root, SeqLIist_Length(list));
	thread_via_list(root->left,list);
	thread_via_list(root->right,list);
    }
}
int main()
{
    BTree* tree = BTree_create();
    
    struct Node n1 = {{NULL, NULL}, 'A'};
    struct Node n2 = {{NULL, NULL}, 'B'};
    struct Node n3 = {{NULL, NULL}, 'C'};
    struct Node n4 = {{NULL, NULL}, 'D'};
    struct Node n5 = {{NULL, NULL}, 'E'};
    struct Node n6 = {{NULL, NULL}, 'F'};
    
    BTree_insert(tree, (BTreeNode*)&n1, 0, 0, 0);
    BTree_insert(tree, (BTreeNode*)&n2, 0x00, 1, 0);
    BTree_insert(tree, (BTreeNode*)&n3, 0x01, 1, 0);
    BTree_iInsert(tree, (BTreeNode*)&n4, 0x00, 2, 0);
    BTree_iInsert(tree, (BTreeNode*)&n5, 0x02, 2, 0);
    BTree_insert(tree, (BTreeNode*)&n6, 0x02, 3, 0);
    
    printf("Height: %d\n", BTree_height(tree));
    printf("Degree: %d\n", BTree_degree(tree));
    printf("Count: %d\n", BTree_count(tree));
    printf("Position At (0x02, 2): %c\n", ((struct Node*)BTree_get(tree, 0x02, 2))->v);
    printf("Full Tree: \n");
    
    BTree_display(tree, printf_data, 4, '-');
    
    BTree_delete(tree, 0x00, 1);
    
    printf("After Delete B: \n");
    printf("Height: %d\n", BTree_height(tree));
    printf("Degree: %d\n", BTree_degree(tree));
    printf("Count: %d\n", BTree_count(tree));
    printf("Full Tree: \n");
    
    BTree_display(tree, printf_data, 4, '-');
    
    BTree_clear(tree);
    
    printf("After Clear: \n");
    printf("Height: %d\n", BTree_height(tree));
    printf("Degree: %d\n", BTree_degree(tree));
    printf("Count: %d\n", BTree_count(tree));
    
    BTree_display(tree, printf_data, 4, '-');
    
    BTree_destroy(tree);
    
	return 0;
}
