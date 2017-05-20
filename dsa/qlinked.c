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
	NODE *front,*rear;
}queue;
void enqueue(queue *ql,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(ql->rear==NULL)
	{
	printf("Creating queue\n");
	ql->front=ql->rear=p;
	}
	else{
	ql->rear->next=p;
	ql->rear=p;
	printf("Value added successfully\n");
	}

}

int dequeue(queue *ql)
{
	NODE *q=ql->front;
	int x;
	x=q->data;
	if(ql->front==ql->rear)		//one node
	{
	ql->rear=NULL;
	}

	else{
	ql->front=ql->front->next;
	free(q);

	return x;
	}
}

void display(queue ql)
{
	NODE *q=ql.front;

	while(q!=NULL)
	{
	printf("%d\t",q->data);
	q=q->next;
	}

}
int main()
{
	queue q1;
	q1.front=q1.rear=NULL;
	int x;
	enqueue(&q1,50);
	enqueue(&q1,42);
	enqueue(&q1,452);
	display(q1);
	x=dequeue(&q1);
	printf("x=%d",x);
return 0;
}
