#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N][2];

    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    // Simple bubble sort
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(arr[j][0] > arr[j+1][0] ||
              (arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1])) {

                int t1 = arr[j][0];
                int t2 = arr[j][1];

                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];

                arr[j+1][0] = t1;
                arr[j+1][1] = t2;
            }
        }
    }

    // Print sorted intervals
    for(int i = 0; i < N; i++)
        printf("%d %d\n", arr[i][0], arr[i][1]);

    // Check continuity
    int current_end = arr[0][1];
    int fragmented = 0;

    for(int i = 1; i < N; i++) {
        if(arr[i][0] > current_end) {
            fragmented = 1;
            break;
        }

        if(arr[i][1] > current_end)
            current_end = arr[i][1];
    }

    if(fragmented)
        printf("Fragmented");
    else
        printf("Contiguous");

    return 0;
}
