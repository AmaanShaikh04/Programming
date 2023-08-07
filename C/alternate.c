/*
	Filename: alternate.c
	Description: To display alternate elements
*/
#include "stdio.h"

int main()
{
	int a[5], i;
	
	printf("Enter 5 elements of array:");
	
	for(i = 0; i < 5; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\nAlternate->\n");
	
	for(i = 0; i < 5; i += 2)
	{
		printf("%d", a[i]);
	}
	
	printf("\n");
	
	return 0;
}
//EOF
