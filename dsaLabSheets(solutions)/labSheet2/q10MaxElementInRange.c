#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > k)
            l++;
        int size = r - l + 1;
        if (size > ans) ans = size;
    }

    printf("%d", ans);
    return 0;
}
