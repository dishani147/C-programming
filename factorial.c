#include<stdio.h>
int factorial(int n){
    if(n>1)
        return n*factorial(n-1);
    return 1;
}
int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Factorial of %d is %d.",num,factorial(num));
    return 0;
}