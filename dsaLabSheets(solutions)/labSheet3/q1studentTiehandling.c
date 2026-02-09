#include <stdio.h>

struct Student {
    int marks;
    int delay;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Student a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].marks, &a[i].delay);
    }

    // Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].marks < a[j + 1].marks ||
               (a[j].marks == a[j + 1].marks && a[j].delay > a[j + 1].delay)) {
                struct Student temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i].marks, a[i].delay);
    }

    return 0;
}
