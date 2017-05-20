#include<stdio.h>
#include<stdlib.h>
#define N 50
#define queen 25
int board[N][N];
int safecheck(int n,int r,int c)		/*check wther the queen is not safe .....after checking all possibilutes if found any place 								return true*/
{
	int i,j;

	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		if(board[i][j]==queen)
		{
		if(abs(i-r)==abs(j-c))		//check for diagonals
		return 0;

		if(i==r||j==c)		//check for same row or col
		return 0;
		

		}
	
	}
	}
	return 1;
}
	
int place_queen(int n,int level){

	int flag,col;

	if(level==n)	/*process goes on till level or row==n*/ 
	return 1;
	else{
	/*consider this level or no and try putting the quuen col by col*/

	for(col=0;col<n;col++)		//placing queen coloumn by colomn
	{
	flag=safecheck(n,level,col);
	if(flag==1){		//check whther safe for the starting position/*check for each level for empty positions*/
	board[level][col]=queen;
	
	if(place_queen(n,level+1)==1)		//now place the other queens in the board by increasing the level
	return 1;

	else
	board[level][col]=0;		//backtrack
	}	
	}
	}
	return 0;		//could NOT place the queens anywhere
}

void display(int n)
{
	int i,j;
	printf("The RESULT IS :\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	printf("%d\t",board[i][j]);
	printf("\n");
	}
}
int main(){

int n,i,flag;

	printf("Enter the size of the board\n");
	scanf("%d",&n);

	if(n<4){
	printf("Chessboard  size cannot be less than 4");
	exit(0);}

	flag=place_queen(n,0);

	if(flag==1)
	{printf("The queens have been placed\n");
	
	display(n);
	}
	else
	printf("Queens coulnt be placed\n");

	


return 0;}
