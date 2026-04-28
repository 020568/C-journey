#include <stdio.h>

int main()
{
	float score_Cplus;
	float py;
	float C;
	
	scanf("%f %f %f",&score_Cplus,&py,&C);
	
	double avg=(score_Cplus+py+C)/3.0;
	float all=score_Cplus+py+C;
	printf("%.6f\n%.6lf",all,avg);
	
	return 0;
}







