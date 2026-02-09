#include <stdio.h>

void sort(int a[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int idx = 0, group = 1;

    while (idx < n) {
        int end = idx + group - 1;
        if (end >= n) end = n - 1;
        sort(a, idx, end);
        idx += group;
        group++;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

  