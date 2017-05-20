/*HEAP SORT*/
#include<stdio.h>
#define N 100
void buildheap(int*,int);
void heapify(int a[],int n,int i)
{
	int lson,rson,largest_index,temp;
	largest_index=i;
	lson=2*i+1;
	rson=2*i+2;
	
	if(lson<n&&a[lson]>a[largest_index])
		largest_index=lson;

	if(rson<n&&a[rson]>a[largest_index])
		largest_index=rson;

	if(i!=largest_index)
      {	temp=a[i];
	a[i]=a[largest_index];
	a[largest_index]=temp;
	heapify(a,n,largest_index);
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
void heapsort(int a[],int n)
{
	int pass,temp;
	buildheap(a,n);
	for(pass=1;pass<n;pass++)
	{
	temp=a[n-pass];
	a[n-pass]=a[0];
	a[0]=temp;
	
	heapify(a,n-pass,0);
	}
}
						
void buildheap(int a[],int n)
{

	int i;

	for(i=n/2-1;i>=0;i--)
	{
	heapify(a,n,i);
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
	printf("Array before heap sort:");
	display(a,n);

	heapsort(a,n);
	printf("Array AFTER heap sort:");
	display(a,n);

return 0;}
