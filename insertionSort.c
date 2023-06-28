#include <stdio.h>
#include <stdlib.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}
void insertionSort(int *a, int n)
{
    int key, i, j;
    for (i = 1; i <= n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    printf("Enter the number of element you want  -  ");
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    printf("Enter the elements  -  \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}