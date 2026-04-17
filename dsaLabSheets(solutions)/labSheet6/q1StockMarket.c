#include <stdio.h>

void stockSpan(int price[], int n) {
    int stack[n];
    int top = -1;
    int span[n];

    for (int i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    int price[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    stockSpan(price, n);
    return 0;
}