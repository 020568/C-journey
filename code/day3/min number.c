#include <stdio.h>

double min(double a,double b);
int main()
{
	double x;
	double y;
	scanf("%lf %lf",&x,&y);
	printf("%lf",min(x,y));
	
}

double min ( double a,double b)
{
	if (a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}