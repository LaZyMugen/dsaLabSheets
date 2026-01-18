#include <stdio.h>

int exists(int arr[], int size, int x) {
    for (int i = 0; i < size; i++)
        if (arr[i] == x) return 1;
    return 0;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int A[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &A[i]);

    scanf("%d", &n2);
    int B[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &B[i]);

    printf("Union: ");
    for (int i = 0; i < n1; i++) printf("%d ", A[i]);
    for (int i = 0; i < n2; i++)
        if (!exists(A, n1, B[i])) printf("%d ", B[i]);

    printf("\nIntersection: ");
    int found = 0;
    for (int i = 0; i < n1; i++) {
        if (exists(B, n2, A[i])) {
            printf("%d ", A[i]);
            found = 1;
        }
    }
    if (!found) printf("(None)");
    printf("\n");

    return 0;
}
