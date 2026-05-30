#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    long long d;
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &d);
        long long num = d * (d + 2) * (2 * d + 1) / 8;
        
        // 核心修改：加上 \n 确保每个结果独占一行
        printf("%lld\n", num); 
    }
    
    return 0;
}