/*Write ‘C’ program to implement following operations on SLL-Creation, Insertion.*/
#include<stdio.h>
#include<stdlib.h>
void insertAtBeginning(int);
void insertAtEnd(int);
void insertBetween(int,int,int);
void display();
struct Node
{
	int data;
	struct Node *next;
}*head = NULL;
int main()
{
   int choice,value,choice1,loc1,loc2;
   while(true)
   {
	   options: 
	   printf("1. Insert\n2. Display\nEnter your choice: ");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	    	case 1: 	
			printf("Enter the value to be insert: ");
			scanf("%d",&value);
			while(true)
			{
			printf("Enter the position to insert: \n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
			scanf("%d",&choice1);
			switch(choice1)
			{
			   case 1: 	
					insertAtBeginning(value);
					break;
			   case 2: 	
					insertAtEnd(value);
					break;
			   case 3:      
					printf("Enter the two values where you want to insert: ");
					scanf("%d%d",&loc1,&loc2);
					insertBetween(value,loc1,loc2);
					break;
			   default: 	
					printf("\nWrong Input");
					goto options;
			}
			goto options_end;
			}
			options_end:
			break;
	    	case 2: 	
				display();
				break;
			default:
				printf("\nWrong Choice");	
		}
   }
   return 0;
}
void insertAtBeginning(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
    	newNode->next = NULL;
    	head = newNode;
   }
   else
   {
    	newNode->next = head;
    	head = newNode;
   }
   	printf("Node inserted\n");
}
void insertAtEnd(int value)
{
   	struct Node *newNode;
   	newNode = (struct Node*)malloc(sizeof(struct Node));
   	newNode->data = value;
   	newNode->next = NULL;
   	if(head == NULL)
	head = newNode;
	else
	{
    	struct Node *temp = head;
    	while(temp->next != NULL)
		temp = temp->next;
    	temp->next = newNode;
	}
	printf("Node inserted\n");
}
void insertBetween(int value, int loc1, int loc2)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
    	newNode->next = NULL;
    	head = newNode;
   }
   else
   {
    	struct Node *temp = head;
    	while(temp->data != loc1 && temp->data != loc2)
		temp = temp->next;
    	newNode->next = temp->next;
    	temp->next = newNode;
   }
   printf("Node inserted\n");
}
void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
	    struct Node *temp = head;
	    printf("\nList elements are - \n");
	    while(temp->next != NULL)
	    {
		printf("%d --->",temp->data);
		temp = temp->next;
	    }
	    printf("%d --->NULL\nEnd of Node\n\n",temp->data);
   }
}
