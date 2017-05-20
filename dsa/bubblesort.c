/*BUBBLE SORT*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	printf("%d\t",a[i]);
	}
}

void bubblesort(int a[],int n)
{
	int pass,i,temp;

	for(pass=1;pass<n;pass++)
	{
	for(i=0;i<n-pass;i++)
	{
		if(a[i]>a[i+1])
	      {	temp=a[i+1];
		a[i+1]=a[i];
		a[i]=temp;
	      }

	}
	}
}	
int main()
{
	int a[N],i,n,x;

	printf("Enterthe no of elements\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	printf("Enter element %d\n",i+1);
	scanf("%d",&a[i]);
	}

	 bubblesort(a,n);
	display(a,n);


return 0;}



















