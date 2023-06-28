//Bubble Sort
#include <stdio.h>
#include <stdlib.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d   ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}
void bubbleSortAdaptive(int *a, int n)
{
    int i, j, isSorted;
    for (i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}
int main()
{
    int n, i,ch;
    printf("Enter the number of elements you want -  ");
    scanf("%d", &n);
    int *a = (int *)(malloc(n*sizeof(int)));
    printf("Enter the elements  -  \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printArray(a, n);
    printf("Which search you want to use \nFor Normal Bubble Sort  press 1 for Bubble Sort Adaptive 2....   ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        bubbleSort(a,n);
        break;
        case 2:
        bubbleSortAdaptive(a, n);
        break;
        default:
        printf("Thanks for visiting -  ");
    }
    printArray(a, n);
    return 0;
}