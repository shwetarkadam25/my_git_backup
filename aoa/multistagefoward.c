#include<stdio.h>
#include<stdlib.h>
#define INF  9999
#define N 50
int wt[N][N];
int visited[N];
int cost[N];
void initialization(int n,int k)
{
	int i,j;

	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		if(i!=j)
		wt[i][j]=INF;
	}
	}



	for(i=1;i<=k;i++)
	{
	for(j=1;j<=n;j++)
	{	cost[i][j]=INF;
	
	}
	}
}

void display(int n){

	int i,j;
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	printf("%d\t",wt[i][j]);
	printf("\n");
	}


}

void multistage(int n,int k)
{
	int i,j,l;

	//computing cost[] for all nodes

	for(j=n;j>=1;j--)
	{
	


}	
	
int main(){

int n,s,d,val,i,j,e,k;

	printf("Enter no. of  nodes and edges and stages\n");
	scanf("%d%d%d",&n,&e,&k);

	initialization(n,k);

	for(i=1;i<=e;i++)
	{
	printf("Enter source and destination\n");
	scanf("%d%d",&s,&d);
	
	printf("Enter value\n");
	scanf("%d",&val);
	
	if(val<wt[s][d]&&s!=d)		//to avoid paraalel loops
	wt[s][d]=val; 

	}

	display(n);

return 0;}
