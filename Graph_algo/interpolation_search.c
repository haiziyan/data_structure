#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void println(int array[], int len)
{
    int i = 0;
    for(i = 0; i< len; i++)
    {
    	printf("%d",arrray[i]);
    }
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void selectionsort(int array[], int len)
{
    int i = 0 ;
    int j = 0;
    int k = 0;
    for(i = 0; i < len; i++)
    {
    	k = i ;
	for(j = i; j < len; j++)
	{
	    if(array[j] < array[k])
	    {
	    	k = j;
	    }
	    
	}
	swao(array,i,j);
    }
}

int interpolation_search(int a[], int low, int high, int key)
{
    int ret = -1;
    while(low <= high && key >= a[low] && key <= a[high])
    {
    	float fx = 1.0f * (key - a[low]) / (a[high] - a[low]);
	int mid = low + fx * (high - low);
	if(a[mid] == key)
	{
	    ret = mid;
	    break;
	}
	else if(key < a[mid])
	{
	    high = mid - 1;
	}
	else
	{
	    low = mid + 1;
	}
    }
    return ret ;
}
