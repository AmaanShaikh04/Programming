%{
    #include<stdio.h>
%}

datatype    int|float|double|char|string|bool
keyword     int|float|double|char|string|bool|for|while|do|break|case|switch|continue|default|if|static|void|struct|long|else|
identifier  [a-zA-Z_][a-zA-Z0-9_]*
D           [0-9]+
L           [A-Z|a-z]

%%

{L}({L}|{D})*               {printf("This is an Identifier %s\n",yytext);}
{keyword}                   {printf("This is a Keyword %s\n",yytext);}
{keyword}"()"               {printf("This is a System-Defined Function %s\n",yytext);}
{L}({L}|{D})*"()"           {printf("This is a User-Defined Function %s\n",yytext);}
{D}+                        {printf("This is a Number %s\n",yytext);}
{L}({L}|{D})*"["{D}+"]"     {printf("This is a User-Defined Array %s\n",yytext);}
{L}({L}|{D})*"="({L}|{D})*  {printf("This is assignment of a variable %s\n",yytext);}


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

