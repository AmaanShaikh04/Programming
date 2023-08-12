

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

void display(){
   int i;
   for(i=top;i>-1;i--){
	   printf(" %c",stack[i]);
   }
}

int icp(char ch){
if(ch=='+' || ch=='-')
return 1;
if(ch=='*' || ch=='/')
return 2;
if(ch=='^')
return 4;
if(ch=='(')
return 5;
else
return 0;
}

int isp(char ch){
if(ch=='+' || ch=='-')
return 1;
if(ch=='*' || ch=='/')
return 2;
if(ch=='^')
return 3;
else
return 0;
}

void in_post(char inexp[20],char postexp[20]){
    char tkn;
    int i=0,j=0;
    tkn=inexp[i];
    while(tkn != '\0'){
        if(isalpha(tkn)!=0){
            postexp[j]=inexp[i];
            j++;
        }
        else{
            if(tkn== '('){
                push(tkn);
            }
            else{
                if(tkn==')'){
                    while((tkn=pop())!='('){
                        postexp[j]=tkn;
                        j++;
                    }
                }
                else{
                    while(!isempty() && isp(stack[top])>= icp(tkn)){
                      postexp[j]=pop();
                      j++;
                }
                push(tkn);
            }
        }
    }
    i++;
    tkn=inexp[i];
}
while(!isempty()){
  postexp[j]=pop();
  j++;
}
    postexp[j]='\0';
    printf("Converted Postfix Expression is : %s",postexp);
}

void displayinpost(char postexp[20]){
	int i;
	for(i=top;i>-1;i--){
		   printf(" %c",postexp[i]);
	   }
}

int main(){
	//int choice;
	//char item;
	char inexp[20],postexp[20];
	printf("Enter the Infix Expression You want to Convert :");
	gets(inexp);
	in_post(inexp,postexp);
	//displayinpost(postexp);
	/*do{
		printf("\nEnter your choice : \n");
		printf("1.Push\n2.Pop\n");
		scanf("%d",&choice);
		switch(choice){
		case 1: printf("\nEnter the element you want to push : ");
        		scanf(" %c",&item);
        		push(item);
        		printf("Stack after push Operation : ");
        		display();
        		break;

		case 2: pop();
				printf("Stack after pop Operation : ");
				display();
				break;
		}
	}while(choice<=2);*/
 return 0;
}

