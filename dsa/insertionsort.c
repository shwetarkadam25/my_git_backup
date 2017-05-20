/*INSERTION SORT*/
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

/*void insertion(int a[],int n)
{
	int pass,i,x;

	for(pass=1;pass<n;pass++)
	{
		x=a[pass];
		i=pass-1;
		while(i>=0)
		{
			if(a[i]<x)
			break;

			else{
			a[i+1]=a[i];
			}
		i--;
	}
	a[i+1]=x;
	}
}
*/
int main()
{
	int a[N],i,n,x;

	printf("Enterthe noof elements\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	printf("Enter element %d",i+1);
	scanf("%d",&a[i]);
	}

	insertion(a,n);

	display(a,n);

return 0;}

