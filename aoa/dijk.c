//DIJKSTRA'S ALGORITHM

#include<stdio.h>
#include<stdlib.h>
#define N 100
#define INF 999
int adj[N][N];		//representation of graph
int visited[N];		//to mark a node as visited
int cost[N][N];		//to store the distance of each node from the source node
int dist[N];
int pred[N];

void display_adj(int n)	// no. of nodes 
{
	int i,j;

	printf("\nAdjacency MATRIX:-\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		printf("%d\t",adj[i][j]);
	}printf("\n");
	}
}
void display_cost(int n)	// no. of nodes 
{
	int i,j;

	printf("\nCOST MATRIX:-\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		printf("%d\t",cost[i][j]);
	}printf("\n");
	}
}

void display_result(int n)
{
	int i;

	printf("\nThe FINAL Result is:-");
	printf("\nVERTEX:\t\t\t");
	for(i=1;i<=n;i++)
	printf("%d\t",i);
	
	printf("\nDISTANCE FROM SOURCE:-\t");
	for(i=1;i<=n;i++)
	printf("%d\t",dist[i]);

	printf("\nPREDECESSOR:-\t\t");
	for(i=1;i<=n;i++)
	printf("%d\t",pred[i]);

}	

void dijkstra(int source,int n)
{
	
	int i,k,j,mindist=INF,current,count=0;
	visited[source]=1;				//mark source as visited 
	for(k=1;k<=n;k++)
	{

	for(i=1;i<=n;i++)
	{
		if(mindist>dist[i]&&!visited[i])		//to find node of min wt. and which is not yet visited
		{
			mindist=dist[i];
			current=i;
		}
	
	}
	
	
	visited[current]=1;
	
	
	for(j=1;j<=n;j++){

	if(visited[j]==0)				//checks whther node is unvisited
	{
		if((mindist+cost[current][j])<dist[j])		//checks whter the selected pth has min wt or no
		{
			dist[j]=mindist+cost[current][j];		//update the dist table
			pred[j]=current;				//update pred table

		}
	}		

	}
	
	mindist=INF;
	

	}

	
}


		
void initialization(int source,int n)	 
{
	int i,j;
	

	//cost matrix
	for(i=1;i<=n;i++)
	{
	for(j=0;j<=n;j++)
	{
		if(adj[i][j]==0)		//no cost present
		cost[i][j]=INF;
		else
		cost[i][j]=adj[i][j];
	}
	}

	//filling of dist[] and pred[]
	for(i=1;i<=n;i++)
	{
		dist[i]=cost[source][i];		//dist from source to ever other node (2nd column of table)
		pred[i]=source;
	}
	visited[source]=1;				//mark source node as visited
	dist[source]=0;					//dist from source node OR to itself is zero


}
int main(){

int e,n,x,i,j,s,d,coste,k;


	printf("Enter the of nodes and edges respectively\n");
	scanf("%d%d",&n,&e);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		adj[i][j]=999;
		}
	}

	for(i=1;i<=e;i++)
	{
	printf("Enter the source and destination\n");
	scanf("%d%d",&s,&d);
	
	
	printf("Enter the cost\n");
	scanf("%d",&coste);
	adj[s][d]=coste;
	
	}
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		{
		
		if(j==k)
		adj[j][k]=0;		//distance or cost of a node from itself is zero
		}
	}

	
	printf("Enter the starting node[source node]\n");
	scanf("%d",&x);

	initialization(x,n);
	dijkstra(x,n);
	display_adj(n);
	display_cost(n);
	display_result(n);
return 0;}

/*OUTPUT******
Enter the of nodes and edges respectively
6
11
Enter the source and destination
1
2
Enter the cost
2
Enter the source and destination
1
3
Enter the cost
8
Enter the source and destination
2
3
Enter the cost
5
Enter the source and destination
3
2
Enter the cost
6
Enter the source and destination
2
4
Enter the cost
3
Enter the source and destination
4
3
Enter the cost
1
Enter the source and destination
3
5
Enter the cost
6
Enter the source and destination
4
5
Enter the cost
7
Enter the source and destination
5
4
Enter the cost
4
Enter the source and destination
4
6
Enter the cost
6
Enter the source and destination
6
5
Enter the cost
2
Enter the starting node[source node]
1

Adjacency MATRIX:-
0	2	8	999	999	999	
999	0	5	3	999	999	
999	6	0	999	6	999	
999	999	1	0	7	6	
999	999	999	4	0	999	
999	999	999	999	2	0	

COST MATRIX:-
999	2	8	999	999	999	
999	999	5	3	999	999	
999	6	999	999	6	999	
999	999	1	999	7	6	
999	999	999	4	999	999	
999	999	999	999	2	999	

The FINAL Result is:-
VERTEX:			1	2	3	4	5	6	
DISTANCE FROM SOURCE:-	0	2	6	5	12	11	
PREDECESSOR:-		1	1	4	2	4	4	

*/

