#include<stdio.h>
#include<math.h>
void printarr(int arr[],int n)
{
int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		if(j==arr[i]){
			printf("%d\t",arr[i]);
		}
		else
			printf("X\t");
	}
		printf("\n");
}
printf("\n\n");
}
int place(int col[],int q,int c)
{
	int k;
	for(k=1;k<=q-1;k++)
	{
		if(c==col[k]||abs(k-q)==abs(col[k]-c))
			return 0;
	}
	return 1;
}
void nqueen(int col[],int q,int n)
{
	int c;
	for(c=1;c<=n;c++)
	{
		if(place(col,q,c))
		{
			col[q]=c;
			if(q==n)
			{
				printarr(col,n);
			}
			else
			nqueen(col,q+1,n);
		}
	}

}
int main()
{
	int n;
	printf("Enter number of queen");
	scanf("%d",&n);
	int col[30]={0};
	nqueen(col,1,n);
	
}
