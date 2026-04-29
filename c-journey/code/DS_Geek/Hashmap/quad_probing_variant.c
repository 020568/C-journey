#include <stdio.h>
#include <stdlib.h>

// 计算大于或等于 m 的最小 2 的幂
int nextPowerOf2(int m) {
    if (m <= 0) return 1;
    m--;
    m |= m >> 1;
    m |= m >> 2;
    m |= m >> 4;
    m |= m >> 8;
    m |= m >> 16;
    // 考虑到 64 位环境增加 32 位移位
    m |= m >> 32;
    m++;
    return m;
}

void quadProbing(int* table, int tsize, int* arr, int n) {
    for (int i = 0; i < n; i++) {
        // 初始哈希索引
        int hv = arr[i] % tsize;

        // 如果位置为空，直接放置
        if (table[hv] == -1) {
            table[hv] = arr[i];
        }
        else {
            // 获取探测步长上限 m
            int m = nextPowerOf2(tsize);

            // 执行变体二次探测
            for (int j = 1; j <= m; j++) {
                // 使用公式：(hv + (j + j * j) / 2) % m 计算新索引
                // 注意：这里取模的对象是 m 而不是 tsize
                int t = (hv + (j + j * j) / 2) % m;

                // 如果计算出的索引超出了原始表长，跳过
                if (t >= tsize)
                    continue;

                // 如果新位置为空，放置元素并退出探测循环
                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
}

int main() {
    int arr[] = { 21, 10, 32, 43, 54, 65, 87, 76 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int tsize = 11;

    // 动态分配哈希表空间
    int* table = (int*)malloc(tsize * sizeof(int));

    // 初始化哈希表为 -1
    for (int i = 0; i < tsize; i++) {
        table[i] = -1;
    }

    // 调用探测插入函数
    quadProbing(table, tsize, arr, n);

    // 打印输出结果
    for (int i = 0; i < tsize; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");

    // 释放内存
    free(table);

    return 0;
}