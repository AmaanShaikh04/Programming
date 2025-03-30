%{
#include<stdio.h>
extern int yylex();
extern int yywrap();
extern int yyparse();
extern int yyerror(char *str);
%}

%token WH IF DO FOR OP CP OCB CCB CMP SC ASG ID NUM COMMA OPR

%%
start: sif ;
sif: IF OP cmpn CP stmt     {printf("Valid Statement If\n");};
cmpn: ID CMP ID | ID CMP NUM;
stmt: ID ASG OPR ID SC; 
%%
int yyerror(char *str)
{
    printf("%s",str);
}
int main()
{
    yyparse();
    return 1;
}

