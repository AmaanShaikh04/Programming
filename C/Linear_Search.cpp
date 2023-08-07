#include <stdio.h>
int main()
{
	int arr[100],search,c,n;
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(c=0;c<n;c++)
	scanf("%d",&arr[c]);
	printf("Enter number to search\n");
	scanf("%d",&search);
	for(c=0;c<n;c++)
	{
		if(arr[c]==search)
		printf("%d is present on the location %d\n",search,c+1);
	}
}
