#include <stdio.h>

int max(int a,int b){ return a>b?a:b; }

int solve(int arr[], int start, int end){
    int prev=0, curr=0;
    for(int i=start;i<=end;i++){
        int temp = max(curr, prev + arr[i]);
        prev = curr;
        curr = temp;
    }
    return curr;
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[200];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    if(n==1){
        printf("%d\n",arr[0]);
        return 0;
    }

    int ans = max(solve(arr,0,n-2), solve(arr,1,n-1));
    printf("%d\n",ans);
    return 0;
}