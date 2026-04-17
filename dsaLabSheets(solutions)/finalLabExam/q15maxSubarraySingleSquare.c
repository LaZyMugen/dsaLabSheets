// q15.c
#include <stdio.h>

long long max(long long a,long long b){return a>b?a:b;}

int main(){
    int n;
    scanf("%d",&n);

    long long a[n],dp0[n],dp1[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    dp0[0]=a[0];   //dp0[i]=Max subarray sum ending at index i WITHOUT using square
    dp1[0]=a[0]*a[0];  //dp1[i]=Max subarray sum ending at index i WITH using square

    long long ans=dp1[0];

    for(int i=1;i<n;i++){
        dp0[i]=max(a[i],dp0[i-1]+a[i]);
        dp1[i]=max(dp1[i-1]+a[i], dp0[i-1]+a[i]*a[i]);
        ans=max(ans,max(dp0[i],dp1[i]));
    }

    printf("%lld",ans);
}