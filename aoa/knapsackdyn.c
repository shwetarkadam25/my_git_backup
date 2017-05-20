#include<stdio.h>
#include<stdlib.h>
int v[50][50];
int profit;
int max(int a,int b)
{
	if(a>b)
	return a;

	else
	return b;
}


void display(int wt[],int val[],int n)
{
	int i;

	printf("\nITEM NO.:-\t");
	for(i=1;i<=n;i++)
	printf("%d\t",i);
	printf("\nWEIGHTS:-\t");
	for(i=1;i<=n;i++)
	printf("%d\t",wt[i]);

	printf("\nPROFITS:-\t");

	for(i=1;i<=n;i++)
	printf("%d\t",val[i]);

}

void displaymatrix(int n,int m)
{
	int i,j;

	printf("\n\nThe Matrix is:\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		printf("%d\t",v[i][j]);

		printf("\n");
	}
}
int main(){

int w,n,i,val[50],wt[50],m;

	printf("Enter no of items\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
	printf("Enter the profit and weight  of item no. %d\t",i);
	scanf("%d%d",&val[i],&wt[i]);	
	}

	printf("Enter the capacity of the bag\n");
	scanf("%d",&m);

	display(wt,val,n);

	//FILLING O THE MATRIX
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=m;w++)
		{
		if(wt[i]>w)				//if the current wt is > col no or wt of the matrix 
		v[i][w]=v[i-1][w];			//add the value of the previos row

		else
		v[i][w]=max(v[i-1][w],val[i]+v[i-1][w-wt[i]]);		//v[i-1][w]:-w/o selecting the item profit is previos val
								//val[i]+v[i-1][w-wt[i]]=selecting the item adding the profit of the 									remaining capacity after the seleted item is added


		}
	}



	displaymatrix(n,m);

	printf("\nThe Results are:-");
	i=n;
	w=m;
	while(i!=0)
	{
		if(v[i][w]!=v[i-1][w])			//val of cuurent pos. of matrix and previos pos isnt same that means
		{					//val isnt coming from top ....dat wt is added into knapsack	
		profit+=val[i];
		w=w-wt[i];				//update wt i.e wt has reduced
		i--;					//go for next item to be found/selected
		
		printf("\nItem no. %d with weight %d and profit %d added into the bag" ,i+1,wt[i+1],val[i+1]); 
		}
		else
		i--;					//go to previous row

	}

	printf("\n\nTOTAL PROFIT:-%d",profit);

return 0;}

/*OUTPUT*****
Enter no of items
4
Enter the profit and weight  of item no. 1	100
3
Enter the profit and weight  of item no. 2	20
2
Enter the profit and weight  of item no. 3	60
4
Enter the profit and weight  of item no. 4	40
1
Enter the capacity of the bag
5

ITEM NO.:-	1	2	3	4	
WEIGHTS:-	3	2	4	1	
PROFITS:-	100	20	60	40	

The Matrix is:
0	0	0	0	0	0	
0	0	0	100	100	100	
0	0	20	100	100	120	
0	0	20	100	100	120	
0	40	40	100	140	140	

The Results are:-
Item no. 4 with weight 1 and profit 40 added into the bag
Item no. 1 with weight 3 and profit 100 added into the bag

TOTAL PROFIT:-140

*/








