#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && a[i] % 2 == 0) even++;
        if (i % 2 == 1 && a[i] % 2 == 1) odd++;
    }

    printf("%d, %d", even, odd);
    return 0;
}
