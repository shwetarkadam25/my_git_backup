/*QUICK SORT*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
int partition(int a[],int low,int high)
{
	int x,up,down,temp;

	x=a[low];
	down=low;
	up=high;
	while(down<up)		//process continues till  up and down dont cross each other
     {	while(a[down]<=x&&down<=high)		//down shouldnt cross sub array 
	{
		down++;
	}
	while(a[up]>x&&up>=low)		//up shouldnt cross the sub array 
	{							
		up--;
	}
	
	if(down<up)
	{
		temp=a[down];
		a[down]=a[up];
		a[up]=temp;
	}

     }

	a[low]=a[up];
	a[up]=x;

	return up;
}
	
void quicksort(int a[],int low, int high)
{
	int j;
	if(low==high)
	return;

	else{

	j=partition(a,low,high);
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);

	}

}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	printf("%d\t",a[i]);
	}
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

	quicksort(a,low,high);

	display(a,n);

return 0;}









