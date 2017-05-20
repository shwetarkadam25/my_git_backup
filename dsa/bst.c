#include<stdio.h>
#include<stdlib.h>
#define N 100
int count=0;
int leafcount=0;

typedef struct tnode
{
	int data;
	struct tnode *left,*right;

}TNODE;

typedef struct
{
	TNODE *root;

}BST;

void createnode(BST *bt,int x)
{
	TNODE *p=(TNODE*)malloc(sizeof(TNODE));
	p->data=x;
	p->right=p->left=NULL;
	TNODE *q,*temp=bt->root;

	if(bt->root==NULL)
	{
	printf("Creating Binary Search Tree\n");
	bt->root=p;
	}
	

	else{
	while(temp!=NULL)		//searches where the node is going to be linked
	{
		q=temp;
		if(x<temp->data)
		temp=temp->left;

		else
		temp=temp->right;

	}	

	if(x<q->data)			//links the node
	q->left=p;
	
	else
	q->right=p;

	}

}	

void delete(BST *bt,int x)
{
	TNODE *p=bt->root;
	TNODE *rp,*f=NULL;

	

	while(p!=NULL)
	{
		if(x==p->data)
		break;

		f=p;
		if(x<p->data)
		p=p->left;

		else
		p=p->right;

	}

	if(p==NULL)
	printf("Data not found\n");
	
	if(p->left==NULL&&p->right==NULL)
		rp=NULL;

	if(p->right==NULL)		//p has left son
	rp=p->left;

	else if(p->left==NULL)		//p has right son
	rp=p->right;

	else{

	rp=p->right;
	TNODE *s=rp->left;		//s searches the leftmost nide
		
	if(s==NULL)
	rp->left=p->left;

	else
	{
		while(s!=NULL)	
		{
			f=rp;
			rp=s;
			s=s->left;
		}
		
		f->left=rp->right;
		rp->left=p->left;
		rp->right=p->right;
	}
     }

	if(f==NULL)		//root node is to be delelted
	bt->root=rp;

	
	free(p);

}
void countnode(TNODE *rt)
{
	if(rt!=NULL)
	{
		count++;

		countnode(rt->left);
		countnode(rt->right);
		
	}
}	
void leafcountnode(TNODE *rt)
{
	if(rt!=NULL)
	{
		if(rt->left==NULL&&rt->right==NULL)
		leafcount++;

		leafcountnode(rt->left);
		leafcountnode(rt->right);
		
	}
}
void inorder(TNODE *rt)

{
	if(rt!=NULL)
	{
		inorder(rt->left);
		printf("%d\t",rt->data);
		inorder(rt->right);
	}
}

void preorder(TNODE *rt)
{

	if(rt!=NULL)
	{
		printf("%d\t",rt->data);
		preorder(rt->left);
		preorder(rt->right);
	}
}
int main()
{
	BST b1;
	b1.root=NULL;
	
	createnode(&b1,50);
	createnode(&b1,250);
	createnode(&b1,5);
	createnode(&b1,62);
	createnode(&b1,45);
	printf("Inorder Traversal:\n");
	inorder(b1.root);
	
	printf("\nPreorder Traversal:\n");
	preorder(b1.root);
	
	printf("\nThe LEAFNODE count is:");
	leafcountnode(b1.root);
	printf("%d",leafcount);

	printf("\nThe TOTAL node count:");
	countnode(b1.root);
	printf("%d",count);


return 0;}














