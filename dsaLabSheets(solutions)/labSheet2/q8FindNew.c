#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n], B[n+2];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n+2; i++) scanf("%d", &B[i]);

    int x = 0;
    for (int i = 0; i < n; i++) x ^= A[i];
    for (int i = 0; i < n+2; i++) x ^= B[i];

    int setBit = x & -x;
    int a = 0, b = 0;

    for (int i = 0; i < n+2; i++) {
        if (B[i] & setBit) a ^= B[i];
        else b ^= B[i];
    }

    printf("%d %d", a, b);
    return 0;
}
