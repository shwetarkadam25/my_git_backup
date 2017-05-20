#include<stdio.h>
#include<stdlib.h>
typedef struct minmax{

	int min,max;
}MINMAX;
void display(int a[],int n){

int i;

	printf("\nThe Result is:-\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}

MINMAX compute(int a[],int n,int low,int high)
{
	MINMAX mmL,mmR,s;
	int mid;
	s.min=s.max=0;

	if(low==high)				//array has only one element
	{
	s.min=a[low];
	s.max=a[low];
	}
	else if(low+1==high)			//array has 2 elements
	{
		if(a[low]>a[high])	
		{s.max=a[low];
		s.min=a[high];
		}
		
		else{
		s.max=a[high];
		s.min=a[low];
		}
	}
	else{
	mid=low+high/2;
	mmL=compute(a,n,low,mid);		//left sub array
	mmR=compute(a,n,mid+1,high);		//right sub array
	
	if(mmL.min>mmR.min)
	s.min=mmR.min;				//comparing minimum lelemntd of two sub arrays
	
	else
	s.min=mmL.min;



	if(mmL.max>mmR.max)			//comoaring maximum elelents of two sub arrays
	s.max=mmL.max;
	
	else
	s.max=mmR.max; 

	}
	return s;
}

int main(){

int n,i,a[50];
MINMAX s;

	printf("Enter no. of elements\n");
	scanf("%d",&n);


	for(i=0;i<n;i++)
	{
	printf("Enter value %d\n",i+1);
	scanf("%d",&a[i]);
	}

	display(a,n);

	s=compute(a,n,0,n-1);

	printf("\nMINIMUM Element =%d\n",s.min);
	printf("MAXIMUM Element =%d\n",s.max);


return 0;}



/*output***

Enter no. of elements
5
Enter value 1
5
Enter value 2
50
Enter value 3
60
Enter value 4
22
Enter value 5
11

The Result is:-
5	50	60	22	11	
MINIMUM Element =5
MAXIMUM Element =60
*/
