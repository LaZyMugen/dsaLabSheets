// q19.c
#include <stdio.h>
#include <stdlib.h>

typedef struct{int x,h;}P;
typedef struct{P*arr;int sz;}S;

S merge(S a,S b){
    P*res=malloc(sizeof(P)*(a.sz+b.sz));
    int i=0,j=0,k=0,h1=0,h2=0;

    while(i<a.sz && j<b.sz){
        int x;
        if(a.arr[i].x<b.arr[j].x){
            x=a.arr[i].x; h1=a.arr[i].h; i++;
        } else {
            x=b.arr[j].x; h2=b.arr[j].h; j++;
        }
        int h=h1>h2?h1:h2;
        if(k==0||res[k-1].h!=h) res[k++]=(P){x,h};
    }

    while(i<a.sz){
        if(k==0||res[k-1].h!=a.arr[i].h)
            res[k++]=a.arr[i];
        i++;
    }

    while(j<b.sz){
        if(k==0||res[k-1].h!=b.arr[j].h)
            res[k++]=b.arr[j];
        j++;
    }

    S s={res,k};
    return s;
}

S solve(int b[][3],int l,int r){
    if(l==r){
        S s;
        s.arr=malloc(sizeof(P)*2);
        s.sz=2;
        s.arr[0]=(P){b[l][0],b[l][2]};
        s.arr[1]=(P){b[l][1],0};
        return s;
    }

    int m=(l+r)/2;
    return merge(solve(b,l,m),solve(b,m+1,r));
}

int main(){
    int n;
    scanf("%d",&n);

    int b[n][3];
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&b[i][0],&b[i][1],&b[i][2]);

    S s=solve(b,0,n-1);

    for(int i=0;i<s.sz;i++)
        printf("%d %d ",s.arr[i].x,s.arr[i].h);
}