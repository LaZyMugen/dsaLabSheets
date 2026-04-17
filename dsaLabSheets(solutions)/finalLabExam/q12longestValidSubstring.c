// q12.c
#include <stdio.h>

int max(int a,int b){return a>b?a:b;}

int solve(char *s,int l,int r,int k){
    if(r-l+1<k) return 0;

    int f[26]={0};
    for(int i=l;i<=r;i++) f[s[i]-'a']++;

    for(int i=l;i<=r;i++){
        if(f[s[i]-'a']<k){
            return max(solve(s,l,i-1,k), solve(s,i+1,r,k));
        }
    }
    return r-l+1;
}

int main(){
    int n,k;
    char s[100005];

    scanf("%d %d",&n,&k);
    scanf("%s",s);

    printf("%d",solve(s,0,n-1,k));
}