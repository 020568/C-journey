#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int* pnum;
	int size;
}presum;

presum* presum_arry_creat(int* nums,int size)//nums is arry,size is belong to arry
{
	presum* obj=(presum *)malloc(sizeof(presum));
	obj->size=size+1;
	obj->pnum=(int *)calloc(obj->size,sizeof(int));
	for(int i=1;i<obj->size;i++)
	{
		obj->pnum[i]=obj->pnum[i-1]+nums[i-1];
	}
	return obj;
}

int sumarry(presum * obj,int left,int right)
{
	return obj->pnum[right+1]-obj->pnum[left];
	
}

void spacefree(presum* obj)
{
	free(obj->pnum);
	free(obj);
}

int main()
{
	int arr[6]={1,5,6,3,4,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	presum* sum_arry = presum_arry_creat(arr,size);
	int sum = sumarry(sum_arry,1,4);
	spacefree(sum_arry);
	printf("%d\n",sum);
}







