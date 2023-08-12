#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 20

int top=-1,stack[MAX],i;
void push();
int pop();
void eval(int post[MAX]);
int calc(int c1,int c2,char op);

void push(int val)
{	
	if(top==MAX-1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		top=top+1;
		stack[top]=val;
	}
}
 
int pop()
{
	if(top==-1)
	{
		printf("\nCannot POP, Stack is empty!!");
	}
	else
	{
		int temp = stack[top];
		top=top-1;
		return (temp);
	}
}

void eval(char post[MAX])
{
	int z,op1=0,op2=0,ans=0;
    for(i=0;post[i]!=0;i++)
    {
        if(isalpha(post[i])!=0)
        {
            printf("Enter the value of %c: ",post[i]);
            scanf("%d",&z);
            push(z);
        }
        else
        {
            op2=pop();
            op1=pop();
            ans=calc(op1,op2,post[i]);
            push(ans);
        }
    }
    printf("Evaluation is: ");
    printf("%d",stack[top]);
}

int calc(int a,int b,char op)
{
	int ans;
    switch(op)
    {
        case '+':
        {
            ans=a+b;
            break;
        }
        case'-':
        {
            ans=a-b;
            break;
        }
        case'*':
        {
            ans=a*b;
            break;
        }
        case'/':
        {
            ans=a/b;
            break;
        }
        case'^':
        	ans=pow(a,b);
        	break;
        default:;
    }
    return(ans);
}

int main()
{
    char exp[MAX];
    printf("Enter the postfix:\n");
    scanf("%s",exp);
    eval(exp);
    return 0;

}
