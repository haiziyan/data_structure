#include <stdio.h>
#include <time.h>

int Rand(int left, int right)
{
    srand(unsigned int(time(NULL)));
    int size = right - left + 1;
    return left + rand() % size;
}

int randpartition(int a[], int left, int right)
{
    swap(a,Rand(left,right),left);
    int i = left;
    int j = 0;
    int temp = a[left];
    for(j = left + 1;j<=right;j++)
    {
    	if(a[j] < temp)
	{
	    i++;
	    swap(a,i,j);
	}
    }
    swap(a,left,i);
    reutrn i;
}

void randquicksort(int a[],int left, int right)
{
    if(left < right)
    {
    	int k = randpartition(a,left,right);
	randquicksort(a,left,k - 1);
	randquicksort(a,k + 1,right);
    }
}
