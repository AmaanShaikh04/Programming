/*
	File name: insndel.c
	Description: To insert an element or delete one in an array
	Author: Hrushikesh Pandit
*/

#include "stdio.h"

int insert(int arr[50], int siz);
int display(int ar[50], int sz);
int del(int ary[50], int size);

int main()
{
	int i, a[50], choice, arsiz;
	
	printf("Enter the size of the array:");
	scanf("%d", &arsiz);
	
	printf("\nEnter the elements:");
	
	for(i = 0; i < arsiz; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\n1.Insert\t\t\t2.Delete\nYour Choice:");
	scanf("%d", &choice);
	
	if(choice == 1)
	{
		insert(a , arsiz);
	}
	else if(choice == 2)
	{
		del(a , arsiz);
	}
	else
	{
		printf("program aborted.\nerror 21: user cannot follow the rules.\n");
		return 1;
	}
	
	printf("\n");
	return 0;
}

// Function name: insert();
// Description: To insert an element in the array
// @param (in) Array elements
// @param (in) Array size
int insert(int arr[50], int siz)
{
	int tmp, tmp1, numbr, i, pos;    
    
        printf("\nEnter the position:");
        scanf("%d", &pos);
            
        if(pos > siz)
	{
		printf("\n\n\n\nerror 4.\n");
		return 1;
	}
            
        printf("\nEnter the number which has to be inserted ->");
        scanf("%d", &numbr);
        printf("\nOld Array:");
        display(arr , siz);
  	      tmp1 = arr[pos];
              arr[pos] = numbr;
              ++pos;
              siz++;
        for( i = pos ; i < siz; i++)
        {
              tmp = arr[i];
              arr[i] = tmp1;
              tmp1 = tmp;
        }
        
        printf("\nNew array:");
        display(arr , siz);
             
        return 0;
}

//Function name: display();
//Function: to display an array;
// @param (in) Array elements
// @param (in) Array size
int display(int ar[50], int sz)
{
	int i;
		
	for(i = 0; i < sz; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
	return 0;
}

// Function name: del();
// Description: To delete an element of an array.
// @param (in) Array elements
// @param (in) Array size
int del(int ary[50], int size)
{
	int i;
	int temp, pos;
	
	printf("\nEnter the position of the element you want to delete:");
	scanf("%d", &pos);
	
	printf("\nOld array:");
	display(ary , size);
	
	if(pos > size)
	{
		printf("\n\n\n\nerror 5.\n");
		return 1;
	}
	else
	{
		ary[pos] = 0;
	
		if(ary[pos] = size)
		{
			goto jump;
		}
		else
		{	for(i = pos; i < size; i ++)
			{
				temp = ary[i];
				ary[i-1] = temp;
			}	
			goto jump;
		}
	}
jump:	
	printf("\nNew Array:");
	display(ary , size-1);
	return 0;
}
//EOF
