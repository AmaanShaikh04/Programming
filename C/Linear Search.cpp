#include <stdio.h>
int main()
{
	int arr[100],search,i,n;
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter number to search\n");
	scanf("%d",&search);
	for(i=0;i<n;i++)
	{
		if(arr[i]==search)
		printf("%d is present on the location %d\n",search,i+1);
	}
}
