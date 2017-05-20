/*STACK USING LINKED LIST*/
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

}SLL;

void push(SLL *s,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(s->top==NULL)		//added node is 1st node
	{
	printf("Creating stack\n");
	s->top=p;
	printf("Value Added Successfully\n");
	}

	else{
	s->top->next=p;
	s->top=p;
	printf("Value Added Successfully\n");
	}
}

int pop(SLL *s){

	NODE *q=s->top;
	int x;
	x=q->data;

	if(q==s->top)		//only node
	s->top==NULL;

	else{
	s->top=q->next;
	}
	free(q);
	return x;

}

void display(SLL s)
{
	NODE *q=s.top;

	while(q!=NULL)
	{
		printf("%d\t",q->data);
		

	}
}
int main()
{
	SLL s1;
	s1.top=NULL;
	
	int x;

	push(&s1,50);
	push(&s1,600);
	push(&s1,700);
	push(&s1,800);
	x=pop(&s1);
	printf("VALUE popped :%d",x);
return 0;
}	































