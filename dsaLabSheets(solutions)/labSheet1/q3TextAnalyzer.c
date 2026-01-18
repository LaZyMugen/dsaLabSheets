#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    fgets(str, sizeof(str), stdin);

    int words = 0, vowels = 0;
    int len = strlen(str);

    if (len > 1) words = 1;

    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (str[i] == ' ') words++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels++;
    }

    printf("Words: %d\n", words);
    printf("Vowels: %d\n", vowels);

    printf("Reversed: ");
    for (int i = len - 2; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
