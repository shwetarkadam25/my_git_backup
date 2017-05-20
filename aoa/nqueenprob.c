#include<stdio.h>
#include<stdlib.h>
#define N 50
#define queen 25
int col[50],count,n;
void solution(){

int i,j,k;

for(i=1;i<=n;i++)
{	for(j=1;j<col[i];j++)
	printf("x\t");
	printf("q%d\t",i);

	for(;j<n;j++)
	printf("x\t");
	printf("\n");
}
}


int place(int q,int c)
{
int k;

for(k=1;k<=q-1;k++)
{
	if(col[k]==c||abs(k-q)==abs(col[k]-c))
	return 0;
	
	else 
	return 1;}

}
void nqueen(int q)
{
	int c,i;

	for(c=1;c<=n;c++)
	{
		if(place(q,c))
		{
		col[q]=c;
		if(q==n)
		{
		count++;
		printf("**********SOLution %d*************\n",count);
		solution();
		}
}
		else
		nqueen(q+1);
	
	
	}
}	
int main(){

int i,flag;

	printf("Enter the size of the board\n");
	scanf("%d",&n);


	nqueen(1);

return 0;}


