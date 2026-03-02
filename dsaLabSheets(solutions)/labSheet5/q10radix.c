#include <stdio.h>

int getMax(int a[], int N){
    int max=a[0];
    for(int i=1;i<N;i++)
        if(a[i]>max) max=a[i];
    return max;
}

void countSort(int a[], int N, int exp){
    int output[100005], count[10]={0};

    for(int i=0;i<N;i++)
        count[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    for(int i=N-1;i>=0;i--){
        int idx=(a[i]/exp)%10;
        output[count[idx]-1]=a[i];
        count[idx]--;
    }

    for(int i=0;i<N;i++)
        a[i]=output[i];
}

int main(){
    int N;
    scanf("%d",&N);

    int a[100005];
    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    int max=getMax(a,N);

    for(int exp=1; max/exp>0; exp*=10)
        countSort(a,N,exp);

    for(int i=0;i<N;i++)
        printf("%d ",a[i]);

    return 0;
}