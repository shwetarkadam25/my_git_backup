#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 100
typedef struct tnode
{
	char data;
	struct tnode *left,*right;
}TNODE;
typedef struct 
{
	int top;
	TNODE *a[N];	//stores the address of the nodes
}stack;

void push(stack *s,TNODE *p)
{
	s->a[++s->top]=p;
}

TNODE *pop(stack *s)
{
	return(s->a[s->top--]);
}

TNODE *create(char a[])
{
	stack s;
	s.top=-1;

	int i;
	TNODE *lop,*rop;
	for(i=0;a[i]!=0;i++)
	{
		TNODE *p=(TNODE*)malloc(sizeof(TNODE));
		p->data=a[i];
		p->left=p->right=NULL;
		if(!isalnum(a[i]))
		{
			rop=pop(&s);
			lop=pop(&s);
			p->right=rop;
			p->left=lop;
		}

		push(&s,p);
	}
	return(pop(&s));
}

void inorder(TNODE *rt)
{
	if(rt!=NULL){
	if(rt->left!=NULL&&rt->right!=NULL)		//if internal node then its a brace
	printf("(");

	inorder(rt->left);

	printf("%c",rt->data);

	inorder(rt->right);

	if(rt->left!=NULL&&rt->right!=NULL)		//if internal node then its a brace
	printf(")");
	
	}
}

int main()
{
	char postfix[N];
	TNODE *root;

	printf("Enter thr postfix expression\n");
	gets(postfix);

	root=create(postfix);

	inorder(root);

return 0;}
