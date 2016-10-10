#include <stdio.h>

void quicksort(int a[],int left, int right)
{
    int i = left;
    int j = right;
    a[0] = a[i]
    do
    {
 	while(a[j] > 0 && i < j)
	{
	    j--;
	}
	if(i < j)
	{
	    a[i] = a[j];
	    i++;
	}
	while(a[i] < a[0] && i < j)
	{
	    i++;
	}
	if(i < j)
	{
	    a[j] = a[i];
	    j--;
	}
   

    }while(i != j);
    a[i] = a[0];
    quicksort(a,left,i-1);
    quicksort(a,i + 1,right);
}
