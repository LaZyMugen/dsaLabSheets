#include <stdio.h>

int canFinish(int a[], int n, int h, int speed) {
    int hours = 0;
    for (int i = 0; i < n; i++) {
        hours += (a[i] + speed - 1) / speed;
    }
    return hours <= h;
}

int main() {
    int n, h;
    scanf("%d %d", &n, &h);

    int a[n], max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) max = a[i];
    }

    int low = 1, high = max, ans = max;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canFinish(a, n, h, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}
