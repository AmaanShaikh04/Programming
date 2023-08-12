#include <stdio.h>
int main()
{
	int arr[100],i,j,temp,n;
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	printf("Enter the %d elements\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<n;j++)
		{
        	if(arr[j]>arr[j+1])
			{
            	temp=arr[j];
            	arr[j]=arr[j+1];
            	arr[j+1]=temp;
	       	}
		}
	}
	printf("Sorted elements:\n");
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
	return 0;
}
