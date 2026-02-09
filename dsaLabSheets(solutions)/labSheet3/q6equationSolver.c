#include<stdio.h>

long long f(long long x){

        return 2*x*x*x- x*x+ 5*x;
}


int main(){
    long long y;
    scanf("%lld",&y);

    int low=0,high=80,ans=0;

    while(low<=high){
            int mid=(low+high)/2;
            if(f(mid)<=y){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;

            }

    }

printf("%d",ans);
return 0;

}