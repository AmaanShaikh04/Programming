/*
	Filename: oddeven.c
	Description: To display only odd or even numbers of an array.
*/
#include "stdio.h"

int main()
{
	int a[5], ch, i;
	
	printf("\nEnter numbers for array of 5:");
	
	for(i = 0; i < 5; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\n1.Display Even numbers\t\t\t2.Display Odd numbers\nYour choice:");
	scanf("%d", &ch);
	printf("\n");
	if(ch == 1)
	{
		for(i = 0; i < 5; i ++)
		{
			if(a[i] % 2 == 0)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else if(ch == 2)
	{
		for(i = 0; i < 5; i ++)
		{
			if(a[i] % 2 != 0)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf("\n.Program aborted.\n");
		return 1;
	}
	printf("\n");
	return 0;
}
//EOF
