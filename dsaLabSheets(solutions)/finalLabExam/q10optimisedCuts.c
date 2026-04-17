#include <stdio.h>

int min(int a,int b){ return a<b?a:b; }

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    int cuts[105];
    for(int i=1;i<=M;i++) scanf("%d",&cuts[i]);

    cuts[0]=0;
    cuts[M+1]=N;

    // sort cuts
    for(int i=1;i<=M;i++){
        for(int j=i+1;j<=M;j++){
            if(cuts[i]>cuts[j]){
                int t=cuts[i]; cuts[i]=cuts[j]; cuts[j]=t;
            }
        }
    }

    int dp[105][105]={0};

    for(int len=2;len<=M+1;len++){
        for(int i=0;i+len<=M+1;i++){
            int j=i+len;
            dp[i][j]=1000000000;

            for(int k=i+1;k<j;k++){
                int cost = dp[i][k] + dp[k][j] + (cuts[j]-cuts[i]);
                dp[i][j]=min(dp[i][j], cost);
            }

            if(dp[i][j]==1000000000) dp[i][j]=0;
        }
    }

    printf("%d\n",dp[0][M+1]);
    return 0;
}