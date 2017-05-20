//Queue using linked list
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
	NODE *rear,*front;

}QLL;

void enqueue(QLL *q,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(q->rear==NULL){
	printf("Creating queue\n");
	q->front=q->rear=p;
	}

	else{
	q->rear->next=p;
	q->rear=p;
	printf("DATA added Successfully\n");
	}
}

int dequeue(QLL *q)
{
	NODE *d=q->front;
	int x;
	x=d->data;

	if(q->front==NULL)		//to check if queue is empty
	printf("NO NODES\n");
	
	

	
	q->front=q->front->next;
	if(q->front==NULL)		//only one node present in queue)
	q->rear=NULL;			//update rear
	printf("NODE dequeued Sucessfully\n");
	
	free(d);
	
	return x;
}



void display(QLL q)
{
	NODE *pq=q.front;
	if(pq==NULL)		//queue does not exist
	printf("Queue does not exist\n");
	
	else{
	while(pq!=NULL)
	{
		printf("%d\t",pq->data);
		
		pq=pq->next;

	}
	}
}

int main()
{
	QLL q1;
	q1.front=q1.rear=NULL;
	int x;

	enqueue(&q1,10);
	enqueue(&q1,20);
	enqueue(&q1,150);
	enqueue(&q1,650);
	display(q1);
	printf("\n");

	x=dequeue(&q1);
	printf("Dequeued element is %d",x);
		printf("\n");
	display(q1);
	
	
return 0;}






























































































