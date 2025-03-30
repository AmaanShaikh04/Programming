%{
    #include<stdio.h>
%}

verb        is|am|are
L [A-Z|a-z]
D [0-9]

%%

{verb}  	{printf("This is a verb %s\n",yytext);}
{L}+    	{printf("this is a letter %s\n",yytext);}
{D}+     	{printf("this is a digit %s\n",yytext);
			int a=atoi(yytext);
			if(a%2==0)
				printf("This is a Even Number %s\n",yytext);
				
			else
				printf("This is a Odd Number %s\n",yytext);
			}
.       	{printf("Invalid input %s\n",yytext);}

%%
int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
