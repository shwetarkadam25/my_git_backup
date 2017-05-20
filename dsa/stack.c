/* Stack*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct stack
{
	int a[N];
	int top;

}stack;

void push(stack *s,int x)
{
	if(s->top==N-1)		//if stack is full
	printf("Stack is full\n");
	

	else{
	s->a[++s->top]=x;
	printf("Element Added Successfully\n");

	}

}

int pop(stack *s)
{
	int x;
	if(s->top==-1)
	printf("Stack is empty\n");

	else{
	x=s->a[s->top--];
	return x;

	}
	
}	

void display(stack *s)
{
	int i;
	for(i=s->top;i>=0;i--){
	printf("%d\t",s->a[s->top--]);
	
	}
}

int main()
{
	stack s1;
	s1.top=-1;
	int x;

	push(&s1,50);
	push(&s1,51);
	push(&s1,52);
	display(&s1);
	x=pop(&s1);
	printf("Popped element=%d",x);	
	push(&s1,6544);
	display(&s1);



return 0;}	
	










































