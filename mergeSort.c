#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n");
}
void merge(int A[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        A[i]=B[i]; 
    }
}
void mergeSort(int A[], int low, int high)
{int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main()
{
    int a[10],n,i;
    printf("Enter the number of elemets you want -\t");
    scanf("%d",&n);
    printf("Enter the elemets -\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Given Array -\n");
    printArray(a, n);
    mergeSort(a,0,8);
    printf("Sorted Array -\n");
    printArray(a, n);
    return 0;
}