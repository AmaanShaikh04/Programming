//Write ‘C’ program to implement following operations on SLL - Deletion, Traversing
#include <stdio.h>
#include<stdlib.h>
void create(void);
void display(void);
void deleteatbeginning(void);
void deleteatend(void);
void deleteatpos(void);
struct node
{
	int data;
	struct node* link;
};
struct node* head=NULL;
int main()
{
	int ch,len;
	while(1)
	{
		printf("SLL operations\n");
		printf("1.Creation \n");
		printf("2.Display \n");
		printf("3.Delete at beginning\n");
		printf("4.Delete at end\n");
		printf("5.Delete at specified location\n");
		printf("6.exit\n");
		printf("enter choice \n");
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
				deleteatbeginning();
				break;
			case 4:
				deleteatend();
				break;
			case 5: 
				deleteatpos();
				break;
			case 6:
				exit(1);
				break;				
			default:
				printf("Wrong Choice\n");
		}
	}
	return 0;
}
void create()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node* p;
		p=head;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void display()
{
	struct node* temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d, ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
void deleteatbeginning()
{
	struct node* temp;
	temp=head;
	head=temp->link;
	temp->link=NULL;
	free(temp);
	printf("Node Deleted\n");
}
void deleteatend()
{
	struct node* temp;
	struct node* temp1;
	temp=head;
	while(temp->link!=NULL)
	{
		temp1=temp;
		temp=temp->link;
	}
	temp1->link=NULL;
	free(temp);
	printf("Node Deleted\n");
}
void deleteatpos()
{
	struct node* temp;
	struct node* temp1;
	int loc;
	printf("Enter the location at which you want to delete\n");
	scanf("%d", &loc);
	temp=head;
	for(int i=1;i<loc-1;i++)
	{
		temp=temp->link;
	}
	temp1=temp->link;
	temp->link=temp1->link;
	temp1->link=NULL;
	free(temp1);
	printf("Node Deleted\n");
}
