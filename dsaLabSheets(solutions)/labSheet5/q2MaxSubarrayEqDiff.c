#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);

    int a[100005];
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);

    int maxLen = 2, start = 1, end = 2;

    int currStart = 1;
    int diff = a[2]-a[1];

    for(int i=2;i<N;i++){
        if(a[i+1]-a[i] == diff){
            if(i+1-currStart+1 > maxLen){
                maxLen = i+1-currStart+1;
                start = currStart;
                end = i+1;
            }
        } else {
            currStart = i;
            diff = a[i+1]-a[i];
        }
    }

    printf("%d %d",start,end);
    return 0;
}