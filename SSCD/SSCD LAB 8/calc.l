%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"

    void yyerror(const char *error);
%}

%%
[0-9]+(\.[0-9]+)?     {
                yylval.fval = atof(yytext);  // Convert to float for better precision
                return NUMBER;
            }

"sin"       { return SIN; }
"cos"       { return COS; }
"tan"       { return TAN; }

[a-zA-Z]+   {
                yylval.fchar = strdup(yytext);  // Allocate memory for variable names
                return NAME;
            }

[ \t]       ;  // Ignore whitespaces
\n          { return 0; }  // End of input
.           { return yytext[0]; }  // Return single character operators

%%
int yywrap() {
    return 1;
}
