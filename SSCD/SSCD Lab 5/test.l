%{
    #include<stdio.h>
	int wcnt=0,lcnt=0,char_cnt=0,a=1;
%}
charac		[^\n\t]
eol			\n
word		" "

%%

{eol}		{lcnt++; wcnt++;}
{word}		{wcnt++;}
{charac}	{char_cnt++;}
.       	{printf("Invalid input %s\n",yytext);}

%%
int main()
{
	yyin=fopen("input.txt","r");
	yyout=fopen("output.txt","w");
    yylex();
	printf("\n\nNumber of Lines: %d",lcnt);
	printf("\nNumber of Words: %d",wcnt);
	printf("\nNumber of Characters: %d\n\n",char_cnt);
    return 0;
}

int yywrap()
{
    return 1;
}
