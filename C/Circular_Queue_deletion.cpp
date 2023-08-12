//Circular queue deletion 
//including header files
#include<stdio.h>
# define N 5	//defining value if N to 5

void insert();	//function used for inserting
void deletion();//function used for deleting
void display();	//function used for displaying
int queue[N];	//globally defined queue

//Globally defined front and rear used for circular queue
int front=-1;
int rear=-1;

//function name: void insert()
//description: Used for inserting the element in the queue
//return type: void
void insert()
{
    int x;
    scanf("%d",&x);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front)	//circular queue overflow condition
    {
        printf("\t\tOver Flow\t\t\n");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
//end of void insert()

//function name: void deletion()
//description: Used for deleting the element in the queue
//return type: void
void deletion()
{
    if(front==-1 && rear==-1)	//circular queue underflow condition
    {
        printf("\t\tUnder Flow\t\t\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("Deleted element: %d\n",queue[front]);	//prints the element deleted
        front=(front+1)%N;
    }
}
//end of void deletion()

//function name: void display()
//description: Used for displaying the queue
//return type: void
void display()
{
    int i=front;
    if(front==-1 && rear==-1)	//checks if the queue is empty or not
    {
        printf("Queue is Empty");
    }
    else
    {
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[i]);
    }
}
//end of void display()

//function name: int main()
//description: Start of the program
//return type: int
int main()
{
	printf("Enter 5 elements:\n");
    for(int i=0;i<N;i++)
    {
    	insert();	//5 numbers are inserted in the queue
	}
    deletion();
    deletion();		//2 elements are deleted from the queue
    
    printf("Enter 2 elements:\n");
    insert();
    insert();		//2 elements are inserted in the queue
    
    printf("Resultant queue:\n");
    display();		//queue is being displayed
    return 0;
}
