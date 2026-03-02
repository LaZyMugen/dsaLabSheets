#include <stdio.h>

int countDiv(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i!=n/i) cnt++;
        }
    }
    return cnt;
}

int main(){
    int N;
    scanf("%d",&N);

    int a[1005], div[1005];

    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        div[i]=countDiv(a[i]);
    }

    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(div[j]>div[j+1] ||
              (div[j]==div[j+1] && a[j]<a[j+1])){
                
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                t=div[j]; div[j]=div[j+1]; div[j+1]=t;
            }
        }
    }

    for(int i=0;i<N;i++)
        printf("%d ",a[i]);

    return 0;
}