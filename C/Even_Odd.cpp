#include<stdio.h>
int main()
{
  	int array[100],i,num;
  	printf ("enter the size of array \n");
  	scanf ("%d",&num);
  	printf ("enter the elements of array \n");
  	for(i=0;i<num;i++)
  	{
    scanf ("%d",&array[i]);
  	}
  	printf("even nos in array are-\n");
  	for(i=0;i<num;i++)
  	{
	    if(array[i]%2==0)
	  	{
	  	printf("%d \t",array[i]);
		}
	}
	printf("\nodd nos in array are-\n");
	for(i=0;i<num;i++)
  	{
	    if(array[i]%2!=0)
	  	{
	  	printf("%d \t",array[i]);
		}
	}
	return 0;
}

