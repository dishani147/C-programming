#include <stdio.h>
#include <malloc.h>

int maxEle(int a[], int n)
{
    int max = a[0], x;
    for (int i = 0; i < n; i++)
    {
        x = a[i];
        if (max < x)
            max = x;
    }
    return max;
}

int main()
{
    // Your code goes here
    int n, max;
    printf("Enter the number of element you want : ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if (n > 0)
    {
        printf("Enter the elements : ");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        max = maxEle(a, n);
        printf("%d is the maximum element present in the array.\n", max);
    }
    else{
        printf("Given array is empty.\n");
    }

    return 0;
}