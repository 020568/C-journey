#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int* diff;
	int  diff_size;
}Difference;

Difference * differencecreat(int * nums,int numsSize)
{
	Difference * df=(Difference *)malloc(sizeof(Difference));
	df->diff=(int *)malloc(numsSize*sizeof(int));
	df->diff_size=numsSize;
	df->diff[0]=nums[0];
	for(int i=1;i<numsSize;i++)
	{
		df->diff[i]=nums[i]-nums[i-1];
	}
	return df;

}

void differenceIncrement(Difference* df,int i,int j,int val)
{
	df->diff[i]+=val;
	
	if(j+1<df->diff_size)
	{
		df->diff[j+1]-=val;
	}
	
}

int* differenceResult(Difference* df)
{
	int* res=(int *)malloc(sizeof(int)*df->diff_size);
	res[0]=df->diff[0];
	for(int i=1;i<df->diff_size;i++)
	{
		res[i]=res[i-1]+df->diff[i];
	}
	return res;
}

int main()
{
	int arry[]={2,5,6,3,4,5};
	int len=sizeof(arry)/sizeof(arry[0]);
	
	Difference *df=differencecreat(arry,len);
	differenceIncrement(df,2,4,10);
	int *res=differenceResult(df);
	for(int i=0;i<len;i++)
	{
		printf("%d ",res[i]);
	}
}














