//basically  answer lies in max(wts)...sum(wts)  so monotonic function of days required with respect to capacity...so binary search on capacity and check if days required is less than or equal to d then we can try for smaller capacity else we need to increase capacity
//give n,c capacity start day 1 if adding package exceeds cstart new day count total days needed
//days<=d capacity works
//think ulta agar capacity pata hai to usse days kaise nikale then imply condition of days<=d 
#include <stdio.h>

int daysRequired(int wts[],int n,int capacity){

    int days=1, sum=0;
     for(int i=0;i<n;i++){
        if(sum+wts[i]>capacity){
            days++;
            sum=wts[i];
        } else {
            sum+=wts[i];        
        }
     }
        return days;  }


int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int wts[n],max=0,sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&wts[i]);
        if(wts[i]>max) max=wts[i];
        sum+=wts[i];
    }

    int low=max,high=sum,ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(daysRequired(wts,n,mid)<=d){
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }

    printf("%d",ans);
    return 0;




}