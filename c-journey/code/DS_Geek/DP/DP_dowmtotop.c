int fiboOptimized(int n) 
{
    if (n <= 1) return n;
    int a = 0; // 代表 dp[i-2]
    int b = 1; // 代表 dp[i-1]
    int current;

    for (int i = 2; i <= n; i++) {
        current = a + b;
        a = b;       // 滚动更新
        b = current; // 滚动更新
    }
    return b;
}