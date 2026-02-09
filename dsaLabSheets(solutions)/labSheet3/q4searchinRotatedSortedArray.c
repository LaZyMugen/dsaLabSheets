//atleast one half is sorted always
//for any mid, either left half is sorted or right
//basically divivde into halves 
//Case A: Left half is sorted....a[low] <= a[mid]  ex:[4 5 6] -3 -2 0 2
//then search left only
//simlarly for right
// binary search nested inside if else
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int target;
    scanf("%d", &target);

int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == target) {
            printf("%d", mid);
            return 0;
        }

        if(a[low]<a[mid] ){
            if(target>=a[low] && target<a[mid])
                high=mid-1;//search in left sorted half
            else
                low=mid+1;//search in right half
        }

        else{
            if (target > a[mid] && target <= a[high])
                low = mid + 1;
            else
                high = mid - 1;

        }

    
    }   

    printf("-1");
    return 0;

}