#include <stdio.h>

int max(int a,int b){ return a>b?a:b; }

int main(){
    int N,K;
    scanf("%d %d",&N,&K);

    int price[1000];
    for(int i=0;i<N;i++) scanf("%d",&price[i]);

    int dp[100][1000]={0};

    for(int i=1;i<=K;i++){
        int maxDiff = -price[0];
        for(int j=1;j<N;j++){
            dp[i][j] = max(dp[i][j-1], price[j] + maxDiff);
            if(dp[i-1][j] - price[j] > maxDiff)
                maxDiff = dp[i-1][j] - price[j];
        }
    }

    printf("%d\n",dp[K][N-1]);
    return 0;
}