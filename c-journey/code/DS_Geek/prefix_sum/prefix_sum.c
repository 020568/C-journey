#include <stdio.h>
#include <stdlib.h>

int* prefix_arr(int* arr,int n)
{
    int* prefix_arr=(int*)malloc(n*sizeof(arr[0]));
    if(prefix_arr==NULL)
    {
        return NULL;
    }

    prefix_arr[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_arr[i]=prefix_arr[i-1]+arr[i];
    }
    return prefix_arr;
}

int main()
{
    int arr[]={10, 20, 10, 5, 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int* prefix_sum=prefix_arr(arr,n);
    if(prefix_arr==NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",prefix_sum[i]);
    }
    free(prefix_sum);
    return 0;
}