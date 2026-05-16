#include <stdio.h>
int main()
{
	double r;
	double h;
	scanf("%lf %lf",&r,&h);
	
	double pi=3.1415926;
	double C=2*pi*r;
	double SC=pi*r*r;
	double SB=4*pi*r*r;
	double VB=4.0/3.0*pi*r*r*r;//!!!4/3结果依旧是整型！！！
	double VCY=SC*h;
	printf("%.2lf\n",C);
	printf("%.2lf\n",SC);
	printf("%.2lf\n",SB);
	printf("%.2lf\n",VB);
	printf("%.2lf",VCY);
}











