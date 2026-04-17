#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int stack[1000], top = -1;
    stack[++top] = -1;

    int maxLen = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen) maxLen = len;
            }
        }
    }

    printf("%d", maxLen);
    return 0;
}