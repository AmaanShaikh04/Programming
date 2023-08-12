#include <stdio.h>

int arr[5],front=-1,rear=-1;

int dis()
{
    int i;
    printf("The queue is\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int insert()
{
    int x;
    printf("Enter value to be inserted\n");
    scanf("%d", &x);
    if(rear == 4)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front=0;
        rear=rear+1;
        arr[rear]=x;
    } else
    {
        rear=rear+1;
        arr[rear]=x;
    }
}

int del()
{
    int x;
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
    }else
    {
        x=arr[front];
        front=front+1;
    }
}

int main()
{
    int a,b;
    do
    {
		printf("1.Display\n2.Insert\n3.Delete\n");
        printf("Enter your choice: ");
		scanf("%d", &a);
        switch(a)
        {
        case 1:
            dis();
            break;
        case 2:
            insert();
            break;
        case 3:
            del();
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("\nDo you want to continue?\n");
        printf("1.Yes\n2.No\n");
        printf("Enter your choice: ");
        scanf("%d", &b);
    } while (b==1);
	return 0;
}
