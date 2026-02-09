#include <stdio.h>

int findFirst(int a[], int n, int t) {
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == t) {
            ans = m;
            r = m - 1;
        } else if (a[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int findLast(int a[], int n, int t) {
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == t) {
            ans = m;
            l = m + 1;
        } else if (a[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int t;
    scanf("%d", &t);

    int first = findFirst(a, n, t);
    int last = findLast(a, n, t);

    printf("%d %d", first, last);
    return 0;
}
