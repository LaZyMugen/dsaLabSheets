//array sorted strictly increasing so gueses binary
//at index i if no numbers missing expexted value=i+1
//actaul value=arr[i] so count of missing numbers before index i is basically arr[i]-(i+1)


//so we bs for first index where count of missing>=k
//Because:If missing < K → we haven't reached Kth missing yet → go right If missing ≥ K → possible answer → go left
//after binary search answer=low+k as low becomes the number of elements before kth missing spot so actual number=k missing numbers +number of real elements before it


#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = N-1;

    while(low <= high) {
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid+1);

        if(missing < K)
            low = mid+1;
        else
            high = mid-1;
    }

    printf("%d", low + K);
    return 0;
}
