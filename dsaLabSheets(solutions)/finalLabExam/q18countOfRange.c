#include <stdio.h>

#define MAX 100005

long long prefix[MAX];
long long temp[MAX];
int N, lower, upper;

// Merge + count function
long long mergeCount(int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long count = 0;

    count += mergeCount(left, mid);
    count += mergeCount(mid + 1, right);

    int i = left, j = mid + 1;
    int k = mid + 1, t = mid + 1;

    // Count valid ranges
    for (i = left; i <= mid; i++) {
        while (k <= right && prefix[k] - prefix[i] < lower) k++;
        while (t <= right && prefix[t] - prefix[i] <= upper) t++;
        count += (t - k);
    }

    // Merge step (standard merge sort)
    int p1 = left, p2 = mid + 1, idx = left;

    while (p1 <= mid && p2 <= right) {
        if (prefix[p1] <= prefix[p2])
            temp[idx++] = prefix[p1++];
        else
            temp[idx++] = prefix[p2++];
    }

    while (p1 <= mid) temp[idx++] = prefix[p1++];
    while (p2 <= right) temp[idx++] = prefix[p2++];

    for (i = left; i <= right; i++)
        prefix[i] = temp[i];

    return count;
}

int main() {
    int A[MAX];

    scanf("%d %d %d", &N, &lower, &upper);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // Build prefix sum
    prefix[0] = 0;
    for (int i = 0; i < N; i++)
        prefix[i + 1] = prefix[i] + A[i];

    // We use size N+1 prefix array
    long long result = mergeCount(0, N);

    printf("%lld\n", result);

    return 0;
}