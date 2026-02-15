
//basically if we guess a time limit t wcan check is it possible to assign boards so no painter exceeds t
//if t works any larger t works if t fails smaller t also fails
//monotonic so bs
//minimum time=max(board length)
//max time=sum of all boards ....consider 1 unitlengthboard=1min
#include <stdio.h>

int canPaint(int arr[], int N, int K, long long maxTime) {
    long long sum = 0;
    int painters = 1;

    for(int i=0;i<N;i++) {
        if(arr[i] > maxTime) return 0;

        if(sum + arr[i] > maxTime) {
            painters++;
            sum = arr[i];
        } else
            sum += arr[i];
    }

    return painters <= K;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    long long sum = 0;

    for(int i=0;i<N;i++) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    long long low = 0, high = sum, ans = sum;

    while(low <= high) {
        long long mid = (low+high)/2;

        if(canPaint(arr,N,K,mid)) {
            ans = mid;
            high = mid-1;
        } else
            low = mid+1;
    }

    printf("%lld", ans);
    return 0;
}
