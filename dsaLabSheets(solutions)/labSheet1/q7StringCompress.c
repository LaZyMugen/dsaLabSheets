#include <stdio.h>
#include <string.h>

int main() {
    char str[200], comp[400];
    scanf("%s", str);

    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
        idx += sprintf(comp + idx, "%c%d", str[i], count);
    }

    int originalLen = strlen(str);
    int compressedLen = strlen(comp);

    if (compressedLen <= originalLen)
        printf("%s\n", comp);
    else
        printf("%s\n", str);

    return 0;
}
