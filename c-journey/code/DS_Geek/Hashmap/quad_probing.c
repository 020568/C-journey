#include <stdio.h>
#include <stdlib.h>

void quadprobing(int* table,int tsize,int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		int hv=arr[i]%tsize;
		
		if(table[hv]==-1)
		{
			table[hv]=arr[i];
		}
		else
		{
			for(int j=1;j<=tsize;j++)
			{
				int t=(hv+j*j)%tsize;
			
				if(table[t]==-1)
				{
					table[t]=arr[i];
					break;
				}
			}
		}
	}
	
}

int main()
{
	int arr[]={50, 700, 76, 85, 92, 73, 101};
	int n=sizeof(arr)/sizeof(arr[0]);
	int tsize=11;
	int* table=(int*)malloc(tsize * sizeof(int));
	for(int i=0;i<tsize;i++)
	{
		table[i]=-1;
	}
	quadprobing(table,tsize,arr,n);
	
	for(int i=0;i<tsize;i++)
	{
		printf("%d ",table[i]);
	}
	
	printf("\n");
	free(table);
	return 0;
}













