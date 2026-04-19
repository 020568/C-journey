#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int** pnum;//prefix sum arry
	int m;//row
	int n;//col
	
}pre_sum;

pre_sum* presum_arry_creat(int** matrix , int m , int n)
{
	pre_sum* presum_arry = (pre_sum*)malloc(sizeof(pre_sum));
	presum_arry->m=m;
	presum_arry->n=n;
	//creat the prefix sum arry
	presum_arry->pnum=(int**)calloc(m+1,sizeof(int*));
	for(int i=0;i<=m;i++)
	{
		presum_arry->pnum[i]=(int *)calloc(n+1,sizeof(int));
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			presum_arry->pnum[i][j]=presum_arry->pnum[i-1][j]+presum_arry->pnum[i][j-1]-presum_arry->pnum[i-1][j-1]+matrix[i-1][j-1];
			
		}
	}
	
	return presum_arry;
	
}

int matrix_sum(pre_sum* presum_arry,int x1,int y1,int x2, int y2)
{
	return presum_arry->pnum[x2+1][y2+1]-presum_arry->pnum[x1][y2+1]-presum_arry->pnum[x2+1][y1]+presum_arry->pnum[x1][y1];
}

void free_arry(pre_sum* presum_arry)
{
	for(int i=0;i<=presum_arry->m;i++)
		free(presum_arry->pnum[i]);
	free(presum_arry->pnum);
	free(presum_arry);
	
}

int main()
{
	int m =6;
	int n=7;
	int ** matrix=(int **)malloc(m*sizeof(int*));
	for (int i = 0; i < m; i++) 
	{
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) matrix[i][j] = (i >= 1 && i <= 2 && j >= 1 && j <= 2) ? 5 : 0;
    }

	pre_sum* presum_arry=presum_arry_creat(matrix,m,n);
	int sum=matrix_sum(presum_arry,1,1,2,2);
	printf("%d",sum);
	free_arry(presum_arry);
	
	
	
}


