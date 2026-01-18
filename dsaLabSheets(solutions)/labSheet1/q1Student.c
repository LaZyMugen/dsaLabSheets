#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks[3];
    float avg;
};

int main() {
    int N;
    scanf("%d", &N);

    struct Student s[N];
    int topperIndex = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &s[i].id, s[i].name);
        float sum = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%f", &s[i].marks[j]);
            sum += s[i].marks[j];
        }
        s[i].avg = sum / 3.0;

        if (s[i].avg > s[topperIndex].avg) {
            topperIndex = i;
        }
    }

    printf("Merit List:\n");
    int found = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].avg > 75) {
            printf("%d %s (Avg: %.2f)\n", s[i].id, s[i].name, s[i].avg);
            found = 1;
        }
    }

    if (!found) {
        printf("(No Output)\n");
    }

    printf("Topper: %s\n", s[topperIndex].name);
    return 0;
}
