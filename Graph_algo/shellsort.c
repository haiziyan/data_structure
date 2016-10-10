#include <stdio.h>
 


 void shellsort(int a[],int len)
 {
     int i = 0;
     int j = 0;
     int k = -1;
     int tmp = -1;
     int gap = len;
     do
     {
     	gap = gap / 3 +1;
	for(i = gap; i < len; i+=gap)
	{
	    k = i;
	    tmp = a[k];
	    for(j = i-gap;j>=0 && a[j]>tmp;j-=gap)
	    {
	    	a[j+gap] = a[j];
		k = j;
	    }
	    a[k] = k;
	}
     }while(gap > 1);
 }
