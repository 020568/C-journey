#include <stdio.h>
int sum(const int ar[],int n);
int sum(const int ar[],int n)
{
	int i;
	int total = 0;
	for(i = 0 ; i < n ; i++)
	{
		total += ar[i];
		
	}
	return total;
}

int main()
{
	int arr[] ={1,2,3,4,5};
	int len=sizeof(arr)/sizeof(arr[0]);
	int res=sum(arr,len);
	printf("%d",res);
	return 0;
	
}
