#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void create(struct node *head)
{
	struct node *temp = head;
	struct node *curr;
	char ch;
	do
	{
		curr = (struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&curr->data);
		curr->next = NULL;
		temp->next = curr;
		temp = curr;
		printf("Press y to continue\n");
		char temp;
		scanf("%c",&temp);
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');
}

void display(struct node *head)
{
	struct node *temp;
	temp = head->next;
	if(head->next == NULL)
	{
    	printf("\nList is Empty\n");
	}
	else
	{
	    printf("\nList elements are - \n");
	    while(temp != NULL)
	    {
			printf("%d ---> ",temp->data);
			temp = temp->next;
	    }
	    //printf("%d ---> NULL\nEnd of Node\n\n",temp->data);
	}
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	int ch;
	while(true)
	{
		printf("Enter 1 for Creating Linked List node\n");
		printf("Enter 2 for Displaying Linked List\n");
		printf("Enter 3 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				return 0;
			default:
				printf("Wrong Choice\n");
				return 0;
		}
	}
}
