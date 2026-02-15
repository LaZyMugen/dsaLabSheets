//each row sorted and total elements are odd
//basically binary search on answer space and not on index
// now median index = r*c/2  ...for median in sorted we can definitely say If count till candidate ≤ desired → median must be bigger

//Since each row is sorted, we can use binary search inside each row to count how many elements are ≤ X.



#include<stdio.h>

int countLessEqual(int arr[],int c,int x){  //does binary search in one row
    int l=0, r=c-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(arr[m] <= x)
            l = m+1;
        else
            r = m-1;
    }
    return l;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int a[R][C];
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d",&a[i][j]);

    int low = a[0][0], high = a[0][C-1];
    for(int i=1;i<R;i++) {
        if(a[i][0] < low) low = a[i][0];
        if(a[i][C-1] > high) high = a[i][C-1];
    }

    int desired = (R*C)/2;

    while(low <= high) {
        int mid = (low+high)/2;
        int count = 0;

        for(int i=0;i<R;i++)
            count += countLessEqual(a[i], C, mid);

        if(count <= desired)
            low = mid+1;
        else
            high = mid-1;
    }

    printf("%d", low);
    return 0;
}