//

#include<stdio.h>
#include<ctype.h>
#define maxsize 20
char stack[20];
int top=-1;

int isfull(){
	if(top==(maxsize-1)){
		return 1;
	}
	else
		return 0;
}

int isempty(){
	if(top==-1){
		return 1;
	}
	else
		return 0;
}

void push(char item){
	if(!isfull()){
		top=top+1;
		stack[top]=item;
	}
	else{
		printf("Stack is full!\n");
	}
}

char pop(){
	char temp;
	if(!isempty()){
		temp=stack[top];
		top=top-1;
		return(temp);
	}
	else{
		printf("Stack is Empty!\n");
	}
}

int calc(int c1,int c2,char op)
{
    int ans;
    switch(op)
    {
        case '+':
        {
            ans=c1+c2;
        }
        break;
        case '-':
        {
            ans=c1-c2;
        }
        break;
        case '*':
        {
            ans=c1*c2;
        }
        break;
        case '/':
        {
            ans=c1/c2;
        }
        break;
    }
    return ans;
}

void eval(char post[20])
{
    int z;
    int op1,op2;
    int ans;
    for(int i=0;post[i]!='\0';i++)
    {
        if(isalpha(post[i])!=0)
        {
            printf("Enter the value of %c:",post[i]);
            scanf("%d",&z);
            push(z);
        }
        else
        {
            op1=pop();
            op2=pop();
            ans=calc(op2,op1,post[i]);
            push(ans);
        }
    }
    printf("Evaluation is :");
    printf("%d\n",stack[top]);
}

void main ()
{
  char post[30];
  printf ("Enter the postfix string :");
  gets(post);
  eval(post);

}
