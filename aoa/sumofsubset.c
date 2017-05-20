#include<stdio.h>
#include<stdlib.h>
#define N 50
int wt[N];
int m;
int result[N];
int x[N];
void display(n)
{
	int i;
	printf("WEIGHT NO.:\t");
	for(i=0;i<n;i++)
	{
	if(x[i]==1)		//indicates that element has been selected for the sub set
	{
	printf("%d\t",x[i]);
	}
	}
	printf("\nWEIGHT:\t");

	/*for(i=1;i<=n;i++)
	{
	if(x[i]==1)		//indicates that element has been selected for the sub set
	{
	printf("%d\t",wt[i]);
	}
	}*/
}
int promising(int n,int level,int wsf,int tpl,int sum)
{
	if(wsf+wt[level+1]<=sum &&(wsf+tpl>=sum))
	return 1;
	else
	 return 0;
}
void sum_of_subset(int n,int level,int wsf,int tpl,int sum)
{
	if(wsf==sum)
	display(n);
	
	else{
	
	if(promising(n,level,wsf,tpl,sum)==1)
	{
	x[level+1]=1;//n is the sol
	wsf+=wt[level+1];						//update the wsf
	tpl= tpl-wt[level+1];						//update tpl after selecting the wt
	sum_of_subset(n,level+1,wsf,tpl,sum);				//go ahead for other levels
	}
	x[level+1]=0;//wont be in the solution
	sum_of_subset(n,level+1,wsf,tpl-wt[level+1],sum);	//even though wt is not aadded it is cosidered hence v will update the tpl
	}
}	
int main(){

int level=0, sum=0,tpl,wsf=0, n,i,j;

	printf("Enter the no of weights\n");
	scanf("%d",&n);

	printf("Enter sum whose sets are to be made\n");
	scanf("%d",&sum);

	printf("Please enter the weights in SORTED Manner\n");
	for(i=1;i<=n;i++)
	{
	printf("Enter weight %d\n",i);
	scanf("%d",&wt[i]);
	}
	printf("level=%d",level);

	for(j=1;j<=n;j++)	
	tpl=tpl+wt[j];

	printf("tpl=%d",tpl);

	level=0;
	
	sum_of_subset(n,0,0,tpl,sum);


return 0;}

