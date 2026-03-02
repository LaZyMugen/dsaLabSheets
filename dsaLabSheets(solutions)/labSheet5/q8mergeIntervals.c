#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    int a[1005][2];

    for(int i=0;i<N;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);

    for(int i=0;i<N-1;i++){        //bubble sort
        for(int j=0;j<N-i-1;j++){
            if(a[j][0]>a[j+1][0]){
                int t1=a[j][0], t2=a[j][1];
                a[j][0]=a[j+1][0]; a[j][1]=a[j+1][1];
                a[j+1][0]=t1; a[j+1][1]=t2;
            }
        }
    }

    int start=a[0][0], end=a[0][1];

    for(int i=1;i<N;i++){
        if(a[i][0]<=end){
            if(a[i][1]>end) end=a[i][1];   //merges overlapping intervals
        } else {
            printf("%d %d\n",start,end);
            start=a[i][0];
            end=a[i][1];
        }
    }

    printf("%d %d",start,end);
    return 0;
}