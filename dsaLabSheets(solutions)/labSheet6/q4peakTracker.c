#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[n], minStack[n];
    int top = -1, minTop = -1;

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);
            stack[++top] = x;

            if (minTop == -1 || x <= minStack[minTop])
                minStack[++minTop] = x;
        }
        else if (op == 2) {
            if (top == -1) {
                printf("Stack Empty\n");
            } else {
                int val = stack[top--];
                printf("Popped: %d\n", val);

                if (val == minStack[minTop])
                    minTop--;
            }
        }
        else if (op == 3) {
            if (minTop == -1)
                printf("Stack Empty\n");
            else
                printf("Minimum: %d\n", minStack[minTop]);
        }
        else if (op == 4) {
            if (top == -1)
                printf("Stack Empty\n");
            else
                printf("Top: %d\n", stack[top]);
        }
    }
    return 0;
}