#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* memo)
{
    if(n<=1) return n;
    if(memo[n]!=-1) return memo[n];
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
}
int findmethod(int n)
{
    int* memo=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++) memo[i]=-1;
    int result=fib(n,memo);
    free(memo);
    return result;
}

int main()
{
    int res=findmethod(5);
    printf("%d",res);
}