#include<stdio.h>
#include<stdlib.h>
float capacity;
float totalprofit;
typedef struct 
{
	int wt;		//weight of each item
	int proft;		//profit of each item
	float ratio;		//ratio=proft/wt
	float x; 		//to mark whther a item is added COMPLETELY or PARTIALLY
}kp;

void display(kp k[],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
	printf("ITEM=%d  \tWEIGHT=%d \tPROFIT=%d \tRATIO=%f\n ",i,k[i].wt,k[i].proft,k[i].ratio);
	}
}
void bubblesort( kp k[],int n)
{
	int pass,i,j;
	kp temp;

	for(pass=1;pass<n;pass++)
	{
		for(i=0;i<n-pass;i++)
		{
			if(k[i].ratio<k[i+1].ratio)
			{
				temp=k[i];
				k[i]=k[i+1];
				k[i+1]=temp;
			}
		}
	}
}
	
int main(){

kp k[50];

int n,i;


printf("Enter the maximum capacity of the bag\n");
scanf("%f",&capacity);

printf("Enter the no. of items\n");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	printf("Enter weight of item %d\t",i+1);
	scanf("%d",&k[i].wt);

	printf("Enter profit of item %d\t",i+1);
	scanf("%d",&k[i].proft);
	k[i].x=0;

	k[i].ratio=k[i].proft/k[i].wt;		//ratio=proft/wt
	

}


	printf("capacity=%f\n",capacity);
	bubblesort(k,n);			//to sort items in decreasing ratio order
	display(k,n);
	


	for(i=0;i<n;i++){			//continue adding  till all the items are done
	
	if(k[i].wt<capacity)			//added completely
	{
	capacity=capacity-k[i].wt;
	totalprofit+=k[i].proft;
	k[i].x=1;
	printf("Completely=%f\n",k[i].x);

	}
	else									//partially
	{
		capacity=capacity/k[i].wt;					//bag's capacity is reduced i.e it is updated 	
		totalprofit+=(capacity*k[i].proft);				//total proft updated
		
		k[i].x=capacity;
		printf("Partially=%f\n",k[i].x);
	}

	}






	//printf("capacity=%f",capacity);
	printf("\nPROFIT EARNED=%f",totalprofit);	

return 0;}


/* output****
Enter the maximum capacity of the bag
15
Enter the no. of items
5
Enter weight of item 1	2
Enter profit of item 1	10
Enter weight of item 2	2
Enter profit of item 2	3
Enter weight of item 3	3
Enter profit of item 3	2
Enter weight of item 4	4
Enter profit of item 4	2 
Enter weight of item 5	5
Enter profit of item 5	6
capacity=15.000000
 ITEM=0  	WEIGHT=2 	PROFIT=10 	RATIO=5.000000
 ITEM=1  	WEIGHT=2 	PROFIT=3 	RATIO=1.000000
 ITEM=2  	WEIGHT=5 	PROFIT=6 	RATIO=1.000000
 ITEM=3  	WEIGHT=3 	PROFIT=2 	RATIO=0.000000
 ITEM=4  	WEIGHT=4 	PROFIT=2 	RATIO=0.000000
Completely=1.000000
Completely=1.000000
Completely=1.000000
Completely=1.000000
Partially=0.750000

PROFIT EARNED=22.50000

/*
