#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int a[M][N];

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    int K;
    scanf("%d", &K);

    int i = 0;
    int j = N - 1;

    while(i < M && j >= 0) {

        if(a[i][j] == K) {
            printf("%d %d", i, j);
            return 0;
        }
        else if(a[i][j] > K)
            j--;
        else
            i++;
    }

    printf("-1");
    return 0;
}
