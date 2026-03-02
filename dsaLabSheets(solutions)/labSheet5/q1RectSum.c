#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int a[101][101], pref[101][101];

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            pref[i][j] = a[i][j] 
                        + pref[i-1][j] 
                        + pref[i][j-1] 
                        - pref[i-1][j-1];
        }
    }

    int a1,b1,a2,b2;
    scanf("%d %d %d %d",&a1,&b1,&a2,&b2);

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            printf("%d ",pref[i][j]);
        }
        printf("\n");
    }

    int sum = pref[a2][b2]
              - pref[a1-1][b2]
              - pref[a2][b1-1]
              + pref[a1-1][b1-1];

    printf("Sum = %d",sum);

    return 0;
}