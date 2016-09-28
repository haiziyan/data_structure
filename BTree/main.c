#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

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
