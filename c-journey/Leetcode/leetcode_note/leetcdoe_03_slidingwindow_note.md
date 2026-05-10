# 3. 无重复字符的最长子串

**标签**：`滑动窗口` `字符串` `双指针`  
**难度**：中等  
**日期**：2026-05-10

---

## 思路

- 第一感：暴力枚举所有子串判重，O(n³) 超时
- 优化：子串连续，想到滑动窗口
- 关键：
  1. 把字符转换为相应的数字，方便进行数组索引，并且字符在 ASCII 码表中连续，所以用 256 个数组元素即可。
  2. 初始化为 -1，表示字符未出现过。
  3. 遍历字符串，用双指针维护窗口边界，当字符重复时，更新窗口边界和最大长度。
  4. 比较条件的含义：每次循环先比较，如果字符已保存过，`lastpos` 里对应字符的位置保存了当时遍历到的 `right` 值，也就是字符在 `s` 中的具体位置。

     `lastpos` 的情况只有三种：
     - 没有出现过：`lastpos[ch] = -1`
     - 出现过，但不在窗口内：`-1 < lastpos[ch] < left`
     - 出现过，且在窗口内：`lastpos[ch] >= left`

  5. `memset` 函数的参数含义：
     - 第一个参数：要初始化的内存区域的指针
     - 第二个参数：要初始化的值
     - 第三个参数：要初始化的字节数

## 代码

```c
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int lastPos[256];
    memset(lastPos, -1, sizeof(lastPos));
    
    int left = 0, maxLen = 0;
    for (int right = 0; right < len; right++) {
        unsigned char ch = s[right];
        if (lastPos[ch] >= left) {
            left = lastPos[ch] + 1;
        }
        lastPos[ch] = right;
        maxLen = fmax(maxLen, right - left + 1);
    }
    return maxLen;
}
