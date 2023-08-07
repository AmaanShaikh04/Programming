/*
	Filename: largest_smallest.c
	Description: To find Largest number or smallest number
*/

#include "stdio.h"

int largest();
int smallest();

int main()
{
	int ch;
	
	printf("\n1. Display Largest number\t\t\t2. Display Smallest number\nYour Choice:");
	
	scanf("%d", &ch);
	
	if(ch == 1)
	{
		largest();
	}
	else if(ch == 2)
	{
		smallest();
	}
	else
	{
		printf("\n\n\n--program error--\n\n");
		return 1;
	}	
	
	return 0;
}

// Function name: largest();
// Desc: To find largest number
// No parameters passed

int largest()
{
	int a[5], largest_num = 0;
	int i;
	
	printf("\nEnter the elements of the array: ");
	for(i = 0; i < 5; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < 5; i ++)
	{
		if(largest_num < a[i])
		{
			largest_num = a[i];
		}
	}
	
	printf("\nThe Largest number is %d.\n", largest_num);
}

// Function name: smallest();
// Desc: To find smallest number
// No parameters passed
int smallest()
{
	int a[5], smallest_num = 0;
	int i;
	
	printf("\nEnter the elements of the array: ");
	for(i = 0; i < 5; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < 5; i ++)
	{
		if(smallest_num > a[i])
		{
			smallest_num = a[i];
		}
	}
	printf("\nThe Smallest number is %d.\n", smallest_num);
}
//EOF
