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
    BTree *btree = BTree_create();
    BTree_destory(btree);
    printf("Hello world!\n");
    return 0;
}
