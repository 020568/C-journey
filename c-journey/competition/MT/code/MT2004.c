#include <stdio.h>
#include <string.h>

int main() {
    char s[205];      // 200位 + 保险
    scanf("%s", s);   // 用 %s 读字符串，保留前导零
    
    int n = strlen(s);
    
    // 1. 去掉前导零
    int start = 0;
    while (start < n - 1 && s[start] == '0') {
        start++;
    }
    // 把有效部分搬到前面
    int m = n - start;
    for (int i = 0; i < m; i++) {
        s[i] = s[start + i];
    }
    s[m] = '\0';
    
    int half = (m + 1) / 2;
    
    // 2. 构造镜像候选
    char t[205];
    strcpy(t, s);
    for (int i = m / 2; i < m; i++) {
        t[i] = t[m - 1 - i];  // 后半部分复制前半部分的镜像
    }
    
    // 3. 如果镜像 <= 原数，直接输出
    if (strcmp(t, s) <= 0) {
        printf("%s\n", t);
        return 0;
    }
    
    // 4. 镜像 > 原数，前半部分减 1
    int i = half - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';   // 借位
        i--;
    }
    if (i >= 0) {
        s[i]--;       // 减 1
    }
    
    // 5. 如果减 1 后出现前导零（如 "10" 变成 "09"），输出 m-1 个 9
    if (s[0] == '0') {
        for (int i = 0; i < m - 1; i++) {
            printf("9");
        }
        printf("\n");
        return 0;
    }
    
    // 6. 否则，将减 1 后的前半部分镜像到后半部分
    for (int i = m / 2; i < m; i++) {
        s[i] = s[m - 1 - i];
    }
    printf("%s\n", s);
    return 0;
}