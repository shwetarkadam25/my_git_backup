#include<stdio.h>
#include<stdlib.h>
#define N 50
int p[N];		//stores key values or probaityof that key value
int q[N];		//dummy nodes or key vlues that r acutally not stored in the tree
int k[N];		//stores the key values or internal node values
int weight[N][N];	//stores values of the wt which is computed using p and q
int root[N][N];		//stores root 
int cost[N][N];		//stores cost computed
void compute_wt(int n)
{
int i,j;
for(i=0;i<=n;i++)
{
	for(j=i;j<=n;j++)
	{
		if(i!=j)
		weight[i][j]=p[j]+q[j]+weight[i][j-1];
	}
}

printf("\nWEIGHT MATRIX\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
{
printf("%d\t",weight[i][j]);
}printf("\n");
}


}

void compute_cost(int n)
{
int i,k,j,min,index,temp;

for(i=n;i>=0;i--)
{
for(j=0;j<=n;j++)
{
	if(i<j){
	min=999;
	index=99;
	for(k=i+1;k<=j;k++)
	{
	temp=weight[i][j]+cost[i][k-1]+cost[k][j];

	if(min>temp)
	{
	min=temp;
	index=k;
	}
	
    }

	cost[i][j]=min;
	root[i][j]=index;
	
	}
	
}
}



printf("\nCOST MATRIX\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
{
printf("%d\t",cost[i][j]);
}printf("\n");
}


printf("\nROOT MATRIX\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
{
printf("%d\t",root[i][j]);
}printf("\n");
}




}
	
	

void obst(int n){

compute_wt(n);
compute_cost(n);

}
void display(int n){

int i,j;

	printf("INDEX\t");
	for(i=0;i<=n;i++)
	printf("%d\t",i);

	printf("\np[]\t\t");

	for(i=1;i<=n;i++)
	printf("%d\t",p[i]);

	printf("\nq[]\t");
	for(j=0;j<=n;j++)
	printf("%d\t",q[j]);
}

void init(int n){

int i,j;

for(i=0;i<=n;i++)	//initilizing wt matrix
weight[i][i]=q[i];


for(i=1;i<=n;i++){	//initilizing root matrix and cost marix
root[i][i]=0;
cost[i][i]=0;}

display(n);

obst(n);
}

int main(){

int n,i,j;

printf("Enter no. of keys\n");
scanf("%d",&n);




printf("Enter weights of successful searches(p)\n");
for(i=1;i<=n;i++)
{
printf("Enter value of p%d\n",i);
scanf("%d",&p[i]);
}


printf("Enter weights of unsuccessful searches(q)\n");
for(i=0;i<=n;i++)
{
printf("Enter value of q%d\n",i);
scanf("%d",&q[i]);
}


init(n);




return 0;}

