//Write ‘C’ program to implement following operations on DLL-Deletion, Traversing.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void insert(void);
void deleteatend(void);
void display(void);
void deleteatbeginning(void);
void deleteatpos(void);
int length(void);
int main()
{
	while(1)
	{
	int ch;
	printf("1.Insert \n");
	printf("2.Delete at beginning\n");
	printf("3.Delete at end \n");
	printf("4.Delete at position\n");
	printf("5.Display\n");
	printf("6.Exit \n");
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		 	insert();
		 	break;
		case 2:
		 	deleteatbeginning();
		 	break;
		case 3:
		 	deleteatend();
		 	break;
		case 4:
		 	deleteatpos();
			break;
		case 5:
		 	display();
		 	break;
		case 6:
		 	exit(1);
			break;
		}
	}
}
void insert()
{
 	struct node* temp;
 	temp=(struct node*)malloc(sizeof(struct node));
 	printf("Enter data\n");
 	scanf("%d",&temp->data);
 	temp->prev=NULL;
 	temp->next=NULL;
 	if(head==NULL)
 	{
 		head=temp;
	}
 	else
 	{
	 	struct node* p;
	 	p=head;
	 	while(p->next!=NULL)
	 	{
	 		p=p->next;
	 	}
	 	p->next=temp;
	 	temp->prev=p;
 	}
}
void display()
{
	struct node* temp;
	temp=head;
	if(temp==NULL)
	{
	 	printf("List empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d, ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void deleteatend()
{
 	struct node* temp;
 	temp=head;
 	while(temp->next!=NULL)
 	{
 	temp=temp->next;
 	}
 	temp->prev->next=NULL;
 	free(temp);
}
void deleteatbeginning()
{
 	struct node* temp;
 	temp=head;
 	head=head->next;
 	head->prev=NULL;
 	free(temp);
}
void deleteatpos()
{
 	struct node* temp,*p;
 	temp=head;
 	int i,pos,len;
 	printf("Enter the position\n");
 	scanf("%d",&pos);
 	len=length();
 	if(pos>len)
 	{
 	printf("Invalid location\n");
 	}
 	else
 	{
 	for(i=1;i<pos-1;i++)
 	{
 	temp=temp->next;
 	}
 	p=temp->next;
 	temp->next=p->next;
 	p->next->prev=temp;
 	free(p);
 	}
}
int length()
{
 	int count=0;
	struct node* temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		count++;
 		temp=temp->next;
 	}
 	return count;
}
