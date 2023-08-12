//Write ‘C’ program to implement following operations on CLL-Creation, Insertion, Deletion, Display.
#include <stdio.h>
#include <stdlib.h>
struct node										//creation of Node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void create(void);
void display(void);
void insert_beginning(void);
void insert_pos(void);
void delete_beginning(void);
void delete_end(void);
void delete_pos(void);							//Function Declaration

//Start of Main
int main()
{
	int ch;
	while(1)
	{
		printf(	"1. Creation\n"
				"2. Insert at Beginning\n"
				"3. Insert at specific position\n"
				"4. Display\n"
				"5. Delete at begenning\n"
				"6. Delete at end\n"
				"7. Delete at specific position\n"
				"8. Exit\n");
		printf("Enter your choice \n");	
		scanf("%d",&ch);						//Accepting the choice
		switch(ch)								//Calling the respective functions
		{
			case 1:
				create();
				break;
			case 2:
				insert_beginning();
				break;
			case 3:
				insert_pos();
				break;
			case 4:
				display();
				break;
			case 5:
				delete_beginning();
				break;
			case 6:
				delete_end();
				break;
			case 7:
				delete_pos();
				break;		
			case 8: 
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
//End of Main

//Start of void create
//Used for creating nodes
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
//Used for displaying the linked list
void display()
{
	struct node* temp;
	temp=head;
	if(head==NULL)
	printf("\n List is empty");
	else
	{
		temp = head;
		while(temp->next!=head)
		{
			printf("%d--->", temp->data);
			temp = temp->next;
		}
		printf("%d--->NULL", temp->data);
		printf("\n");
	}
}
//End of void display

//Start of void insert_beginning
//Used for inserting nodes in beginning
void insert_beginning()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
	}
	else
	{
		struct node* p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		temp->next=head;
		head=temp;
		p->next=head;
	}
}
//End of void insert_beginning

//Start of void insert_pos
//Used for inserting node at a particular position
void insert_pos()
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	int pos,i;
	printf("Enter position\n");
	scanf("%d",&pos);
	printf("Enter data\n");
	scanf("%d",&temp->data);
	p=head;
	for(i=1;i<pos-1;i++)
	{
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
}
//End of void insert_pos

//Start of void delete_beginning
//Used to delete the node in the beginning
void delete_beginning()
{
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node* temp,*temp1;
		temp=head;
		temp1=head;
		if(temp->next==head)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			while(temp->next!=head)
			{
			temp=temp->next;
			}
			head=temp1->next;
			temp->next=head;
			free(temp1);
		}
	}
}
//End of void delete_beginning

//Start of void delete_end
//Used to delete node in the end
void delete_end()
{
	struct node *temp,*temp1=head;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else if(temp1->next==head)
	{
		temp1 = NULL;
		free(temp1);
	}
	else
	{
		temp = head;
		while(temp->next!=head)
		{ 
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=temp->next;
		free(temp);
	}
}
//End of void delete_end
//Used to delete node at a particular position
void delete_pos()
{
	struct node* temp;
	struct node* temp1=head;
	int pos;
	printf("Enter the location at which you want to delete");
	scanf("%d", &pos);
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		temp=head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next=head;
		free(temp1);
	}
}
//End of void delete_end
//EOF
