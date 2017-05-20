#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct dnode
{
	int data,count;
	struct dnode *prev,*next;

}DNODE;
 typedef struct
{
	DNODE *left,*right;

}DLL;

void addleft(DLL *dq,int x)
{
	DNODE *p=(DNODE*)malloc(sizeof(DNODE));

	p->data=x;
	p->prev=p->next=NULL;

	if(dq->left&&dq->right==NULL)
	{
		dq->left=dq->right=p;
	}

	else
	{
		dq->left->prev=p;
		p->next=dq->left;
		dq->left=p;
		printf("ELEMENT added\n");

	}

}

int deleteleft(DLL *dq)
{
	int x;
	DNODE *q=dq->left;

	if(dq->left==NULL&&dq->right==NULL)
	printf("NO nodes left\n");
	return;
	
	x=q->data;
	dq->left=dq->left->next;
	if(dq->left==NULL)
	dq->right==NULL;
	else
	dq->left->prev=NULL;
	printf("DELELTED ELEMENT:%d",x);
	free(q);
	return x;

}

int deleteright(DLL *dq)
{
	int x;
	DNODE *q=dq->right;

	
	if(dq->left==NULL&&dq->right==NULL)
	printf("NO nodes left\n");
	return;
	
	
	x=q->data;
	dq->right=dq->right->next;
	if(dq->right==NULL)
	dq->left==NULL;

	else
	dq->right->next=NULL;
	printf("DELELTED ELEMENT:%d",x);
	free(q);
	return x;

}
 
void addright(DLL *dq,int x)
{
	DNODE *p=(DNODE*)malloc(sizeof(DNODE));

	p->data=x;
	p->prev=p->next=NULL;

	if(dq->left&&dq->right==NULL)
	{
		dq->left=dq->right=p;
	}

	else{
		dq->right->next=p;
		p->prev=dq->right;
		dq->right=p;
		printf("ELEMENT added\n");

	}
	
}
		

int main()
{
	DLL dq;

	dq.left=dq.right=NULL;

	addleft(&dq,10);
	addleft(&dq,20);
	addright(&dq,60);
	addleft(&dq,40);
	deleteleft(&dq);
	deleteright(&dq);
	deleteleft(&dq);
	addright(&dq,66);


return 0;}

