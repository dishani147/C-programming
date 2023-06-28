#include<stdio.h>
void swap(int*, int*);
void swap(int*a,int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a[10],i,j,n;
    printf("Enter how many numbers do you want to take \t");
    scanf("%d",&n);
    printf("Enter the elements in the array \t");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            swap(&a[i],&a[j]);
        }
    }
    printf("Sorted array is \t");
    for(i=0;i<n;i++)
    printf("%d\t",&a[i]);
    return 0;
}