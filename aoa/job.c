#include<stdio.h>
#include<stdlib.h>
typedef  struct job{		//create a struct for job

	int id;
	int deadline;
	int profit;
}job;

void display(job j[],int n)
{
	int i,p,k;

	printf("\n\nThe Result is:-\n");
	printf("\nID\t\t");
	for(i=1;i<=n;i++)
	printf("%d\t",j[i].id);
	

	printf("\nDEADLINE\t");
	for(p=1;p<=n;p++){
	printf("%d\t",j[p].deadline);
	
	}

	printf("\nPROFIT\t\t");
	for(k=1;k<=n;k++){
	printf("%d\t",j[k].profit);
	}
}

void bubblesort(job j[],int n)
{
	int pass,k;
	job temp;
	
	for(pass=1;pass<n;pass++)
	{
	for(k=1;k<n-pass;k++)
	{
		if(j[k].profit<j[k+1].profit)
	      {	temp=j[k+1];
		j[k+1]=j[k];
		j[k]=temp;
	      }

	}
	}
}

//to get dmax value(max. deadline)
int max_deadline(job j[],int n)			
{

	int i,max=j[1].deadline;

	for(i=1;i<=n;i++)
	{
		if(max<j[i].deadline)
		{
		max=j[i].deadline;
		}
	}

	return max;
}


//to get value of k		
int  min_value(int dmax,int no)
{
	

	if(dmax<no)
	return dmax;
	else
	return no;
}
	

int main(){

	int i,n,timeslot[50]={0},dmax,k,p;

	job j[50];	

	printf("Enter no of jobs to be scheduled\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("Enter ID,DEADLINE and PROFIT of job %d\n",i);
		scanf("%d%d%d",&j[i].id,&j[i].deadline,&j[i].profit);
	}

	
	display(j,n);
	bubblesort(j,n);
	display(j,n);

	dmax=max_deadline(j,n);

	
	
	for(i=1;i<=n;i++)
	{
	for(k=min_value(dmax,j[i].deadline);k>=1;k--)	//job can be done before OR on deadline or no(k=k-1)
	{
	if(timeslot[k]==0)				//to check whther the mentioned k th timeslot is empty
	{timeslot[k]=j[i].id;				//schedule dat job in the selected time slot and go for the next iteration
	break;

	}						//otherwise do k=k-1 to check whther any other time slot is empty  
	}
	}



	//displaying the job sequnce
	printf("\nThe scheduled JOB SEQUENCE(Acoording to job ID ) is:-\n");
	for(p=1;p<=dmax;p++)
	printf("%d\t",timeslot[p]);



	
	

return 0;}


