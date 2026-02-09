#include <stdio.h>
void interchange(int *a,int * b);
int main()
{
	int x=10,y=20;
	interchange(&x,&y);
	//printf("%d %d ",x,y)
	return 0;

	
}

void interchange(int *a, int *b)
{
	int *temp;//int temp;
	temp=a;//temp=*a;
	a=b;//*a=*b;
	b=temp;//*b=temp;
	printf("%d %d",*a,*b);
}



