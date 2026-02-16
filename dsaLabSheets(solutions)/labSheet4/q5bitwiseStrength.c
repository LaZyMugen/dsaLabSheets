#include <stdio.h>

int strength(int x) {  //counts the number of set bits
    int count = 0;
    while(x) {
        count += x & 1; // x & 1 basically returns 1 if number odd 0 if number even
        x = x >> 1; // x/2
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < N-1; i++)  //selection sort with condition
        for(int j = 0; j < N-i-1; j++) {
            int s1 = strength(arr[j]);
            int s2 = strength(arr[j+1]);

            if(s1 < s2 || (s1 == s2 && arr[j] < arr[j+1])) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }

    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}
