/*SELECTION SORT*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
void selectionsort(int a[],int n)
{
	int min,pos,pass,i;
	
	
	for(pass=0;pass<n-1;pass++)
	{
		min=a[pass];
		pos=pass;
		i=pass+1;
		while(i<n)
		{
			if(min>a[i])
			{
				min=a[i];
				pos=i;
			}
		i++;
		}
		
		a[pos]=a[pass];
		a[pass]=min;
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
	printf("Array before selection sort:");
	display(a,n);
	selectionsort(a,n);
	printf("Array AFTER selection sort:");
	display(a,n);

return 0;
}

