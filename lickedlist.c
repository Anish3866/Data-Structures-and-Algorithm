#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *next;
};
typedef struct Node node;
node *start=NULL;
node* getnode();
void createlist(int n);
void traverse();
void insert_first();
void insert_last();
void insert_after();
void insert_before();
void delete_after();
void deletenode();
void delete_first();
void delete_last();
int main()
{
	int ch,n;
	while(1)
	{
		printf("\nEnter your choice:\n");
		printf("\n1. Create a list");
		printf("\n2. Insert a node at beginning");
		printf("\n3. Insert a node at the end");
		printf("\n4. Insert after a node");
		printf("\n5. Insert before a node");
		printf("\n6. Delete a node from first");
		printf("\n7. Delete a node from last");
		printf("\n8. Delete after a node");
		printf("\n9. Delete a node");
		printf("\n10. Traverse a list");
		printf("\n11. Exit:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(start==NULL)
				{
					printf("\nEnter a number of node to create:-  ");
					scanf("%d",&n);
					createlist(n);
					traverse();
				}
				else
					printf("List is already created....");
				break;
			case 2:
				insert_first();
				break;
			case 3:
				insert_last();
				break;
			case 4:
				insert_after();
				break;
			case 5:
				insert_before();
				break;
			case 6:
				delete_first();
				break;
			case 7:
				delete_last();
				break;
			case 8:
				delete_after();
				break;
			case 9:
				deletenode();
				break;
			case 10:
				traverse();
				break;
			case 11:
				exit(0);
		}		
	}
	getch();
	return 0;
}
node* getnode()
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter the data:-  ");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	return newnode;
}
void createlist(int n)
{
	int i;
	node *newnode;
	node *temp;
	for(i=0;i<n;i++)
	{
		newnode=getnode();
		if(start==NULL)
			start=newnode;
		else
		{
			temp=start;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
}
void traverse()
{
	node *temp;
	temp=start;
	printf("Contents are:-  ");
	if(start==NULL)
		printf("List is empty");
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->info);
			temp=temp->next;
		}
	}
}
void insert_first()
{
	node *newnode;
	newnode=getnode();
	if(start==NULL)
		start=newnode;
	else
	{
		newnode->next=start;
		start=newnode;
	}
}
void insert_after()
{
	node *newnode, *ptr, *preptr;
	int n,val;
	newnode=getnode();
	printf("Enter a value after which the data is to be inserted:-  ");
	scanf("%d",&val);
	ptr=start;
	preptr=start;
	while(preptr->info!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	traverse();
}
void insert_before()
{
	node *newnode, *ptr, *preptr;
	int n,val;
	newnode=getnode();
	printf("Enter the value before which the data is to be inserted:-  ");
	scanf("%d",&val);
	ptr=start;
	preptr=start;
	while(ptr->info!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	traverse();
}
void insert_last()
{
	node *newnode, *temp;
	newnode = getnode();
	if(start==NULL)
		start=newnode;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
}
void delete_first()
{
	node *temp;
	if(start==NULL)
		printf("List is empty....");
	else
	{
		temp=start;
		start=temp->next;
		free(temp);
		printf("Node deleted.....\n");
		traverse();
	}
}
void delete_last()
{
	node *temp, *prev;
	if(start==NULL)
		printf("List is empty...");
	else
	{
		temp=start;
		prev=start;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
		printf("Node deleted...\n");
		traverse();
	}
}

void delete_after()
{
	node *newnode, *ptr, *preptr;
	int n, val;
	printf("Enter the value after which the data is to be deleted:-  ");
	scanf("%d",&val);
	ptr=start;
	preptr=start;
	while(ptr->info!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	traverse();
}

void deletenode()
{
	node *newnode, *ptr, *preptr;
	int n,val;
	printf("Enter the value to be deleted:-  ");
	scanf("%d",&val);
	ptr=start;
	preptr=start;
	while(ptr->info!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	traverse();
}

