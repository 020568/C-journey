#include <stdio.h>
int main()
{
	int *ptr;
	int bath=10;
	int val;
	ptr=&bath;
	val=(int)ptr;
	printf("%d",val);
	return 0;
	
}