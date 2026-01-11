#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int info;
	struct Node *next;
};
typedef struct Node node;

node *front=NULL;
node *rear=NULL;

void enqueue(int num);
void dequeue();
void display();

int main()
{
	int ch,num;
	while(1)
	{
		printf("\nEnter your choice:\n");
		printf("\n1. Enqueue operation");
		printf("\n2. Dequeue operation");
		printf("\n3. Display");
		printf("\n4. Exit\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data to insert into the queue...\t");
				scanf("%d",&num);
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	getch();
	return 0;
}

void enqueue(int num)
{
	node *newnode;
	newnode=(struct Node*)malloc(sizeof(node));
	newnode->info=num;
	newnode->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	printf("%d is inserted into the queue",num);
}

void dequeue()
{
	node *temp;
	if(front==NULL)
		printf("Queue is empty....");
	else
	{
		temp=front;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		printf("Deleted element %d",temp->info);
		free(temp);
	}
}

void display()
{
	node *temp;
	if(front==NULL)
		printf("Queue is empty");
	else
	{
		temp=front;
		printf("Contents are:\n");
		while(temp!=NULL)
		{
			printf("%d-->",temp->info);
			temp=temp->next;
		}
	}
}

