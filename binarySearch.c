#include <stdio.h>
void binarySearch(int arr[], int lb, int ub, int ele){
    if (lb > ub){
        printf("%d is not present in the given array.\n", ele);
        return;
    }
    else{
        int mid = (lb + ub) / 2;
        if (arr[mid] == ele){
            printf("%d is present in %d index.\n", ele, mid);
            return;
        }
        else if (arr[mid] > ele)
            ub = mid - 1;
        else
            lb = mid + 1;
        binarySearch(arr, lb, ub, ele);
    }
}
int main()
{
    int i, n, ele, arr[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in sorted order:- \n");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the elements you want to search: ");
    scanf("%d", &ele);
    binarySearch(arr, 0, n - 1, ele);
    return 0;
}