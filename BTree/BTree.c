typedef struct _tag_TBTree
{
    int count ;
    BTreeNode *root;
}TBTree;

static int recursive_count(BTreeNode *root)
{
    int ret = 0;
    if(root != NULL)
    {
        ret = recursive_count(root->left) + 1 + recursive_count(root->right);
    }
    return ret ;
}
static int recursive_hight(BTreeNode *root)
{
    int ret = 0;
    if(root != NULL)
    {
        int lh = recursive_hight(root->left);
        int rh = recursive_hight(root->right);
        ret = ((lh >rh )? lh : rh)+1;
    }
    return ret ;
}

static int recursive_degree(BTreeNode *root)
{
    int ret = 0;
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            ret++;
        }
        if(root->right != NULL)
        {
            ret++;
        }
        if(ret != 1)
        {
            int ld = recursive_degree(root->left);
            int rd = recursive_degree(root->right);
            if(ret <ld)
            {
                ret = ld;
            }
            if(ret <rd)
            {
                ret = rd;
            }

        }
    }
    return ret ;
}
static void recursive_display(BTreeNode *root, BTree_printf *pFunc, int format, int gap, char div)
{
    int i = 0;
    if(root != NULL && pFunc != NULL)
    {
        for(i=0; i<format; i++)
        {
            printf("%c",div);
        }
        pFunc(root);
        printf("\n");
        if(root->left != NULL || root->right != NULL)
        {
            recursive_display(root->left,pFunc,format+gap, gap, div);
            recursive_display(root->right,pFunc,format+gap, gap, div);
        }

    }
    else
    {
        for(i=0; i<format; i++)
        {
            printf("%c",div);
        }
        printf("\n");
    }
}
BTree *BTree_create()
{
    TBTree *ret = (TBTree *)malloc(sizeof(TBTree));
    if( ret )
    {
        ret->count = 0;
        ret->root = NULL;

    }
    return ret ;
}

void BTree_destory(BTree *tree)
{
    free(tree);
}

void BTree_clear( BTree *tree)
{
    TBTree *btree = (TBTree *)tree;
    if(btree)
    {
        btree->count = 0;
        btree->root = NULL;
    }
}

int BTree_insert(BTree *tree, BTreeNode *node, BTpos pos, int count, int flag)
{
    int ret = 0;
    TBTree *btree = (TBTree*)tree;
    ret = (btree != NULL)&&(node != NULL)&&((flag == BT_LEFT)||(flag == BT_RIGHT));
    int bit = 0;
    if( ret )
    {
        BTreeNode *parent = NULL;
        BTreeNode *current = btree->root;
        while(count > 0 && current != NULL)
        {
            bit = pos & 1;
            pos = pos >> 1;
            parent = current;
            if(bit == BT_LEFT)
            {
                current = current->left;
            }
            else if(bit == BT_RIGHT)
            {
                current = current->right;
            }
            count--;
        }
        if(flag == BT_LEFT)
        {
            node->left = current;
        }
        else if(flag == BT_RIGHT)
        {
            node->right = current;
        }
        if(parent != NULL)
        {
            if(bit == BT_LEFT)
            {
                parent->left = node;
            }
            else if(bit == BT_RIGHT)
            {
                parent->right = node;
            }
        }
        else
        {
            btree->root = node;
        }
        btree->count++;
    }
    return ret ;
}

BTreeNode *BTree_delete(BTree *tree,BTpos pos, int count )
{
    TBTree *btree = (TBTree *)tree;
    int bit = 0;
    BTreeNode *ret = NULL;

    if(btree != NULL)
    {
        BTreeNode *parent = NULL;
        BTreeNode *current = btree->root;
        while(count >0 && current != NULL)
        {
            bit = pos & 1;
            pos = pos >> 1;
            parent = current ;
            if(bit == BT_LEFT)
            {
                current = current->left;
            }
            if(bit == BT_RIGHT)
            {
                current = current->right;
            }
            count--;
        }
        if(parent != NULL)
        {
            if(bit == BT_LEFT)
            {
                parent->left = NULL;
            }
            else if(bit == BT_RIGHT)
            {
                parent->right = NULL;
            }

        }
        else
        {
            btree->root = NULL;
        }
        ret = current ;
        btree->count = btree->count - recursive_count( ret );


    }
    return ret ;
}

BTreeNode *BTree_get(BTree *tree , BTpos pos, int count )
{
    TBTree *btree = (TBTree *)tree;
    BTreeNode *ret = NULL;
    if(btree)
    {
        int bit = 0;
        BTreeNode *current = btree->root;
        while(count >0 && current != NULL)
        {
            bit = pos & 1;
            pos = pos >> 1;
            if(bit == BT_LEFT )
            {
                current = current->left;

            }
            else if(bit == BT_RIGHT)
            {
                current = current->right;
            }
            count--;
        }
        ret = current ;
    }
    return ret ;
}

BTreeNode *BTree_root(BTree *tree)
{
    TBTree *btree = (TBTree *)tree;
    BTreeNode *ret = NULL;
    if(btree)
    {
        ret = btree->root;
    }
    return ret ;
}

int BTree_hight(BTree *tree)
{
    TBTree *btree = (TBTree *)tree;
    int ret = 0;
    if(btree)
    {
        ret = recursive_hight(btree->root);
    }
    return ret ;
}

int BTree_degree(BTree *tree)
{
    TBTree *btree = (TBTree *)tree;
    int ret = 0;
    if(btree)
    {
        ret = recursive_degree(btree->root);
    }
    return ret ;
}

void BTree_display(BTree *tree, BTree_printf *pFunc, int gap, char div)
{
    TBTree *btree = (TBTree *)tree;
    if(btree != NULL)
    {
        recursive_display(btree->root,pFunc,0,gap, div);
    }
}
