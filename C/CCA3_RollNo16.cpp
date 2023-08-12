#include <stdio.h>
int main()
{
	int arr[100],i,n,j=0;
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	int brr[n];
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		brr[i]=0;
		if(arr[i]>100)
		{
		brr[j]=arr[i];
		j++;
		}
	}
	printf("Array elements greater than 100 are:\n");
	for(j=0;j<n;j++)
	{
		if(brr[j]==0)
		printf("%d ",brr[j]);
	}
	return 0;
}
