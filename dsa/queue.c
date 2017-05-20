/*QUEUE
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct queue
{
	int a[N];
	int front,rear;

}queue;

void enqueue(queue *q,int x)
{
	if(q->rear==N-1)		//if queue is full
	printf("Queue is full\n");

	else
	{
		q->a[++q->rear]=x;
		printf("Value added Successfully\n");

	}

}

int dequeue(queue *q)
{
	int x;
	if(q->front==q->rear)
	printf("Queue is empty\n");

	else
	{
		x=q->a[++q->front];
		printf("Dequeued Successfully\n");
		return x;
	}
}

void display(queue q)
{
	int i;

	for(i=q.front+1;i<=q.rear;i++)
	{
		printf("%d\t",q.a[i]);

		
	}

}

int main()
{
	queue q1;
	q1.rear=q1.front=NULL;
	int x;

	enqueue(&q1,10);
	enqueue(&q1,50);
	enqueue(&q1,40);
	display(q1);
	dequeue(&q1);
	display(q1);


return 0;}
