#include <stdio.h>
#include <string.h>
//dsitinct subseuqneces
int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    char S[200], T[200];
    scanf("%s",S);
    scanf("%s",T);

    long long dp[200][200]={0};

    for(int i=0;i<=N;i++) dp[i][0]=1;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(S[i-1]==T[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    printf("%lld\n",dp[N][M]);
    return 0;
}