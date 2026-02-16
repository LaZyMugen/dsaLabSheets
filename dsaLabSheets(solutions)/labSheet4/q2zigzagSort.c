#include <stdio.h>

void sort(int arr[], int l, int r) {
    for(int i = l; i <= r; i++)
        for(int j = l; j < r - (i - l); j++)
            if(arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int left = 0, right = N - 1, k = 1;
    int fromFront = 1;

    while(left <= right) {
        int size = k;
        if(size > right - left + 1)
            size = right - left + 1;

        if(fromFront) {
            sort(arr, left, left + size - 1);
            left += size;
        } else {
            sort(arr, right - size + 1, right);
            right -= size;
        }

        fromFront = !fromFront;
        k++;
    }

    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}
