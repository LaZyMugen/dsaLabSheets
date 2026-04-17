// q16.c
#include <stdio.h>

long long merge(long long a[],int l,int m,int r,int k){
    long long cnt=0;
    int j=m+1;

    for(int i=l;i<=m;i++){
        while(j<=r && a[i]>(long long)k*a[j]) j++;
        cnt+=j-(m+1);
    }

    long long L[100000],R[100000];
    int n1=m-l+1,n2=r-m;

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0; j=0; int k2=l;

    while(i<n1 && j<n2)
        a[k2++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) a[k2++]=L[i++];
    while(j<n2) a[k2++]=R[j++];

    return cnt;
}

long long ms(long long a[],int l,int r,int k){
    if(l>=r) return 0;
    int m=(l+r)/2;
    return ms(a,l,m,k)+ms(a,m+1,r,k)+merge(a,l,m,r,k);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    long long a[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    printf("%lld",ms(a,0,n-1,k));
}