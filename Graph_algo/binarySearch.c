#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void println(int array[], int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
    	printf("%d",array[i]);
    }
    printf("\n");
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void selectionsort(int array[], int len)
{
    int j = 0 ;
    int i = 0;
    int k = -1;
    for(i = 0; i < len; i++)
    {
    	k = i;
	for(j = i; j < len; j++)
	{
	    if(array[j] < array[k])
	    {
	    	k = j;
	    }
	}
	swap(array,i,k);
    }
}

int binary_search(int a[], int low, int high, int key)
{
    int ret = -1;
    if(low <= high)
    {
    	int mid = (low + high) / 2;
	if(a[mid] == key)
	{
	    ret = mid;

	}
	else if(key < a[mid])
	{
	    ret = binary_search(a,low,mid-1,key);
	}
	else
	{
	    ret = binary_search(a,mid+1,high,key);
	}
    }
    return ret;
}

int binary_search_ex(int a[]. int low, int high, int key)
{
    int ret = -1;
    while(low <= high)
    {
    	int mid = (low + high) / 2;
	if(a[mid] == key)
	{
	    ret = mid;
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


int main()
{
   int a[SIZE] = {0};
   int i = 0;
   int key = 0;
   int index = -1;
   srand((unsigned int)time(NULL));
   for(i = 0; i < SIZE; i++)
   {
   	a[i] = rand() % 100;
   }
   key = 50;
   selectsort(a,SIZE);
   println(a);
   index = binary_search(a, 0, SIZE-1, key);
   if(index >= 0)
   {
   	printf("%d",index);
   }
   return ret ;
}
