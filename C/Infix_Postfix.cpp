#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char stack[MAX];
int top = -1;
int isEmpty(){
    return top == -1;
}
int isFull(){
    return top == MAX - 1;
}
char Top(){
    return stack[top];
}
char pop()
{
    if(isEmpty())
        return -1;
    char ch = stack[top];
    top--;
    return(ch);
}

void push(char oper){
    if(isFull())
        printf("Stack Full!");
   
    else{
        top++;
        stack[top] = oper;
    }
}

int OperandCheck(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int prec(char ch) 
{ 
    switch (ch) 
    { 
	    case '+': 
	    case '-': 
	        return 1; 
	    case '*': 
	    case '/': 
	        return 2; 
	    case '^': 
	    	return 3; 
    } 
    return -1; 
} 

int Inf_Pos(char* exp) 
{ 
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i) 
    { 
        if (OperandCheck(exp[i])) 
            exp[++j] = exp[i];  
        else if (exp[i] == '(') 
            push(exp[i]); 
        else if (exp[i] == ')') 
        { 
            while (!isEmpty() && Top() != '(') 
                exp[++j] = pop(); 
            if (!isEmpty() && Top() != '(') 
                return -1;              
            else
                pop(); 
        }	
        else
        { 
            while (!isEmpty() && prec(exp[i]) <= prec(Top())) 
                exp[++j] = pop(); 
            push(exp[i]); 
        }
    }
    printf("Postfix Expression: ");
    while (!isEmpty()) 
        exp[++j] = pop(); 

    exp[++j] = '\0'; 
    printf( "%s", exp); 
} 

int main()
{
	char exp[100]; 
	printf("Enter Infix Expression\n");
	scanf("%s",exp);
    Inf_Pos(exp); 
    return 0; 
}
