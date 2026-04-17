#include <stdio.h>
#include <string.h>

int max(int a,int b){ return a>b?a:b; }

int main(){
    int n;
    scanf("%d",&n);

    char s[200];
    scanf("%s",s);

    int dp[200][200]={0};

    for(int i=0;i<n;i++) dp[i][i]=1;

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(s[i]==s[j])
                dp[i][j]=2 + dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
        }
    }

    printf("%d\n",dp[0][n-1]);
    return 0;
}