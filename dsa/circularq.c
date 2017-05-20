/*CIRCULAR QUEUE*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct
{
	int a[N];
	int rear;
	int front;
}queue;
void enqueue(queue *cq,int x)
{
	if(cq->rear+1%N==cq->front)
	printf("queue is full\n");


	else{
	cq->rear=cq->rear+1%N;
	cq->a[cq->rear]=x;
	}


}

int dequeue(queue *cq)
{
	int x;
	if(cq->rear==cq->front)
	printf("Queue is empty\n");

	else{
	cq->front++;
	x=cq->a[cq->front];	
	}
	return x;
}
void display(queue cq)
{
	int i;
	printf("the queue is\n");
	for(i=cq.front+1;i<=cq.rear;i++)
	{
	printf("%d\t",cq.a[i]);
	}
}
int main()
{	queue q1;
	q1.rear=q1.front=0;
	int x;
	enqueue(&q1,50);
	enqueue(&q1,51);
	enqueue(&q1,52);
	display(q1);
	x=dequeue(&q1);
	printf("\nx=%d",x);
	display(q1);
return 0;
}

