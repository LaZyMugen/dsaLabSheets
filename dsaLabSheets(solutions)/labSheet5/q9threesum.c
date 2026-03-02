#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    int a[1005];
    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    for(int i=0;i<N-1;i++)
        for(int j=0;j<N-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }

    int found=0;

    for(int i=0;i<N-2;i++){
        if(i>0 && a[i]==a[i-1]) continue;

        int l=i+1, r=N-1;

        while(l<r){
            int sum=a[i]+a[l]+a[r];
            if(sum==0){
                printf("%d %d %d\n",a[i],a[l],a[r]);
                found=1;
                l++; r--;
                while(l<r && a[l]==a[l-1]) l++;
                while(l<r && a[r]==a[r+1]) r--;
            }
            else if(sum<0) l++;
            else r--;
        }
    }

    if(!found) printf("No triplets found");

    return 0;
}