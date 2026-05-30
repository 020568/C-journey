#include <stdio.h>

long long get_down(int N)
{
    if(N==0||N==1)
    {
        return 0;
    }

    return (N-1)+get_down(N-2);
}

long long solve(int N)
{
    if(N==1)
    {
        return 1;
    }

    long long new_top_rec=N*(N+1)/2;
    long long old=solve(N-1);
    long long new_down_rec=get_down(N);

    return new_down_rec+new_top_rec+old;
}

int main()
{
    int N;
    scanf("%d",&N);

   while(N--)
   {
        long long  div;
        scanf("%lld",&div);
        printf("%lld\n",solve(div));
   }
    
    
}