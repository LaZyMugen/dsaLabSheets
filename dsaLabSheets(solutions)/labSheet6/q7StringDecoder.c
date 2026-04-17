#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[1000];
    scanf("%s", s);

    char stackStr[1000][100];
    int stackNum[1000];

    int top = -1;
    char current[100] = "";
    int num = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            stackNum[++top] = num;
            strcpy(stackStr[top], current);
            num = 0;
            current[0] = '\0';
        }
        else if (s[i] == ']') {
            char temp[100] = "";
            int repeat = stackNum[top];
            for (int j = 0; j < repeat; j++)
                strcat(temp, current);

            strcpy(current, stackStr[top]);
            strcat(current, temp);
            top--;
        }
        else {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    printf("%s", current);
    return 0;
}