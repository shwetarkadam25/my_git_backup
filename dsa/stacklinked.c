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
	NODE *top;
}stack;

void push(stack *s,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(s->top==NULL)
	{
	printf("Creating stack\n");
	s->top=p;
	}

	else{
	p->next=s->top;
	s->top=p;
	printf("Value added sucessfully\n");
	}

}

int pop(stack *s)
{
	NODE *q=s->top;
	int x;
	if(s->top->next==NULL)
	s->top=NULL;
	else
	s->top=s->top->next;
	x=q->data;

	free(q);
	return x;

}

void display(stack *s)
{
	NODE *q=s->top;
	
	while(q!=NULL)
	{
		printf("%d\t",q->data);
		q=q->next;

	}
}
int main()
{
stack s1;
s1.top=NULL;
int x;

push(&s1,10);

push(&s1,560);
push(&s1,20);

push(&s1,4560);
x=pop(&s1);
printf("x=%d\n",x);
display(&s1);

return 0;}
