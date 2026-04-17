#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int input[n], target[n];
    for (int i = 0; i < n; i++) scanf("%d", &input[i]);
    for (int i = 0; i < n; i++) scanf("%d", &target[i]);

    int stack[n], top = -1, j = 0;

    for (int i = 0; i < n; i++) {
        stack[++top] = input[i];
        printf("Push\n");

        while (top != -1 && stack[top] == target[j]) {
            top--;
            printf("Pop\n");
            j++;
        }
    }

    if (top == -1)
        return 0;
    else
        printf("Impossible");

    return 0;
}