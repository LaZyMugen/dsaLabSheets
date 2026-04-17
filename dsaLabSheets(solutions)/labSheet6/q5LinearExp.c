#include <stdio.h>
#include <ctype.h>

int main() {
    char exp[1000];
    scanf("%s", exp);

    double stack[1000];
    int top = -1;

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            if (top < 1) {
                printf("Invalid Expression");
                return 0;
            }

            double b = stack[top--];
            double a = stack[top--];

            if (exp[i] == '+') stack[++top] = a + b;
            else if (exp[i] == '-') stack[++top] = a - b;
            else if (exp[i] == '*') stack[++top] = a * b;
            else if (exp[i] == '/') {
                if (b == 0) {
                    printf("Invalid Expression");
                    return 0;
                }
                stack[++top] = a / b;
            }
        }
    }

    if (top != 0) {
        printf("Invalid Expression");
        return 0;
    }

    printf("%.2lf", stack[top]);
    return 0;
}