#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 5
void enqueue();
int dequeue();
void display();
int front=-1,rear=-1;
int a[MAXSIZE];
void main()
{
	int n,i,opt;
	do
	{
		printf("\nEnter a choice");
		printf("\n1: Enqueue Operation");
		printf("\n2: Dequeue Operation");
		printf("\n3: Display data element");
		printf("\n4: Exit....\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter a number to insert into the queue:-  ");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 2:
				n=dequeue();
				printf("\nThe deleted item is %d\n",n);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}while(opt!=4);
	getch();
}
void enqueue(int item)
{
	if(rear==MAXSIZE-1)
		printf("\nQueue is full\n");
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
			rear++;
		a[rear]=item;
	}
}
int dequeue()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("\nQueue is empty\n");
		return -1;
	}
	else
	{
		item=a[front];
		front++;
		return item;
	}
}
void display()
{
	printf("\nThe items in the queue are:\n");
	int i;
		for(i=front;i<=rear;i++)
		{
			printf("%d ",a[i]);
		}
}
