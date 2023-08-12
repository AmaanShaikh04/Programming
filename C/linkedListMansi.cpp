#include<stdlib.h>
#include<stdio.h>
void Create();
void Display();
void InsertAtStart();
void InsertAtEnd();
void InsertAtPos();
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
int main() 
{
    int choice;
    while(true)
    {
        printf("SLL Operation \n");
        printf("1.Create \n");
        printf("2.Display \n");
        printf("3.Insert at the Start \n");
        printf("4.Insert at the End \n");
        printf("5.Insert at specified Position \n");
        printf("6.Exit \n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3: 
                InsertAtStart();
                break;
            case 4:
                InsertAtEnd();
                break;
            case 5:
                InsertAtPos();
                break;
            case 6:
                exit(0);
                break;                     
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
}
void Create()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
            printf("Out of Memory Space: \n");
            exit(0);
    }
    printf("Enter the data value for the node: \n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void Display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty: \n");
        return;
    }
    else
    {
        ptr=start;
        printf("The List elements are: \n");
        while(ptr!=NULL)
        {
            printf("%d, ",ptr->info );
            ptr=ptr->next ;
        }
    }
}
void InsertAtStart()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of Memory Space: \n");
        return;
    }
    printf("Enter the data value for the node: " );
    scanf("%d",&temp->info);
    temp->next =NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}
void InsertAtEnd()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of Memory Space: \n");
        return;
    }
    printf("Enter the data value for the node: ");
    scanf("%d",&temp->info );
    temp->next =NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next ;
        }
        ptr->next =temp;
    }
}
void InsertAtPos()
{
    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of Memory Space: \n");
        return;
    }
    printf("Enter the position for the new node to be inserted:");
    scanf("%d",&pos);
    pos--;
    printf("Enter the data value of the node:");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        for(i=0,ptr=start;i<pos-1;i++) 
        { 
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Position not found: \n");
                return;
            }
        }
            temp->next =ptr->next ;
            ptr->next=temp;
        }
    }
