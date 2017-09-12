#include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a,int start,int end)
{int i;
    int pivot=a[end];
    int partitionindex=start;
    for( i=start;i<end;i++)
    {

        if(a[i]<=pivot){swap(&a[i],&a[partitionindex]); partitionindex++;}
    }
    swap(&a[partitionindex],&a[end]);
    return partitionindex;

}
void quicksort(int *a,int start,int end)
{

    if(start<end)
    {
        int partitionindex=partition(a,start,end);
        quicksort(a,start,partitionindex-1);
        quicksort(a,partitionindex+1,end);

    }
}

int main(void) {
    int i;
    	int a[]={7,6,5,4,3,2,1,0};
	quicksort(a,0,7);
	for(i=0;i<=7;i++)
	printf("%d ",a[i]);
	// your code goes here
	return 0;
}
