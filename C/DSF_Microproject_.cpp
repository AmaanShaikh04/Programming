//Bubble sort using Linked Lists
/*	*Microproject by
	*Mansi Mulik 	(16)
	*Anish Panwala 	(20)
	*Amaan Shaikh 	(28)
*/

#include <stdio.h>
#include <stdlib.h>				//including header files

struct node						//Representation a node of the singly linked list
{
    int data;
    struct node *next;
};

struct node *head,*t=NULL;		//Represent the head and tail of the singly linked list

void create_node();
void bbl_sort();
void dis();						//function declaration

//Start of void create_node
//Used for adding a new node to the list
void create_node()
{
	int data;
	scanf("%d",&data);
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(head==NULL)				//Checks if the list is empty
	{
        head=newNode;
        t=newNode;				//If list is empty, both head and tail will point to new node
    }
    else
	{
        t->next=newNode;		//newNode will be added after tail such that tail's next will point to newNode
        t=newNode;				//newNode will become new tail of the list
    }
}
//End of void create_node

//Start of voif bbl_sort
//Used for sorting nodes of the list in ascending order
void bbl_sort()
{
    struct node *current=head,*index=NULL;		//Node current will point to head
    int temp,i=1;
    if(head==NULL)
	{
        return;
    }
    else
	{
        while(current!=NULL)
		{
            index=current->next;				//Node index will point to node next to current
            while(index!=NULL)
			{
                if(current->data>index->data)	//If current node's data is greater than index's node data, swap the data between them
				{
                    temp=current->data;
                    current->data=index->data;
                    index->data=temp;
                }
                index=index->next;
            }
            current=current->next;
            printf("Pass %d:\n",i);
            dis();
            i++;
        }
    }
}
//End of void bbl_sort

//Start of void dis
//Used to display all the nodes present in the list
void dis()
{
    //Node current will point to head
    struct node *current = head;
    if(head == NULL)
	{
        printf("List is empty \n");
        return;
    }
    while(current->next!= NULL)
	{
        //Prints each node by incrementing pointer
        printf("%d,", current->data);
        current = current->next;
    }
    printf("%d\nEnd of Node\n",current->data);
}
//End of void Dis

//Start of main
int main()
{
	int n,i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
	{
		create_node();			    //Adds data to the list
	}
    
    printf("Original list: \n");	//Displaying original list
    dis();
    printf("\n");
    
    //Sorting list
    bbl_sort();
    
    printf("\n");
    printf("Sorted list: \n");		//Displaying sorted list
    dis();
    return 0;
}
//End of main
//EOF
