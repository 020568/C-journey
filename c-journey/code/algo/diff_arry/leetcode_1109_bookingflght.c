typedef struct
{
	int* diff;
	int  diff_size;
}Difference;

Difference* difference_creat(int* nums,int numsSize)
{
	Difference* df=(Difference *)malloc(sizeof(Difference));
	df->diff_size=numsSize;
	df->diff=(int*)malloc(df->diff_size * sizeof(int));
	
	df->diff[0]=nums[0];
	for(int i=1;i<df->diff_size;i++)
	{
		df->diff[i]=nums[i]-nums[i-1];
	}
	
	return df;

}

void difference_increment(Difference * df,int i,int j, int val)
{
	df->diff[i]+=val;
	if(j+1<df->diff_size)
		df->diff[j+1]-=val;
}

int* difference_result(Difference* df)
{
	int * res =(int*)malloc(df->diff_size * sizeof(int));
	res[0]=df->diff[0];
	for(int i =1;i<df->diff_size;i++)
	{
		res[i]=res[i-1]+df->diff[i];
	}
	return res;
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) 
{
    int* nums=(int *)calloc(n,sizeof(int));
    Difference* df=difference_creat(nums,n);
    for(int op=0;op<bookingsSize;op++)//the nums of operations
    {
    	int l=bookings[op][0]-1;
    	int r=bookings[op][1]-1;
    	int val=bookings[op][2];
    	difference_increment(df,l,r,val);
	}
    
    int * result=difference_result(df);
    
    free(df->diff);
    free(df);
    *returnSize=n;
    return result;

}