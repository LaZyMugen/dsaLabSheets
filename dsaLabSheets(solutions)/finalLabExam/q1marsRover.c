#include <stdio.h>
#define MOD 1000000007

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int grid[100][100], dp[100][100];

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&grid[i][j]);

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==1) dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else{
                int up = (i>0)?dp[i-1][j]:0;
                int left = (j>0)?dp[i][j-1]:0;
                dp[i][j]=(up+left)%MOD;
            }
        }
    }

    printf("%d\n", dp[M-1][N-1]);
    return 0;
}