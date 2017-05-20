#include<stdio.h>
#include<stdlib.h>
#define N 100 
#define INF 99999 
int adj[N][N];
int visited[N];
void initialization(int n)
{
	int i,j;

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
}


void display(int n)
{
	int i,j;

	printf("\nThe graph is\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	printf("%d\t",adj[i][j]);
	printf("\n");
	}
}


void prim(int n){

int i,j,min,u,v,k;
int total=0;

	visited[1]=1;
	for(k=1;k<n;k++){
	for(i=1;i<=n;i++)
	{
		min=INF;
		if(visited[i]==1){
		for(j=1;j<=n;j++)
		{
		if(visited[j]==0){
			if(adj[i][j]<min&& adj[i][j]!=0)		//find min value 
			{
			min=adj[i][j];
			u=i;
			v=j;
			}
	
			}
	
		
		}

		}
	

	}
		visited[u]=1;
		visited[v]=1;
			total=total+adj[u][v];
	 printf("\nEdge found from %d->%d with COST=%d",u,v,adj[u][v]);
	
	}
	printf("\nMinimum Spanning cost of the tree=%d\n",total);	
}	
int main(){

int n,i,j,s,d,val,e;

	printf("Enter the no of nodes and edges\n");
	scanf("%d%d",&n,&e);


	 initialization(n);
	for(i=1;i<=e;i++)
	{
	printf("Enter source and destination\n");
	scanf("%d%d",&s,&d);

	printf("Enter value\n");
	scanf("%d",&val);
	

	if(val<adj[s][d]&s!=d)			//to remove parallel edges
	{
	adj[s][d]=val;
	adj[d][s]=val;
	}

	}

	display(n);

	prim(n);

return 0;}


/*OUTPUT*****
Enter the no of nodes and edges
4
6
Enter source and destination
1
2
Enter value
1
Enter source and destination
2
4
Enter value
4
Enter source and destination
3
4
Enter value
5
Enter source and destination
1
3
Enter value
3
Enter source and destination
1
4
Enter value
2
Enter source and destination
1
3
Enter value
9

The graph is
0	1	3	2	
1	0	99999	4	
3	99999	0	5	
2	4	5	0	

Edge found from 1->2 with COST=1
Edge found from 2->4 with COST=4
Edge found from 4->3 with COST=5
Minimum Spanning cost of the tree=10

*/
