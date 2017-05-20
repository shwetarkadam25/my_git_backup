/* LINKED LIST

CONCATENATE+REVERSE*/
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
	NODE *start;

}LL;

void appendnode(LL *l,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(l->start==NULL){		//if list doesnt exist
	l->start=p;
	printf("CREATING LIST\n");
	}

	else{
	NODE *q=l->start;		//q searches last node
	while(q->next!=NULL)	
	{
		q=q->next;			//loop goes throough the last node
	}

	q->next=p;
	printf("Node Added Succesfully\n");

	}
}

void addbegin(LL *l,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;

	if(l->start==NULL)		//if list doesnt exist
	l->start=p;

	else{

	p->next=l->start;
	l->start=p;
	printf("Node Added Succesfully\n");
	}

}

void display(LL l)
{
	NODE *q=l.start;
	
	if(q==NULL)
	printf("List does not exist\n");

	else{

	while(q!=NULL)		//loop traverses till list exists
	{

		printf("%d\t",q->data);
		q=q->next;

	}
	}
	printf("\n");
}


int count(LL l)
{
	int count=0;
	NODE *q=l.start;

	while(q!=NULL)
	{
		count++;
		q=q->next;
	}

	printf("Count=%d\n",count);
}
	
void addaftern( LL *l,int n,int x)
{
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;
	int i;
	NODE *q=l->start;	
	for(i=1;i<=n-1;i++)
	{
		q=q->next;
	}

	p->next=q->next;
	q->next=p;
	printf("Node Added Successfully\n");
	
}	

void delete(LL *l,int x)
{
	NODE *q=l->start;		//q is node to be delelted
	NODE *prev=NULL;
	while(q!=NULL)
	{
		
	if(q->data==x)		//match found
	{
		if(q==l->start)		//first node
		l->start=NULL;

		else if(q->next==NULL)		//last node
		prev->next=NULL;
		
		else
		prev->next=q->next;

	}

	else{
	prev=q;
	q=q->next;
	}
	}

}


int main()
{

	LL l1;
	l1.start=NULL;
	
	appendnode(&l1,10);
	appendnode(&l1,200);
	appendnode(&l1,460);
	display(l1);
	addbegin(&l1,50);
	addbegin(&l1,23);
	display(l1);
	count(l1);
	addaftern(&l1,3,45);
	display(l1);


return 0;}
