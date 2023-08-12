//Single and Doubly Linked list- Insertion, Deletion and Reversing
/*	*Microproject by
	*Mansi Mulik 	(16)
	*Anish Panwala 	(20)
	*Amaan Shaikh 	(28)
*/
#include <stdio.h>
#include <stdlib.h>			//including header files
struct Node					//Singly Linked List Node
{
	int Data;
	struct Node *Next;
}*Head = NULL;
struct node 				//Doubly Linked List Node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;

void singly();
void doubly();
void si();
void sd();
void sr();
void di();
void dd();
void dr();
void sDis();
void dDis();
int length();					/*function definitions*/

//start of main
int main()
{
	int ch;
	printf(	"________________________________________________________________________________________________________\n"
			"|\t\t\t\t\tWELCOME TO DSF MICROPROJECT BY:\t\t\t\t\t|\n"
			"|\t\t\t\t\t\tMANSI MULIK\t16\t\t\t\t\t|\n"
			"|\t\t\t\t\t\tANISH PANWALA\t20\t\t\t\t\t|\n"
			"|\t\t\t\t\t\tAMAAN SHAIKH\t28\t\t\t\t\t|\n"
			"|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n"
			"|\t\t\t\t\t\tMICROPROJECT TOPIC:-\t\t\t\t\t|\n"
			"|\t\t\tSingle and Doubly Linked list- Insertion, Deletion and Reversing\t\t|\n"
			"|_______________________________________________________________________________________________________|\n\n");
	while(true)
	{
		printf(	"Enter Your choice\n"
				"1. Singly Linked List\n2. Doubly Linked List\n3. Exit\n");		//choosing if we want to operate on singly or doubly linked list
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				singly();			//calling function singly();
				break;
			case 2:
				doubly();			//calling function doubly();
				break;
			case 3:
				return 0;
			default:
				printf("Wrong Choice, Please try again\n\n");
		}
	}
	return 0;
}
//EOF

//start of singly function
//function for singly linked list operations
void singly()
{
	int c;
	printf("\n1. Insert\n2. Delete\n3. Reverse\n4. Display Singly Linked List\n");		//choosing particular operation
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			si();
			break;
		case 2:
			sd();
			break;
		case 3:
			sr();
			break;
		case 4:
			sDis();
			break;
		default:
			printf("Wrong Choice, Please try again\n\n");
	}
}

//start of doubly function
//function for doubly linked list operations
void doubly()
{
	int c;
	printf("\n1. Insert\n2. Delete\n3. Reverse\n4. Display Doubly Linked List\n");		//choosing particular operation
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			di();
			break;
		case 2:
			dd();
			break;
		case 3:
			dr();
			break;
		case 4:
			dDis();
			break;
		default:
			printf("Wrong Choice, Please try again\n\n");
	}
}

