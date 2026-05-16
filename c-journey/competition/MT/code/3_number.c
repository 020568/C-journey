#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int bit(int num,int exp)
{
	return (num/exp)%10;
}

bool get(int num)
{
	int total=0;
	for(int exp=1;exp<=num;exp*=10)
	{	
		int b=bit(num,exp);
		total+=b*b*b;
	}
	if(total==num)
		return 1;
	return 0;
}

int main()
{
	int len=300;
	int *arry=(int *)malloc(len*sizeof(int));
	int j=0;
	for(int i =0;i<len;i++)
	{
		if(get(i))
			arry[j++]=i;
	}
	
	for(int i=0;i<j;i++)
	{
		printf("%d ",arry[i]);
	}
	
	
}





