#include<stdio.h>
#include<stdlib.h>
#define INF 999
#define N 50
int dist[N][N];			//distance mtrix
int seq[N][N];			//sequence matrix

void display(int n)
{
	int i,j;

	printf("\n The DISTANCE Matrix is\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	printf("%d\t",dist[i][j]);
	printf("\n");
	}

	printf("\n\nTHE SEQUENCE Matrix is\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	printf("%d\t",seq[i][j]);
	printf("\n");
	}

}

void result(int n)
{
	int i,j,sum,k;

	for(i=1;i<=n;i++)
	{
	for(j=1,k=1;j<=n;j++,k++)
	{

	if(seq[i][j]!=j)				//der has been a change in the mtrix
	{
	sum=dist[i][j];
	
	}
}
}
}		
void initialization(int n){

	int i,j;
//initialization of arrays
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
	if(i!=j)
	{dist[i][j]=INF;
	seq[i][j]=j;
	}
	else
	dist[i][j]=0;
	}
	}
}

	
	
void display_result(int n,int s,int d)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	printf("%d\t\t%d\t\t%d\t\t",i,j,dist[i][j]);
	
	
	}
}
	

void floyd(int n)
{

	int i,j,k;

	for(k=1;k<=n;k++)			//iteration number AND the intermediate node
	{
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		if(dist[i][j]>dist[i][k]+dist[k][j])		//if wt using the intermedeiate node is min then update 
		{dist[i][j]=dist[i][k]+dist[k][j];
		seq[i][j]=k;
	}
	}	
	}
	}
}
int main(){

int n,i,j,e,s,d,val,k;


	printf("Enter no. of vertices and edges\n");
	scanf("%d%d",&n,&e);

	
	initialization(n);

	for(i=1;i<=e;i++)
	{
	printf("Enter source and destination\n");
	scanf("%d%d",&s,&d);
	printf("Enter value\n");
	scanf("%d",&val);
	
	if(val<dist[s][d]&&s!=d){
	dist[s][d]=val;
	dist[d][s]=val;
	}
	}


	display(n);
	floyd(n);
	display(n);

	printf("\n\n");
		printf("SOURCE\t\tDESTINATION\t\tDISTANCE\t\tPATH\n");
	display_result(n,1,n);


return 0;
}
