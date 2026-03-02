#include <stdio.h>

int canPlace(int pos[], int N, int K, int dist){
    int count = 1;
    int last = pos[1];

    for(int i=2;i<=N;i++){
        if(pos[i]-last >= dist){
            count++;
            last = pos[i];
        }
    }
    return count>=K;
}

int main(){
    int N,K;
    scanf("%d %d",&N,&K);

    int pos[100005];
    for(int i=1;i<=N;i++) scanf("%d",&pos[i]);

    int low=0, high=pos[N]-pos[1], ans=0;

    while(low<=high){
        int mid=(low+high)/2;
        if(canPlace(pos,N,K,mid)){
            ans=mid;
            low=mid+1;
        } else high=mid-1;
    }

    printf("%d",ans);
    return 0;
}