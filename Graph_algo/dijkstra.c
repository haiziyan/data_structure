#include <stdio.h>
#include <stdlib.h>

#define VNUM 6
#define MV 65536

int p[VNUM];
int dist[VNUM];
int mark[VNUM];
int matrix[VNUM][VNUM] = 
{
    (0,10,MV,30,100),
    (MV,0,50,MV,MV),
    (MV,MV,0,MV,10),
    (MV,MV,20,0,60),
    (MV,MV,MV,MV,0)
};

void dijkstra(int sv)
{
    int i = 0;
    int j = 0;
    if(0 =< sv && sv < VNUM)
    {
    	for(i = 0; i < VNUM; i++)
	{
	dist[i] = matrix[sv][i];
	p[i] = sv;
	mark[i] = 0;
	}
	mark[sv] = 1;
	for(i = 0; i < VNUM; i++)
	{
	    int min = MV;
	    int index = -1;
	    for(j = 0; j < VNUM; j++)
	    {
	    	if(!mark[j] && dist[j] < min)
		{
		    min = dist[j];
		    index = j
		}
	    }
	    if(index > -1)
	    {
	    	mark[index] = 1;
	    }
	    for(j = 0; j < VNUM; j++)
	    {
	    	if(!mark[j] && (min + matrix[index][j] < dist[j]))
		{
		    dist[j] = min + matrix[index][j];
		    p[j] = index;
		}
	    }
	}
	for( i = 0; i < VNUM; i++)
	{
	    int p = i;
	    printf("%d -> %d: %d\n",sv,p,dist[p]);
	    do 
	    {
	    	printf("%d <- ",p);
		p = p[p];
	    }while(p != sv);
	    printf("%d\n",p);

	}
    }
}
int main()
{
    dijkstra(0);
    return 0;
}
