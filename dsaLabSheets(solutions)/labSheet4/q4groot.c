#include <stdio.h>

int main() {
    long long K;
    scanf("%lld", &K);

    long long low = 1, high = K, ans = 0;

    while(low <= high) {
        long long mid = (low + high) / 2;

        if(mid * mid <= K) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }

    printf("%lld", ans);
    return 0;
}
