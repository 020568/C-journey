#include <stdio.h>

int countways(int n)
{
    int prev1=1;
    int prev2=1;
    for(int i=2;i<=n;i++)
    {
        int current=prev1+prev2;
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}

int main()
{
    int n=4;
    int res=countways(n);
    printf("%d",res);
}