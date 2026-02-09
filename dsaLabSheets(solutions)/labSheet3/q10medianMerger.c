#include <stdio.h>

double findMedian(int a[], int n, int b[], int m) {
    if (n > m) return findMedian(b, m, a, n);

    int low = 0, high = n;
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? -1e9 : a[cut1 - 1];
        int l2 = (cut2 == 0) ? -1e9 : b[cut2 - 1];
        int r1 = (cut1 == n) ? 1e9 : a[cut1];
        int r2 = (cut2 == m) ? 1e9 : b[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n + m) % 2 == 0)
                return ( (l1 > l2 ? l1 : l2) +
                         (r1 < r2 ? r1 : r2) ) / 2.0;
            else
                return (l1 > l2 ? l1 : l2);
        } else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    printf("%.2f", findMedian(a, n, b, m));
    return 0;
}
