#include<stdio.h>
#define MAX 5
void push(int);
int pop();

void showStack();
int s[100],top=-1;

int main()
{
   int ch,x;
   do
   {
      printf("--Stack Menu--\n");
      printf("1.push\n");
      printf("2.pop\n");
      printf("3.Display Stack\n");
      printf("4.Exit\n");
      printf("Enter ur choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
               printf("Entr an item to be pushed:");
               scanf("%d",&x);
               push(x);
               break;
          case 2:
               x=pop();
               if(x!=0)
                   printf("\n the popped item is: %d\n",x);
               break;
          case 3:
               showStack();
               break;
          case 4:
               printf("Good Day\n");
               break;
          default:
               printf("Invalid input\n");
      }
    }while(ch!=4);
}
void push(int n)
{
     if(top>=MAX-1)
     {
          printf("\n--Stack Overflow---\n");
     }
     else
     {
         top++;
         s[top]=n;
         printf("\n the item %d is pushed \n",n);
     }
}
int pop()
{
   int n;
   if(top<=-1)
   {
        printf("\n--Stack Underflow--\n");
        return(0);
   }
   n=s[top];
   top--;
   return(n);
}
void showStack()
{
    int i;
    printf("the stack contains: ");
    for(i=0;i<=top;i++)
    {
        printf("%d  ",s[i]);    
    }
}





