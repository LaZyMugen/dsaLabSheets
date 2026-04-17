// q13.c
#include <stdio.h>

long long max(long long a,long long b){return a>b?a:b;}
long long min(long long a,long long b){return a<b?a:b;}

int main(){
    int n;
    scanf("%d",&n);

    long long a[n],dp[n][n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);


    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            long long x=(i+2<=j)?dp[i+2][j]:0;
            long long y=(i+1<=j-1)?dp[i+1][j-1]:0;
            long long z=(i<=j-2)?dp[i][j-2]:0;

            dp[i][j]=max(a[i]+min(x,y), a[j]+min(y,z));
            
        }
    }

    printf("%lld",dp[0][n-1]);
}