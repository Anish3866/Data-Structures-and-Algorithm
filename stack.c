#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 10
void push(int item);
int pop();
void display();
int top=-1;
int a[MAXSIZE];
int main()
{
	int n,i,opt;
	do
	{
		printf("\nEnter a choice");
		printf("\n1: Push Operation");
		printf("\n2: Pop Operation");
		printf("\n3: Display data element");
		printf("\n4: Exit....\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter a number to insert into the stack...");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				n=pop();
				printf("\nThe deleted item is: %d",n);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	while(opt!=4);
	return 0;
}

void push(int item)
{
	if(top==MAXSIZE-1)
		printf("\nStack is full\n");
	else
	{
		top++;
		a[top]=item;
	}
}
pop()
{
	int item;
	if(top==-1)
	{
		printf("\nStack is empty\n");
		return -1;
	}
	else
	{
		item=a[top];
		top--;
		return item;
	}
}
void display()
{
	printf("\nThe items in the stack are:");
	int i;
		for(i=top;i>=0;i--)
		{
			printf("%d ",a[i]);
		}
}
