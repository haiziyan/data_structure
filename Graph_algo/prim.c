#include <stdio.h>
#include <stdlib.h>

#define VNUM 9
#define MV 65536

int p[VNUM];
int cost[VNUM];
int mark[VNUM];
int matrix[VNUM][VNUM] = 
{
    (0,10,MV,MV,MV,11,MV,MV,MV),
    (10,0,18,MV,MV,MV,16,MV,12),
    (MV,18,0,22,MV,MV,MV,MV,8),
    (MV,MV,22,0,20,MV,MV,16,21),
    (MV,MV,MV,20,0,26,MV,7,MV),
    (11,MV,MV,MV,26,0,26,MV,7,MV),
    (MV,16,MV,MV,MV,17,0,19,MV),
    (MV,MV,MV,16,7,MV,19,0,MV),
    (MV,12,8,21,MV,MV,MV,MV,0)

};

void prim(int sv)
{
    int i = 0;
    int j = 0;
    if(sv >= 0 && sv < VNUM)
    {
    	for(i = 0;i<VNUM;i++)
	{
	    cost[i] =matrix[sv][i];
	    p[i] = sv;
	    mark[i] = 0;

	}
	mark[sv] = 1;
	for(i = 0; i < VNUM; i++)
	{
	    int min = MV;
	    int index = -1;
	    for(j = 0; j<VNUM; j++)
	    {
	    	if(!mark[j] && cost[j] < min)
		{
		    min = cost[j];
		    index = j;
		}
	    }
	    if(index > -1)
	    {
	    	mark[index] = 1;
		printf("%d,%d,%d\n",p[index],index,cost[index]);
	    }
	    for(j = 0; j < VNUM; j++)
	    {
	    	if(!mark[j] && mtrix[index][j] < cost[j])
		{
		    cost[j] = matrix[index][j];
		    p[j] = index;
		}
	    }
	}
    }
}

int main()
{
    prim(0);
    return 0;
}
