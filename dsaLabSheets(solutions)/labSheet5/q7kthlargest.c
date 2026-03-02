#include <stdio.h>

int partition(int a[], int l, int r){
    int pivot=a[r], i=l;
    for(int j=l;j<r;j++){
        if(a[j]<=pivot){
            int t=a[i]; a[i]=a[j]; a[j]=t;
            i++;
        }
    }
    int t=a[i]; a[i]=a[r]; a[r]=t;
    return i;
}

int quickSelect(int a[], int l, int r, int k){
    if(l<=r){
        int pi=partition(a,l,r);
        if(pi==k) return a[pi];
        else if(pi<k) return quickSelect(a,pi+1,r,k);
        else return quickSelect(a,l,pi-1,k);
    }
    return -1;
}

int main(){
    int N;
    scanf("%d",&N);

    int a[100005];
    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    int k;
    scanf("%d",&k);

    int result = quickSelect(a,0,N-1,N-k);
    printf("%d",result);
    return 0;
}