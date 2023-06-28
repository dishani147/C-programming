#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int A[],int low,int high){
    int pivot = A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j)
        swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[low],&A[j]);

    return j;
}
void quickSort(int A[], int low, int high)
{
    int partitionIndex;
    if(low<high){
        partitionIndex=partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }
}
int main()
{
    int a[10],n,i,low=0,high;
    printf("Enter the number of elemets you want -\t");
    scanf("%d",&n);
    high=n-1;
    printf("Enter the elemets -\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printArray(a, n);
    quickSort(a,low,high);
    printArray(a, n);
    return 0;

}