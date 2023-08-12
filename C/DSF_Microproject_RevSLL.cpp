// Iterative C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
/* Link list node */
struct Node 
{
	int Data;
	struct Node* Next;
};

/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
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
}

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	new_node->Data=new_data;
	new_node->Next=(*head_ref);
	(*head_ref)=new_node;
}

/* Function to print linked list */
void printList(struct Node* Head)
{
	struct Node* temp = Head;
	while(temp!=NULL)
	{
		printf("%d ",temp->Data);
		temp=temp->Next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	struct Node* Head = NULL;
	push(&Head, 20);
	push(&Head, 4);
	push(&Head, 15);
	push(&Head, 85);
	printf("Given linked list\n");
	printList(Head);
	reverse(&Head);
	printf("\nReversed Linked list \n");
	printList(Head);
}

