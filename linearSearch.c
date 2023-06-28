#include<stdio.h>

void linearSearch(int arr[],int n,int i,int ele){ 
    if(n==i){
        printf("%d is not present in the given array.\n",ele);
        return;
    }
    if(arr[i]==ele){
        printf("%d is present in %d index.\n",ele,i);
        return;
    }
    i++;
    linearSearch(arr,n,i,ele);
    return;
}

int main(){
    int i,n,ele,arr[100];
    printf("Enter the number of elements ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements you want to search: ");
    scanf("%d",&ele);
    linearSearch(arr,n,0,ele);
    return 0;
}