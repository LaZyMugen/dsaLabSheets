#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int left[n], right[n], stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[stack[top]] > arr[i]) top--;
        left[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && arr[stack[top]] >= arr[i]) top--;
        right[i] = (top == -1) ? (n - i) : (stack[top] - i);
        stack[++top] = i;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long long)arr[i] * left[i] * right[i];

    printf("%lld", sum);
    return 0;
}