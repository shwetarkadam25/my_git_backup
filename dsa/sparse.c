#include<stdio.h>
#include<stdlib.h>
#define N 50
int a[N][N];
int compact[N][N];

void display(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	printf("%d\t",a[i][j]);
	
	printf("\n");

	}
}

int main(){

int n,i,j,size=0,k=0;

printf("Enter size of the matrix\n");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
	printf("Enter value\n");
	scanf("%d",&a[i][j]);
	}
}


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
	if(a[i][j]!=0)
	size++;
}
}

compact[3][size];

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
	if(a[i][j]!=0)
	{
	compact[0][k]=i;			//fill the row no
	compact[1][k]=j;			//column no.
	compact[2][k]=a[i][j];			//value
	k++;
	}
	}
}


display(n);

printf("\n\n");

for(i=0;i<3;i++)
{
	for(j=0;j<size;j++)
	{
		printf("%d\t",compact[i][j]);
	}printf("\n");
}



return 0;}
