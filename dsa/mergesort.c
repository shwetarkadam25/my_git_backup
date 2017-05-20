/*MERGE SORT*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
void display(int a[],int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

}
void merging(int a[],int low,int mid,int mid_1,int high)
{
	int i=low,j=mid_1,k=0,c[N];

	while(i<=mid&&j<=high)
	{
	if(a[i]<a[j])
	c[k++]=a[i++];

	else
	c[k++]=a[j++];

	}

	while(i<=mid)
	c[k++]=a[i++];

	while(j<=high)
	c[k++]=a[j++];

	for(i=low,k=0;i<=high;i++,k++)
	{
		a[i]=c[k];
	}
}	
void mergesort(int a[],int low,int high)
{
	int mid;
	mid=low+high/2;

	if(low==high)
	return ;
		
	else{
	mergesort(a,low,mid);
	printf("THE sub merged array is\n");
	display(a,mid+1);
	
	printf("THE sub merged array is\n");
	mergesort(a,mid+1,high);
	display(a,high);
	}

	merging(a,low,mid,mid+1,high);
}

int main()
{
	int a[N];
	int i,n,low ,high,mid;

	printf("Enter the no of elements\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	printf("Enter element %d",i+1);
	scanf("%d",&a[i]);

	}

	low=0;
	high=n-1;
	
	mergesort(a,low,high);



return 0;}

