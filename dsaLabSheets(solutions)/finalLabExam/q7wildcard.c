#include <stdio.h>
#include <string.h>

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    char s[200], p[200];
    scanf("%s",s);
    scanf("%s",p);

    int dp[200][200]={0};

    dp[0][0]=1;

    for(int j=1;j<=M;j++)
        if(p[j-1]=='*') dp[0][j]=dp[0][j-1];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(p[j-1]=='*')
                dp[i][j]=dp[i][j-1] || dp[i-1][j];
            else if(p[j-1]=='?' || s[i-1]==p[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=0;
        }
    }

    if(dp[N][M]) printf("YES\n");
    else printf("NO\n");

    return 0;
}