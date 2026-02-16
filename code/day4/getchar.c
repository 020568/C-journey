#include <stdio.h>
int main(void)
{
	char ch ;
	ch=getchar();
	while(ch != '#')
	{
		putchar(ch);
		ch=getchar();
	}
	
	return 0;
}