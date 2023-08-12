#include <stdio.h>
int main()
{
	int arr[100],i,j,temp,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
        	if(arr[i]>arr[j])
			{
            	temp=arr[i];
            	arr[i]=arr[j];
            	arr[j]=temp;
	       	}
		}
	}
	printf("Sorted elements\n");
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
	return 0;
}
