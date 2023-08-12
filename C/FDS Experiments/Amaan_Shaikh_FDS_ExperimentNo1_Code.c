//Program Matric Operations

#include <stdio.h>
#include <stdlib.h>

void accept(int X[10][10], int a, int b)
{
	int i, j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("Enter element [%d%d] :\t", i, j);
			scanf("%d", &X[i][j]);
		}
	}
}

void display(int Z[10][10], int a, int b)
{
	int i, j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf(" %d \t", Z[i][j]);
		}
		printf("\n");
	}
}

void add(int X[10][10], int Y[10][10], int Z[10][10], int m, int n)
{
	int i, j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Z[i][j] = X[i][j] + Y[i][j];
}

void subtract(int X[10][10], int Y[10][10], int Z[10][10], int m, int n)
{
	int i, j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Z[i][j] = X[i][j] - Y[i][j];
}

void multiply (int X[10][10], int Y[10][10], int Z[10][10], int m, int n)
{
	int i, j, k;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			Z[i][j] = 0;
			for(k = 0; k < n; k++)
			Z[i][j] += X[i][k] * Y[k][j];
		}
	}
}

void transpose (int Y[10][10], int Z[10][10], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			Z[i][j] = Y[j][i];
}

int main()
{
	int m, n, choice, A[10][10], B[10][10], C[10][10];

	printf("Enter the number of Rows :");
	scanf("%d", &m);
	printf("Enter the number of Columns :");
	scanf("%d", &n);
	printf("\nEnter Matrix A:\n");
	accept(A, m, n);
	printf("\n Enter Matrix B:\n");
	accept(B, m, n);

	do
	{
		printf("\nChoose the matrix operation,\n");
		printf("----------------------------\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Transpose\n");
		printf("5. Exit\n");
		printf("----------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				add(A, B, C, m, n);
				printf("\nSum of matrix: \n");
				display (C, m, n);
				break;
			case 2:
				subtract(A, B, C, m, n);
				printf("\nSubtraction of matrix: \n");
				display (C, m, n);
				break;
			case 3:
				multiply (A, B, C, m, n);
				printf("\nMultiplication of matrix: \n");
				display (C, m, n);
				break;
			case 4:
				printf("\nTranspose of the first matrix: \n");
				transpose (A, C, m, n);
				display (C, m, n);
				printf("\nTranspose of the second matrix: \n");
				transpose (B, C, m, n);
				display (C, m, n);
				break;
			case 5:
				printf("Thank You.\n");
				exit (0);
			default:
				printf("Invalid input.\n");
				printf("Please enter the correct input.\n");
		}
	}while(1);
return 0;
}
