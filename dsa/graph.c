#include<stdlib.h>
#include<stdio.h>
#define N 100
int adj[N][N]={0};
int visited[N]={0};
typedef struct 
{
	int a[N];
	int top;
}stack;

typedef struct 
{
	int a[N];
	int front,rear;
}queue;
void enqueue(queue *q,int x)
{
	if(q->rear==N-1)
	printf("Queue full\n");
	else{
	q->a[++q->rear]=x;
}
}
int dequeue(queue *q)
{
	return(q->a[++q->front]);
}
void ibfs(int v,int n)
{
	int i,x;
	queue q;
	q.rear=q.front=-1;
	visited[v]=1;
	enqueue(&q,v);

	while(q.front!=q.rear)
	{
		x=dequeue(&q);
		printf("%d\t",x);
		for(i=1;i<=n;i++)
		{
			if(adj[x][i]==1&&!visited[i])
			{
				enqueue(&q,i);
				visited[i]=1;
			}
		}
	}
}

void push(stack *s,int x)
{

	if(s->top==N-1)
	printf("Stack full\n");

	else{
	s->a[++s->top]=x;

}
}

int pop(stack *s)
{

	return(s->a[s->top--]);
}
int isEmpty(stack *s)
{
	if(s->top==-1)
	return 1;

	else
	return 0;
}

void dfs(int v,int n)
{
	int i;
	visited[v]=1;
	printf("%d\t",v);

	for(i=1;i<=n;i++)
	{
	if(adj[v][i]!=0&&!visited[i])
	dfs(i,n);

}
}
void idfs(int v,int n)
{
	int i,x;
	stack s;
	s.top=-1;
	visited[v]=1;
	push(&s,v);
	while(!isEmpty(&s))
	{
	
	x=pop(&s);
		printf("%d\t",x);
	for(i=1;i<=n;i++)
	{
		if(adj[x][i]!=0&&!visited[i])
		push(&s,i);
		visited[i]=1;


	}
	}
}
	



void display(int n)
{
	int i,j;
	printf("\nThe matrix is\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)	
	printf("%d\t",adj[i][j]);
	
	printf("\n");
}
	}

int main()
{
	int s,d,x,n,e,i;

	printf("ENTER no. of vertices and edges\n");
	scanf("%d%d",&n,&e);

	for(i=1;i<=e;i++)
	{
		printf("Enter source and destination\n");
		scanf("%d%d",&s,&d);
		adj[s][d]=1;
		adj[d][s]=1;
	}
	printf("Enter starting point\n");
	scanf("%d",&x);
	/*dfs(x,n);
	display(n);
	visited[N]=0;*/

	ibfs(x,n);
	display(n);
return 0;
}
