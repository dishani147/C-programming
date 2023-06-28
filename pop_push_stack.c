#include<stdio.h>
#include<conio.h>
#define max 5
int top =-1;
int stack_arr[max];
void push()
{
	int pushed_item;
	if(top==(max-1))
	{
		printf("stack is over flow");
	}
	else
	{
		printf("enter the item to push in stack:");
		scanf("%d",&pushed_item);
		top=top+1;
		stack_arr[top]=pushed_item;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack under flow");
	}
	else
	{
		printf("pop element is: %d ",stack_arr[top]);
		top=top-1;
	}
}
void peek()
{
	int pushed_item;
	if(top==-1)
	printf("stack is empty");
	else
	pushed_item=stack_arr[top];
	printf("the top element is:%d",pushed_item);
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is empty:");
	}
	else
	{
		printf("stack elements : \n");
		for(i=top;i>=0;i--)
		 printf("%d\n",stack_arr[i]);
	}
}
main()
{
	int ch,no;
	do
	{
		printf("\n....MENU.....\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.peek item\n");
		printf("5.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				printf("exit");
		}
	}while(ch!=5);
}