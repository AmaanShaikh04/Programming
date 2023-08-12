//Write a program to count the number of non-zero values in a circular linked list.
#include <stdio.h>
#include<stdlib.h>
struct node									//creation of node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void create(void);
void display(void);
void ctr(void);								//Function Declaration

//Start of main
int main()
{
	int ch;
	while(1)
	{
		printf("1. Creation\n"
				"2. Display\n"
				"3. Number of non-zero values\n"
				"4. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);					//Accepting choice
		switch(ch)							//Calling respecting functions
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				ctr();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
//End of main

//Start of void create
//Used to create nodes
void create()
{
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&p->data);
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		p->next=head;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=p;
		p->next=head;
	}
}
//End of void create

//Start of void display
//Used to display linked list
void display()
{
	struct node* temp;
	temp=head;
	if(head==NULL)
		printf("\n List is empty");
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			printf("%d--->",temp->data);
			temp=temp->next;
		}
		printf("%d--->NULL",temp->data);
		printf("\n");
	}
}
//End of void display

//Start of void ctr
//Used to count the non-zero values in the linked list
void ctr()
{
	struct node* temp = head;
	int count=0;
	if(head!=NULL)
	{
		do
		{
			temp=temp->next;
			if(temp->data!=0)
			{
				count++;
			}
		}while(temp!=head);
	}
	printf("Count of non-zero values %d\n",count);
}
//End of void ctr
//EOF
