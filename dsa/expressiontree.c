#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct tnode{

	char data;
	struct tnode *left,*right;
}TNODE;

typedef struct stack{

	TNODE *a[N];
	int top;
}stack;

void push(stack *s,TNODE *p)
{	
	s->a[++s->top]=p;

}

TNODE *pop(stack *bt)
{
	return(bt->a[bt->top--]);

}
int isalnum(char x)
{
	if(x>=0||x<=9||x>='a'||x<='z'||x>='A'||x<='Z')
	return 1;

	else 
	return 0;
}
TNODE *createtree(char a[])
{
	stack s;
	s.top=-1;

	TNODE *rop,*lop;
	int i;
	for(i=0;a[i]!=0;i++)
	{
		TNODE *p=(TNODE*)malloc(sizeof(TNODE));
	p->data=a[i];
	p->left=p->right=NULL;
	while(!isalnum(a[i]))		// if operator
	{
		rop=pop(&s);
		lop=pop(&s);
		p->right=rop;
		p->left=lop;
	}

	push(&s,p);
	}
	return(pop(&s));	//returns address of topmost node
}



void inorder(TNODE *rt)
{
	if(rt!=NULL)
	{
		if(rt->left!=NULL&&rt!=NULL)
			printf("(");

		inorder(rt->left);
		printf("%c",rt->data);
		inorder(rt->right);
		
		
		if(rt->left!=NULL&&rt!=NULL)
			printf(")");
	
			
	}
}


int main()
{
	char postfix[N];
	TNODE *root;

	printf("Enter expression\n");
	scanf("%s",postfix);

	root=createtree(postfix);
	inorder(root);

return 0;}	

















































		
