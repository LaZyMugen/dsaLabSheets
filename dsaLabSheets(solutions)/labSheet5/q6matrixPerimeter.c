#include <stdio.h>

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    int a[101][101];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&a[i][j]);

    int layers = (N<M?N:M)/2;

    for(int l=0;l<layers;l++){
        int top=l, left=l;
        int bottom=N-l-1, right=M-l-1;

        if(top==bottom || left==right) continue;

        int temp[400], k=0;

        for(int j=left;j<=right;j++) temp[k++]=a[top][j];
        for(int i=top+1;i<=bottom;i++) temp[k++]=a[i][right];
        for(int j=right-1;j>=left;j--) temp[k++]=a[bottom][j];
        for(int i=bottom-1;i>top;i--) temp[k++]=a[i][left];

        int shift = (l%2==0)?1:-1;
        int rotated[400];

        for(int i=0;i<k;i++){
            int ni = (i+shift+k)%k;
            rotated[ni]=temp[i];
        }

        k=0;
        for(int j=left;j<=right;j++) a[top][j]=rotated[k++];
        for(int i=top+1;i<=bottom;i++) a[i][right]=rotated[k++];
        for(int j=right-1;j>=left;j--) a[bottom][j]=rotated[k++];
        for(int i=bottom-1;i>top;i--) a[i][left]=rotated[k++];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}