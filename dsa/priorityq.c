#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct {
	NODE *front;
}PQ;

void enqueue(PQ *pq,int x)
{

	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(pq->front==NULL)
	{
	printf("Creating Priority Queue\n");
	pq->front=p;
	}

	else{
	NODE *q=pq->front;
	NODE *prev=NULL;
	while(q!=NULL)
	{
	if(x<q->data)
	{
		if(q==pq->front)
		{
		p->next=pq->front;
		pq->front=p;		;
		}
		else{
		p->next=q;
		prev->next=p;

		}
	break;
	}

	else{	
	prev=q;
	q=q->next;
	}

	}

	}
}

int dequeue(PQ *pq)
{
	NODE *q=pq->front;
	int x=q->data;
	pq->front=pq->front->next;;
	free(q);
	return x;
}

void display(PQ *pq)
{
	NODE *q=pq->front;
	while(q!=NULL)
	{
	printf("%d\t",q->data);
	q=q->next;
	}
}	
int main()
{
	PQ pq1;
	pq1.front=NULL;

	enqueue(&pq1,50);
	enqueue(&pq1,460);
	enqueue(&pq1,20);
	display(&pq1);

return 0;}

	
