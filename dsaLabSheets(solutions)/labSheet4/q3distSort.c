#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    int idx[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        idx[i] = i;   // store original index
    }

    // Bubble sort with index tracking
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                // swap values
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // swap corresponding indices
                int t = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = t;
            }
        }
    }

    // Check adjacent duplicates
    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i - 1]) {

            int diff = idx[i] - idx[i - 1];
            if(diff < 0) diff = -diff;

            if(diff > K) {
                printf("%d %d", idx[i - 1], idx[i]);
                return 0;
            }
        }
    }

    printf("-1");
    return 0;
}
