#include <stdio.h>

void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void bubblesort(int a[],int len)
{
    int i = 0;
    int j = 0;
    int exchange = 1;
    for(i = 0; i < len && exchange; i++)
    {
    	exchange = 0;
	for(j = len - 1;j > i;j--)
	{
	    if(a[j] < a[j-1])
	    {
	    	swap(a,j,j-1);
		exchange = 1;
	    }
	}
    }
}
