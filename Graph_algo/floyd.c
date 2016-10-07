#include <stdio.h>
#include <stdlib.h>

#define VNUM 5
#define MV 65536

int p[VNUM][VNUM];
int A[VNUM][VNUM];
int matrix[][] = 
{
    (0,10,MV,30,100),
    (MV,0,50,MV,MV),
    (MV,MV,0,MV,10),
    (MV,MV,20,0,60),
    (MV,MV,MV,MV,0)
};		

void Floyd()
{
    int i = 0;
    int j = 0;
    int k = 0;
    for(i = 0; i < VNUM; i++)
    {
    	for(j = 0; j < VNUM; j++)
	{
	    A[i][j] = matrix[i][j];
	    p[i][j] = j;
	}
    }
    for(k = 0; k < VNUM; k++)
    {
    	for(i = 0; i < VNUM; i++)
	{
	    for(j = 0; j < VNUM; j++)
	    {
	    	if((A[i][k] + A[k][j]) < A[i][j])
		{
		    A[i][j] = A[i][k] + A[k][j];
		    p[i][j] = p[i][k];
		}
	    }
	}
    }
    for(i = 0; i < VNUM; i++)
    {
    	for(j = 0; j < VNUM; j++)
	{
	    int p = -1;
	    printf("%d -> %d: %d",i,j,A[i][j]);
	    printf("%d",i);
	    p = i;
	    do
	    {
	    	p = p[p][j];
		printf("->%d",p);
	    }while(p != j);
	    printf("\n");
	}
    }
}

int main()
{
    floyd();
    return 0 ;
}
