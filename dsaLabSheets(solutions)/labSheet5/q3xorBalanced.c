#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    int a[100005];
    int totalXor = 0;

    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
        totalXor ^= a[i];
    }

    int leftXor = 0;

    for(int i=1;i<=N;i++){
        totalXor ^= a[i];

        if(i>=2 && i<=N-1){
            if(leftXor == totalXor)
                printf("%d ",i);
        }

        leftXor ^= a[i];
    }

    return 0;
}