#include <stdio.h>
//0/1 knapsack
int max(int a,int b){ return a>b?a:b; }

int main(){
    int N,H;
    scanf("%d %d",&N,&H);

    int val[100], wt[100];
    for(int i=0;i<N;i++) scanf("%d",&val[i]);
    for(int i=0;i<N;i++) scanf("%d",&wt[i]);

    int dp[100][1000]={0};

    for(int i=1;i<=N;i++){
        for(int j=0;j<=H;j++){
            if(wt[i-1]<=j)
                dp[i][j]=max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    printf("%d\n",dp[N][H]);
    return 0;
}