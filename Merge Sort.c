#include<stdio.h> //merge sort
void merge(int [],int ,int ,int );
void part(int [],int ,int );
int size;
int main()
{
	int arr[30];
 	int i;
 	printf("Enter the size::");
 	scanf("%d",&size);
 	printf("Enter the elements::");
 	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("\n!!!!!!!!!!!!!!Unsorted Elements!!!!!!!!!!!!!!!!!!!!!\n");
 	for(i=0;i<size;i++)
 		printf("%d ",arr[i]);
 	printf("\n");
	printf("\n!!!!!!Partitions!!!!!!!!!!\n");
 	part(arr,0,size-1);
 	return 0;
}

void part(int arr[],int min,int max)
{
	int i,mid;
	for(i=min;i<=max;i++)
		printf("%d ",arr[i]);
	printf("\n");
 	if(min<max)
 	{
		mid=(min+max)/2;
	 	part(arr,min,mid);
	 	part(arr,mid+1,max);
	 	merge(arr,min,mid,max);
 	}
}

void merge(int arr[],int min,int mid,int max)
{
	int tmp[30];
	int i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min;j<=mid && m<=max;i++)
	{
		if(arr[j]<=arr[m])
		{
		 	tmp[i]=arr[j];
			j++;
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j;k<=mid;k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	for(k=min;k<=max;k++)
		arr[k]=tmp[k];
	printf("\n!!!!!!!1Status of partitions!!!!!!!!\n");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
 	printf("\n");
}
