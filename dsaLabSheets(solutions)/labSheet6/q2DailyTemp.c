#include <stdio.h>

void nextGreater(int temp[], int n) {
    int stack[n], top = -1;
    int ans[n];

    for (int i = 0; i < n; i++) ans[i] = 0;

    for (int i = 0; i < n; i++) {
        while (top != -1 && temp[i] > temp[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    int temp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &temp[i]);

    nextGreater(temp, n);
    return 0;
}