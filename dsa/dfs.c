#include<stdio.h>
#include<stdlib.h>
#define N 100
int adj[N][N]={0};
int visited[N]={0};
void dfs(int v,int n)
{
	int i;
	visited[v]=1;
	printf("%d",v);

	for(i=1;i<=n;i++)		//to visist all adjacent nodes
	{
		if(adj[v][i]==1&&!visited[i])		//for all adjacent node and nodes which r not yet visisted
		dfs(i,n);

	}
}
void display(int n)
{
	int i,j;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",adj[i][j]);
		}printf("\n");
	}
}

int main()
{

	int n,e,x,i,s,d;

	printf("Enter the no of vertices and edges\n");
	scanf("%d%d",&n,&e);

	for(i=1;i<=e;i++)
	{
		printf("Enter source and destination\n");
		scanf("%d%d",&s,&d);

		adj[s][d]=1;
		adj[d][s]=1;
	}

	printf("Enter the starting position\n");
	scanf("%d",&x);
 
	dfs(x,n);

	display(n);
return 0;
}
	
