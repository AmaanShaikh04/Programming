/*
	Filename:LinearSearch.C
	Description: To do Linear Search
	Author: Hrushikesh Pandit
	Contributions: logictech31
*/
#include "stdio.h"

int main()
{
	int a[100], i, j, loc[100], num, ele, lim;
	
	lim = 0;
	
	printf("Enter the number of elements:");
	scanf("%d", &ele);
	
	printf("\nEnter the elements:");
	for(i = 0; i < ele; i ++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\nEnter the number which has to be searched:");
	scanf("%d", &num);
	
	for(i = 0, j = 0; i < ele; i ++)
	{
		if(num == a[i])
		{
			loc[j] = i;
			j++;
			lim++;
		}
	}
	printf("\nPosition(s) found:");
	
	for(i = 0; i < lim; i ++)
	{
		printf("%d ", loc[i]);
	}
	printf(".\n");
	
	return 0;
}
//EOF
