#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct 
{
	NODE *front;
}PQ;

void enqueue(PQ *pq,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	NODE *q=pq->front;
	NODE *prev=NULL;

	if(pq->front==NULL){
	printf("Creating Priorirty queue\n");
	pq->front=p;
	}

	else{
	while(q!=NULL)
	{
	if(x<pq->front->data)
	{
		if(q==pq->front)	//first node
		{
		p->next=q;
		pq->front=p;
		}	
			
		else{
		p->next=q;
		prev->next=p;
		}
	}
	else
	{
		prev=q;
		q=q->next;
	}

	}
   }		

}

void display(PQ pq)
{
	NODE *q=pq.front;
	while(q!=NULL)
	{
		printf("%d\t",q->data);
		q=q->next;
	}
}
int dequeue(PQ *pq)
{
	NODE*q=pq->front;
	int x;
	
	pq->front=pq->front->next;
	x=q->data;
	free(q);
	return x;

}

	
	
int main()
{
	PQ pq1;
	pq1.front=NULL;
	int x;

	enqueue(&pq1,10);
	enqueue(&pq1,5);
	enqueue(&pq1,556);
	x=dequeue(&pq1);

	printf("X=%d",x);
	printf("\n");

	display(pq1);
return 0;
}
