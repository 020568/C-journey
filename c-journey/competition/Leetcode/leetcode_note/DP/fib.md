# 509. 斐波那契数

**标签**：`递归` `记忆化搜索` `动态规划`  
**难度**：简单  
**日期**：2026-05-11

---

## 思路

- 第一感：递归 `F(n) = F(n-1) + F(n-2)`，但纯递归有大量重复计算
- 优化：用**备忘录（memoization）**存储已计算结果，避免重复递归
- 本质：自顶向下的动态规划

fib(5)
├── fib(4)           ← 第一次计算
│   ├── fib(3)       ← 第一次计算
│   │   ├── fib(2)   ← 第一次计算
│   │   │   ├── fib(1) = 1
│   │   │   └── fib(0) = 0
│   │   │   → memo[2] = 1
│   │   └── fib(1) = 1
│   │   → memo[3] = 2
│   └── fib(2)       ← 查备忘录，直接返回 1
│   → memo[4] = 3
└── fib(3)           ← 查备忘录，直接返回 2
→ memo[5] = 5



| 指标 | 值                  |
| :- | :----------------- |
| 时间 | O(n)：每个数字只计算一次     |
| 空间 | O(n)：递归栈深度 + 备忘录数组 |



## 代码

### C 语言版（记忆化递归）

```c
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

int fibRec(int n, int* memo) {
    // 基础情况
    if (n &lt;= 1) return n;

    // 查备忘录：如果已经算过，直接返回
    if (memo[n] != -1) return memo[n];

    // 计算、记录、返回
    memo[n] = fibRec(n - 1, memo) + fibRec(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    // 动态分配备忘录并初始化为 -1
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i<=n; i++) memo[i] = -1;

    int result = fibRec(n, memo);

    free(memo); // 别忘了释放内存
    return result;
}

int main() {
    int n = 5;
    printf("%d", fib(n));  // 5
    return 0;
}