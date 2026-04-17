// q14.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{int x,y,set;}P;

int abs(int x){return x<0?-x:x;}
int min(int a,int b){return a<b?a:b;}

int dist(P a,P b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int cmpx(const void*a,const void*b){
    return ((P*)a)->x-((P*)b)->x;
}
int cmpy(const void*a,const void*b){
    return ((P*)a)->y-((P*)b)->y;
}

int brute(P p[],int n){
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(p[i].set!=p[j].set)
                ans=min(ans,dist(p[i],p[j]));
    return ans;
}

int strip(P s[],int n,int d){
    qsort(s,n,sizeof(P),cmpy);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && abs(s[j].y-s[i].y)<d;j++){
            if(s[i].set!=s[j].set)
                d=min(d,dist(s[i],s[j]));
        }
    }
    return d;
}

int solve(P p[],int n){
    if(n<=3) return brute(p,n);

    int mid=n/2;
    int dl=solve(p,mid);
    int dr=solve(p+mid,n-mid);
    int d=min(dl,dr);

    P stripArr[n];
    int j=0;
    for(int i=0;i<n;i++)
        if(abs(p[i].x-p[mid].x)<d)
            stripArr[j++]=p[i];

    return min(d,strip(stripArr,j,d));
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    P p[n+m];
    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
        p[i].set=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&p[n+i].x,&p[n+i].y);
        p[n+i].set=1;
    }

    qsort(p,n+m,sizeof(P),cmpx);

    printf("%d",solve(p,n+m));
}