// q17.c
#include <stdio.h>
#include <limits.h>

long long max(long long a,long long b){return a>b?a:b;}

long long cross(long long a[],int l,int m,int r){
    long long sum=0,left=LLONG_MIN;
    for(int i=m;i>=l;i--){
        sum+=a[i];
        if(sum>left) left=sum;
    }

    sum=0;
    long long right=LLONG_MIN;
    for(int i=m+1;i<=r;i++){
        sum+=a[i];
        if(sum>right) right=sum;
    }

    return left+right;
}

long long solve(long long a[],int l,int r){
    if(l==r) return a[l];
    int m=(l+r)/2;

    return max(max(solve(a,l,m),solve(a,m+1,r)),cross(a,l,m,r));
}

int main(){
    int n;
    scanf("%d",&n);

    long long a[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    printf("%lld",solve(a,0,n-1));
}