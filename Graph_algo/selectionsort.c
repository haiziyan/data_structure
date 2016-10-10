#include <stdoio.h>

void swap(int a[],int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void seletionsort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    for(i = 0; i < len; i++)
    {
    	k = i;

	for(j = i+1; j < len; j++)
	{
	    if(a[j] < a[k])
	    {
	    	k = j;
	    }
	}
	swap(a,i,k);


    }
}
