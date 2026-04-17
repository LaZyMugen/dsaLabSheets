#include <stdio.h>

int largestRectangle(int h[], int n) {
    int stack[n + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        while (top != -1 && (i == n || h[i] < h[stack[top]])) {
            int height = h[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }
    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);

    int h[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    printf("%d", largestRectangle(h, n));
    return 0;
}