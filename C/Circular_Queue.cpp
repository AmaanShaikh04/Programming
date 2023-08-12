#include <stdio.h>
int front=-1, rear=-1,arr[5];
void ins()
{
 int x;
 printf("Enter value to be inserted:\n");
 scanf("%d",&x);
 if ((front == 0 && rear == 4) ||
(front==rear+1))
 {
 printf("Queue is Full\n");
 }
 else if (front == -1)
 {
 front = rear = 0;
 arr[rear] = x;
 }
 else if (rear == 4 && front != 0)
 {
 rear = 0;
 arr[rear] = x;
 } else
 {
 rear++;
 arr[rear] = x;
 }
}
int del()
{
 if ((front == -1))
 {
 printf("Queue is empty\n");
 }
 else if(front == rear)
 {
 front = -1;
 rear = -1;
 }
 else if(front == 4)
 {
 front = 0;
 }else
 {
 front = front + 1;
 }
}
void display()
{
 if (front == -1)
 {
 printf("Queue is Empty\n");
 return;
 }
printf("Elements in Circular Queue are: ");
 if (rear >= front)
 {
 for (int i = front; i <= rear; i++)
 printf("%d ",arr[i]);
 } else
 {
 for (int i = front; i < 5; i++)
 printf("%d ", arr[i]);
 for (int i = 0; i <= rear; i++)
 printf("%d ", arr[i]);
 }
}
int main()
{
 int ch1, ch2;
 do
 {
 printf("Enter your choice\n");
printf("\n1.Display\n2.Insert\n3.Delete\n4.Exit\n");
 scanf("%d", &ch1);
 switch (ch1)
 {
 case 1:
 display();
 break;
 case 2:
 ins();
 break;
 case 3:
 del();
 break;
 case 4:
 return 0;
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (ch1 != 5);
 return 0;
}

