// accept and display matrix
#include <stdio.h>
void accept(int a[100][100],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter matrix element at position %d,%d\n",i,j);
			scanf("%d",&a[i][j]);
		}
	}	
}

void display(int a[100][100],int n,int m)
{
	int i,j;
	printf("Matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void compact(int a[100][100],int n,int m)
{
	int sp_arr[n][m],c=0;
	for(int i=0;i<n;i++)  
    {  
    	for(int j=0;j<m;j++)  
        {  
            if(a[i][j]!=0)  
            {  
                sp_arr[0][c] = i;  
                sp_arr[1][c] = j;  
                sp_arr[2][c] = a[i][j];  
                c++;  
            }  
      }  
    }  
}

/*void transpose(int a[100][100],int n,int m)
{
	int transpose[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			transpose[j][i]=a[i][j];
		}
	}
	
	printf("\nTranspose of the matrix:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d  ", transpose[i][j]);
	    	if(j==n-1)
	    	printf("\n");
		}
	}
	printf("\n\n");
}*/

int main()
{
	int n,m,arr[100][100],ch;
	printf("Enter matrix dimensions:\n");
	scanf("%d%d",&n,&m);
	while(true)
	{
		printf("Enter 1 for Accepting matrix\n");
		printf("Enter 2 for Displaying matrix\n");
		printf("Enter 3 for Compacting matrix\n");
		printf("Enter 4 for Transposing matrix\n");
		printf("Enter 5 to quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept(arr,n,m);
				break;
			case 2:
				display(arr,n,m);
				break;
			case 3:
				compact(arr,n,m);
				break;
			case 4:
				//transpose(arr,n,m);
				break;
			case 5:
				return 0;
			default:
				printf("Wrong Choice!");		
		}
	}
	return 0;
}

