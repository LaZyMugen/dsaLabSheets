#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n], B[n + 2];

   
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n + 2; i++) {
        scanf("%d", &B[i]);
    }

   
    qsort(A, n, sizeof(int), cmp);
    qsort(B, n + 2, sizeof(int), cmp);

    int i = 0, j = 0;
    int res[2], idx = 0;

    
    while (i < n && j < n + 2) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else {
           
            res[idx++] = B[j];
            j++;
        }
    }

    
    while (j < n + 2) {
        res[idx++] = B[j++];
        
    }

    
    printf("%d %d", res[0], res[1]);

    return 0;
}
