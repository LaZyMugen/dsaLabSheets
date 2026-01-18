#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int A[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &A[i]);

    scanf("%d", &n2);
    int B[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &B[i]);

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (A[i] <= B[j]) printf("%d ", A[i++]);
        else printf("%d ", B[j++]);
    }

    while (i < n1) printf("%d ", A[i++]);
    while (j < n2) printf("%d ", B[j++]);

    printf("\n");
    return 0;
}
