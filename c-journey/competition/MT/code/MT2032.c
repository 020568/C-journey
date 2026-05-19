#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[205];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }

    char temp[2000] = {0};
    int k = 0;

    for (int i = 0; str[i]; i++) {
        // 在 [ ] 前后加空格
        if (str[i] == '[' || str[i] == ']') {
            temp[k++] = ' ';
            temp[k++] = str[i];
            temp[k++] = ' ';
        }
        // 在 REPEAT 前面加空格（如果前面是字母/数字）
        else if (strncmp(str + i, "REPEAT", 6) == 0) {
            if (i > 0 && str[i - 1] != ' ') temp[k++] = ' ';
            for (int j = 0; j < 6; j++) temp[k++] = str[i + j];
            i += 5;
            // REPEAT 后面如果是数字，加空格
            if (str[i + 1] != ' ' && str[i + 1] != '\0') temp[k++] = ' ';
        }
        // 在 FD/BK 前面加空格（如果前面是字母/数字）
        else if (strncmp(str + i, "FD", 2) == 0) {
            if (i > 0 && str[i - 1] != ' ') temp[k++] = ' ';
            temp[k++] = 'F'; temp[k++] = 'D';
            i++;
            if (str[i + 1] != ' ' && str[i + 1] != '\0') temp[k++] = ' ';
        }
        else if (strncmp(str + i, "BK", 2) == 0) {
            if (i > 0 && str[i - 1] != ' ') temp[k++] = ' ';
            temp[k++] = 'B'; temp[k++] = 'K';
            i++;
            if (str[i + 1] != ' ' && str[i + 1] != '\0') temp[k++] = ' ';
        }
        else {
            temp[k++] = str[i];
        }
    }
    temp[k] = '\0';

    // 去掉多余空格
    char clean[2000] = {0};
    int j = 0, space = 0;
    for (int i = 0; temp[i]; i++) {
        if (temp[i] == ' ') {
            if (!space) clean[j++] = ' ';
            space = 1;
        } else {
            clean[j++] = temp[i];
            space = 0;
        }
    }
    // 去掉首尾空格
    int start = 0, end = strlen(clean) - 1;
    while (clean[start] == ' ') start++;
    while (end >= 0 && clean[end] == ' ') clean[end--] = '\0';

    char tok[200][50] = {0};
    char *p = strtok(clean + start, " ");
    int n = 0;
    while (p) {
        strcpy(tok[n++], p);
        p = strtok(NULL, " ");
    }

    long long res = 0;
    long long mul = 1;
    long long stk[100] = {0};
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(tok[i], "FD") == 0) {
            res += mul * atoll(tok[++i]);
        } else if (strcmp(tok[i], "BK") == 0) {
            res -= mul * atoll(tok[++i]);
        } else if (strcmp(tok[i], "REPEAT") == 0) {
            long long num = atoll(tok[++i]);
            i++;  // 跳过 '['
            stk[top++] = num;
            mul *= num;
        } else if (strcmp(tok[i], "]") == 0) {
            mul /= stk[--top];
        }
    }

    printf("%lld\n", res < 0 ? -res : res);
    return 0;
}