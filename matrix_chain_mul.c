#include<stdio.h>

int cost[10][10],s[10][10];

int mem(int p[],int i,int j){
  int min=9999,r;
  if(i==j){
    return 0;
  }
  else{
    for(int k=i;k<j;k++){
      r=mem(p,i,k)+mem(p,k+1,j)+p[i-1]*p[k]*p[j];
      if(r<min){
        min=r;
        cost[i][j]=min;
        s[i][j]=k;
      }
    }
  }
  return min;
}

int main(){
  int p[10],n,r;
  printf("Enter the number of matrix : ");
  scanf("%d",&n);
  printf("Enter the dimensions : ");
  for(int i=0;i<=n;i++)
    scanf("%d",&p[i]);
  r=mem(p,1,n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j){
        cost[i][j]=0;
        s[i][j]=0;
      }
      if(i>j){
        cost[i][j]=-1;
        s[i][j]=-1;
      }
    }
  }
  printf("minimum number of multiplication = %d\n",r);
  printf("cost Matrix is :-\n");
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d\t",cost[i][j]);
    }
    printf("\n");
  }
 printf("\n");
 printf("S Matrix is :-\n");
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d\t",s[i][j]);
    }
    printf("\n");
  }

  return 0;
}
