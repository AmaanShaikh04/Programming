//Write ‘C’ program to reverse a doubly Linked List.
#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head, *last = NULL;
void insert(void);
void display(void);
void rev(void);
int main()
{
	while(1)
	{
		int ch,x,pos;
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Reverse\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				rev();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Wrong Choice\n");
		}
	}
}
void insert() 
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	if(head == NULL) 
	{
		head = last = temp;
		head->prev = NULL;
		last->next = NULL;
	}
	else 
	{
		last->next = temp;
		temp->prev = last;
		last = temp;
		last->next = NULL;
	}
}
void display()
{
	struct node *temp = head;
	if(head == NULL) 
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void rev()
{
	struct node *p = head, *temp = NULL;
	while(p != NULL) 
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
	}
	temp = head;
	head = last;
	last = temp;
	display();
} 