void si()
{
	int choice,value,choice1,loc1,loc2,p=0;
	struct Node *newNode;
	while(p<=5)
	{
		printf("Enter the value to be insert: ");
		scanf("%d",&value);
		printf("Enter the position to insert:\n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
		scanf("%d",&choice1);
		switch(choice1)
		{
		   case 1: 	
				newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->Data = value;
				if(head == NULL)
				{
				    newNode->Next = NULL;
				    Head = newNode;
				}
				else
				{
				    newNode->Next = Head;
				    Head = newNode;
				}
				printf("Node inserted\n");
				break;
			case 2: 	
				newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->Data = value;
				newNode->Next = NULL;
				if(head == NULL)
				Head = newNode;
				else
				{
			    	struct Node *temp = Head;
			    	while(temp->Next != NULL)
					temp = temp->Next;
			    	temp->Next = newNode;
				}
				printf("Node inserted\n");
				break;
			case 3:      
				printf("Enter the two values where you want to insert: ");
				scanf("%d%d",&loc1,&loc2);
				newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->Data = value;
				if(head == NULL)
				{
			    	newNode->Next = NULL;
			    	Head = newNode;
				}
				else
				{
			    	struct Node *temp = Head;
			    	while(temp->Data != loc1 && temp->Data != loc2)
					temp = temp->Next;
			    	newNode->Next = temp->Next;
			    	temp->Next = newNode;
				}
				printf("Node inserted\n");
				break;
			default: 	
				printf("\nWrong Input");
		}
		p++;
	}
}

void sd()
{
	int ch,len;
	struct Node* temp;
	struct Node* temp1;
	printf("Enter the position to Delete:\n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			temp=Head;
			Head=temp->Next;
			temp->Next=NULL;
			free(temp);
			printf("Node Deleted\n");
			break;
		case 2:

			temp1=Head;
			while(temp1->Next!=NULL)
			{
				temp1=temp;
				temp=temp->Next;
			}
			temp1->Next=NULL;
			free(temp);
			printf("Node Deleted\n");
			break;
		case 3: 
			int loc,i;
			printf("Enter the location at which you want to delete\n");
			scanf("%d", &loc);
			temp=Head;
			for(i=1;i<loc-1;i++)
			{
				temp=temp->Next;
			}
			temp1=temp->Next;
			temp1->Next=temp->Next;
			temp->Next=NULL;
			free(temp);
			printf("Node Deleted\n");
			break;		
		default:
			printf("Wrong Choice\n");
	}
}

void sr()
{
	struct Node* Head = NULL;
	push(&Head, 20);
	push(&Head, 4);
	push(&Head, 15);
	push(&Head, 85);
	printf("Given linked list\n");
	printList(Head);
	struct Node* prev=NULL;
	struct Node* curr=*head_ref;
	struct Node* Next=NULL;
	while(current!=NULL)
	{
		Next=curr->Next;
		curr->Next=prev;
		prev=curr;
		curr=Next;
	}
	*head_ref=prev;
	printf("\nReversed Linked list \n");
	struct Node* temp = Head;
	while(temp!=NULL)
	{
		printf("%d ",temp->Data);
		temp=temp->Next;
	}
}

void sDis()
{
   if(Head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
	    struct Node *temp = Head;
	    printf("\nList elements are - \n");
	    while(temp->Next != NULL)
	    {
		printf("%d --->",temp->Data);
		temp = temp->Next;
	    }
	    printf("%d --->NULL\nEnd of Node\n\n",temp->Data);
   }
}

void di()
{
	int value,choice;
	struct node *temp, *ptr;
	printf("Enter the value to be insert: ");
	scanf("%d",&value);
	printf("Enter the position to insert:\n1. At Beginning\n2. A Particular Position\nEnter your choice: ");
	scanf("%d",&choice); 
	switch(choice)
	{
		case 1:
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=value;
			if(head==NULL)
			{
				head=temp;
				head->next=NULL;
			}
			head->prev=temp;
			temp->next=head;
			temp->prev=NULL;
			head=temp;
			printf("Node Inserted\n");
			break;
		case 2:
			int v;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=value;
			printf("Enter the number where you want to insert number\n"); 
			scanf("%d",&v);
			ptr=head;
			while(ptr->data!=v)
			{
				ptr=ptr->next;
			}
			temp->next=ptr;
			temp->prev=ptr->prev;
			ptr->prev->next=temp;
			ptr->prev=temp;
			printf("Node Inserted\n");
			break;
		default:
			printf("Wrong Choice");
	}
}

void dd()
{
	int ch;
	struct node *temp, *p;
	printf("Enter the position to Delete:\n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
			break;
		case 2:
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->prev->next=NULL;
			free(temp);
			break;
		case 3:
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
			break;
		
	}
}

void dr()
{
	struct node *head, *last = NULL;
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
}

void dDis()
{
	struct node* temp;
	temp=head;
	printf("\nList elements are - \n");
	if(temp==NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(temp->next!=NULL)
		{
			printf("%d --->",temp->data);
			temp=temp->next;
		}
		printf("%d --->NULL\nEnd of Node\n\n",temp->data);
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
