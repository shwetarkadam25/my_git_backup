//BELLMAN FORD

#include<stdio.h>
#include<stdlib.h>
#define INF 999
int adj[50][50];
int dist[50];			//dist array
int pred[50];			//predecessor 

void initialization(int n)
{
	int i,j;
	//initializing adj matrix
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		if(i==j)
		adj[i][j]=0;

		else
		adj[i][j]=INF;
	}
	}

	//initializing dist array
	for(i=1;i<=n;i++)	
	{dist[i]=INF;
	pred[i]=0;
	}
	
}
void display_result(int n, int x)
{
	int i,j;
	printf("\n\nThe Result is");

	printf("\nPATH\t\tDISTANCE\tPREDECESSOR\n");
	for(i=1;i<=n;i++)
	printf("\n%d -> %d\t\t %d\t\t%d",x,i,dist[i],pred[i]);


}


void bellman(int n)
{
	int u,v,k;

	for(k=1;k<=n;k++)			//iteration no.
	{
	for(u=1;u<=n;u++)				//source u
	{
	for(v=1;v<=n;v++)
	{
		if(dist[v]>dist[u]+adj[u][v])		//if a min dist is found
		{
		dist[v]=dist[u]+adj[u][v];		//update the dist
		pred[v]=u;				//update pred
		}
	
	}
	}
	}
}				
	
void display(int n)
{
	int i,j;
	printf("\nThe Graph is :-\n");
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d\t",adj[i][j]);
		printf("\n");
	}
	//dispay dist
	printf("\n\nThe distance array is\n");
	printf("ITERATION\t");
	for(i=1;i<=n;i++)
	printf("%d\t",i);
	printf("\n");
	printf("DISTANCE\t");
	for(i=1;i<=n;i++)
	printf("%d\t",dist[i]);


	
	printf("\n\nThe predecessor array is\n");
	printf("ITERATION\t");
	for(i=1;i<=n;i++)
	printf("%d\t",i);
	printf("\n");
	printf("PREDECESSOR\t");
	for(i=1;i<=n;i++)
	printf("%d\t",pred[i]);
	
	
}
int main(){

int s,d,i=0,ch=1,n,val,x,e;

	printf("Enter the no of nodes and edges\n");
	scanf("%d%d",&n,&e);

	initialization(n);

	for(i=1;i<=e;i++)			//entering of weights
	{
	printf("Enter source and destination\n");
	scanf("%d%d",&s,&d);
	printf("Enter weight\n");	
	scanf("%d",&val);

	adj[s][d]=val;
	
	}
	
	printf("Enter the  starting node\n");
	scanf("%d",&x);

	dist[x]=0;
	display(n);

	bellman(n);

	display_result(n,x);

return 0;}

/*OUTPUT

Enter the no of nodes and edges
4
6
Enter source and destination
1
2
Enter weight
5
Enter source and destination
2
1
Enter weight
3
Enter source and destination
2
4
Enter weight
4
Enter source and destination
3
4
Enter weight
6
Enter source and destination
4
1
Enter weight
-1
Enter source and destination
1
3
Enter weight
2
Enter the  starting node
1

The Graph is :-
0	0	5	2	
0	3	0	999	
0	999	999	0	
0	-1	999	999	


The distance array is
ITERATION	1	2	3	4	
DISTANCE	0	999	999	999	

The predecessor array is
ITERATION	1	2	3	4	
PREDECESSOR	0	0	0	0	

The Result is
PATH		DISTANCE	PREDECESSOR

1 -> 1		 0		0
1 -> 2		 5		1
1 -> 3		 2		1
1 -> 4		 8		3*/
	


