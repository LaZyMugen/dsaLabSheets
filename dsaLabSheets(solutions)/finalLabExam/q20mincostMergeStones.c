// q20.c
#include <stdio.h>
#include <limits.h>

long long min(long long a,long long b){return a<b?a:b;}

int main(){
    int n,K;
    scanf("%d %d",&n,&K);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    if((n-1)%(K-1)!=0){
        printf("-1");
        return 0;
    }

    long long pref[n+1];
    pref[0]=0;
    for(int i=0;i<n;i++)
        pref[i+1]=pref[i]+a[i];

    long long dp[n][n];

    for(int i=0;i<n;i++) dp[i][i]=0;

    for(int len=2;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            dp[i][j]=LLONG_MAX;

            for(int m=i;m<j;m+=K-1)
                dp[i][j]=min(dp[i][j],dp[i][m]+dp[m+1][j]);

            if((len-1)%(K-1)==0)
                dp[i][j]+=pref[j+1]-pref[i];
        }
    }

    printf("%lld",dp[0][n-1]);
}