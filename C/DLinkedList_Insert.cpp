//Write ‘C’ program to implement following operations on DLL-Creation, Insertion. 
#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insertstart();
void insertpos();
struct node 
{
	struct node *prev;
	int data;
	struct node *link;
};
struct node *head=NULL;
int main()
{
	int ch;
	while(true)
	{
		printf("1.Create\n");
		printf("2.Display\n");
		printf("3.Insert at beginning\n");
		printf("4.Insert at a position\n");
		printf("5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch); 
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insertstart();
				break;
			case 4:
				insertpos();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Wrong Choice");
		}
	}
}
void create()
{
	struct node *temp,*ptr;
	int n;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&n);
	if(head==NULL)
	{
		temp->prev=NULL;
		temp->data=n;
		temp->link=NULL;
		head=temp;
	}
	else
	{ 
		ptr=head;
		temp->data=n;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
		temp->prev=ptr;
		temp->link=NULL;
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	printf("Head");
	while(ptr!=NULL)
	{
		printf("->%d",ptr->data);
		ptr=ptr->link;
	}
	printf("->NULL\n");
}
void insertstart() 
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
		head=temp;
		head->link=NULL;
	}
	head->prev=temp;
	temp->link=head;
	temp->prev=NULL;
	head=temp;
	printf("Node Inserted\n");
}
void insertpos()
{
	struct node *temp,*ptr;
	int v;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&temp->data);
	printf("Enter the number where you want to insert number\n"); 
	scanf("%d",&v);
	ptr=head;
	while(ptr->data!=v)
	{
		ptr=ptr->link;
	}
	temp->link=ptr;
	temp->prev=ptr->prev;
	ptr->prev->link=temp;
	ptr->prev=temp;
	printf("Node Inserted\n");
}
