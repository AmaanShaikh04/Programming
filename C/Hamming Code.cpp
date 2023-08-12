//Hamming Code
//Done by: Amaan Shaikh SY-CSE Panel A
#include <math.h>
#include <stdio.h>

int in[32];
int co[32];

int ham(int pos, int c)
{
	int ctr = 0, i, j;
	i = pos - 1;
	while (i < c) 
	{
		for (j = i; j < i + pos; j++) 
		{
			if (co[j] == 1)
				ctr++;
		}
		i = i + 2 * pos;
	}
	if (ctr % 2 == 0)
		return 0;
	else
		return 1;
}

void solve(int in[], int n)
{
	int i, p_n = 0, c, j, k;
	i = 0;
	while (n > (int)pow(2, i) - (i + 1))
	{
		p_n++;
		i++;
	}
	c = p_n + n;
	j = k = 0;
	for (i = 0; i < c; i++) 
	{
		if (i == ((int)pow(2, k) - 1)) 
		{
			co[i] = 0;
			k++;
		}
		else {
			co[i] = in[j];
			j++;
		}
	}
	for (i = 0; i < p_n; i++) 
	{
		int pos = (int)pow(2, i);
		int value = ham(pos, c);
		co[pos - 1] = value;
	}
	printf("The Code is: ");
	for (i = 0; i < c; i++) 
	{
		printf("%d", co[i]);
	}
}

int main()
{
	printf("Enter the number of bits\n");
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("Enter value %d\n",i);
		scanf("%d",&in[i]);
	}	
	printf("Done by Amaan Shaikh\n");
	solve(in, N);
	return 0;
}

