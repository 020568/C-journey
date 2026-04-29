#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000001 // 缩小一点演示，10^7在栈上开销太大

typedef struct {
    int TABLE_SIZE;
    int keysPresent;
    int PRIME;
    int* hashTable;
    char* isPrimeSieve; // 替代 bitset
} DoubleHash;

// 1. 埃拉托斯特尼筛法 (Sieve of Eratosthenes)
void setSieve(char* sieve) {
    sieve[0] = sieve[1] = 1;
    for (long long i = 2; i * i < MAX_SIZE; i++) {
        if (sieve[i] == 0) {
            for (long long j = i * i; j < MAX_SIZE; j += i)
                sieve[j] = 1;
        }
    }
}

// 2. 哈希函数
int hash1(int value, int size) { return value % size; }
int hash2(int value, int prime) { return prime - (value % prime); }

// 3. 初始化
DoubleHash* createTable(int n) {
    DoubleHash* dh = (DoubleHash*)malloc(sizeof(DoubleHash));
    dh->TABLE_SIZE = n;
    dh->keysPresent = 0;
    
    // 准备筛法找质数
    dh->isPrimeSieve = (char*)calloc(MAX_SIZE, sizeof(char));
    setSieve(dh->isPrimeSieve);

    // 寻找小于 TABLE_SIZE 的最大质数
    dh->PRIME = n - 1;
    while (dh->PRIME > 0 && dh->isPrimeSieve[dh->PRIME] == 1)
        dh->PRIME--;

    // 初始化哈希表数组
    dh->hashTable = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dh->hashTable[i] = -1;

    return dh;
}

// 4. 搜索操作
bool search(DoubleHash* dh, int value) {
    int probe = hash1(value, dh->TABLE_SIZE);
    int offset = hash2(value, dh->PRIME);
    int initialPos = probe;
    bool firstItr = true;

    while (1) {
        if (dh->hashTable[probe] == -1) return false;
        if (dh->hashTable[probe] == value) return true;
        if (!firstItr && probe == initialPos) return false;
        
        probe = (probe + offset) % dh->TABLE_SIZE;
        firstItr = false;
    }
}

// 5. 插入操作
void insert(DoubleHash* dh, int value) {
    if (dh->keysPresent == dh->TABLE_SIZE) {
        printf("ERROR : Hash Table Full\n");
        return;
    }

    int probe = hash1(value, dh->TABLE_SIZE);
    int offset = hash2(value, dh->PRIME);

    // 探测直到找到空位(-1)或已删除位(-2)
    while (dh->hashTable[probe] != -1 && dh->hashTable[probe] != -2) {
        probe = (probe + offset) % dh->TABLE_SIZE;
    }

    dh->hashTable[probe] = value;
    dh->keysPresent++;
}

// 6. 删除操作
void erase(DoubleHash* dh, int value) {
    if (!search(dh, value)) return;

    int probe = hash1(value, dh->TABLE_SIZE);
    int offset = hash2(value, dh->PRIME);

    while (dh->hashTable[probe] != -1) {
        if (dh->hashTable[probe] == value) {
            dh->hashTable[probe] = -2; // 标记为已删除
            dh->keysPresent--;
            return;
        }
        probe = (probe + offset) % dh->TABLE_SIZE;
    }
}

void printTable(DoubleHash* dh) {
    for (int i = 0; i < dh->TABLE_SIZE; i++) {
        printf("%d, ", dh->hashTable[i]);
    }
    printf("\n");
}

int main() {
    DoubleHash* myHash = createTable(13);

    int insertions[] = {115, 12, 87, 66, 123};
    for (int i = 0; i < 5; i++) insert(myHash, insertions[i]);

    printf("Table status: "); printTable(myHash);

    if (search(myHash, 12)) printf("12 is present\n");
    
    erase(myHash, 87);
    printf("After deleting 87: "); printTable(myHash);

    return 0;
}
























