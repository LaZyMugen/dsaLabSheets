#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    k %= n;
    int temp[k];
    for (int i = 0; i < k; i++) temp[i] = arr[i];
    for (int i = k; i < n; i++) arr[i - k] = arr[i];
    for (int i = 0; i < k; i++) arr[n - k + i] = temp[i];
}

void rotateRight(int arr[], int n, int k) {
    k %= n;
    int temp[k];
    for (int i = 0; i < k; i++) temp[i] = arr[n - k + i];
    for (int i = n - 1; i >= k; i--) arr[i] = arr[i - k];
    for (int i = 0; i < k; i++) arr[i] = temp[i];
}

int main() {
    int n, d, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    scanf("%d", &d);
    scanf("%d", &k);

    if (d == 0) rotateLeft(arr, n, k);
    else rotateRight(arr, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
