#include <stdio.h>
#include <string.h>

int min(int a,int b,int c){
    int m=a<b?a:b;
    return m<c?m:c;
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    char A[200], B[200];
    scanf("%s",A);
    scanf("%s",B);

    int dp[200][200];

    for(int i=0;i<=N;i++) dp[i][0]=i;
    for(int j=0;j<=M;j++) dp[0][j]=j;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    printf("%d\n",dp[N][M]);
    return 0;
}