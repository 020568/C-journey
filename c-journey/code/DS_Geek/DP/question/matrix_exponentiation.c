#include <stdio.h>

void multiply(long long a[2][2], long long b[2][2]) {
    long long res[2][2];

    // Matrix Multiplication
    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    // Copy the result back to the first matrix
    a[0][0] = res[0][0];
    a[0][1] = res[0][1];
    a[1][0] = res[1][0];
    a[1][1] = res[1][1];
}

void power(long long m[2][2], int expo, long long res[2][2]) {
    
    // Initialize result with identity matrix
    res[0][0] = 1; res[0][1] = 0;
    res[1][0] = 0; res[1][1] = 1;

    while (expo) {
        if (expo & 1)
            multiply(res, m);
        multiply(m, m);
        expo >>= 1;
    }
}

int countWays(int n) {
    
    // base case
    if (n == 0 || n == 1)
        return 1;

    long long m[2][2] = { { 1, 1 }, { 1, 0 } };
    
    // Matrix initialMatrix = {{f(1), 0}, {f(0), 0}}, where f(0)
    // and f(1) are first two terms of sequence
    long long initialMatrix[2][2] = { { 1, 0 }, { 1, 0 } };

    // Multiply matrix m (n - 1) times
    long long res[2][2];
    power(m, n - 1, res);

    multiply(res, initialMatrix);

    return res[0][0];
}

int main() {
    int n = 4;
    printf("%d
",countWays(n));
    return 0;
}