#include <stdio.h>

void intertionsort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int k = -1;
    int tmp = -1;
    for(i = 0; i < len; i++)
    {
    	k = i;
	tmp = a[k];
	for(j = i - 1; j>=0&&a[j]>tmp;j--)
	{
	    a[j+1] = a[j];
	    k = j;
	}
	a[k] = tmp;
    }
}
