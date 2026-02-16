//each pays min(income[i],c)
//total collected f (c)=sum(min(income[i],c))
//We must find:Smallest C such that F(C) ≥ G

#include <stdio.h>

long long collected(int arr[], int N, int cap) {
    long long sum=0;
    for(int i=0;i<N;i++)
        sum += (arr[i] < cap ? arr[i] : cap);
    return sum;
}

int main() {
    int N;
    long long G;
    scanf("%d %lld",&N,&G);

    int arr[N];
    long long total=0;

    for(int i=0;i<N;i++) {
        scanf("%d",&arr[i]);
        total+=arr[i];
    }

    if(total<G) {
        printf("-1");
        return 0;
    }

    int low=0, high=1000000, ans=-1;

    while(low<=high) {
        int mid=(low+high)/2;

        if(collected(arr,N,mid)>=G) {
            ans=mid;
            high=mid-1;
        } else
            low=mid+1;
    }

    printf("%d",ans);
    return 0;
}
