#include<stdio.h>
void towerOfHanoi(int num,char from_rod, char to_rod, char aux_rod){
    if(num==1){
        printf("Move disc 1 from rod %c to rod %c.\n",from_rod,to_rod);
        return;
    } 
    towerOfHanoi(num-1,from_rod,aux_rod,to_rod);
    printf("Move disc %d from rod %c to rod %c.\n",num,from_rod,to_rod);
    towerOfHanoi(num-1,aux_rod,to_rod,from_rod);
}
int main(){
    int n;
    printf("Enter the number of disc : ");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');
    return 0;
}