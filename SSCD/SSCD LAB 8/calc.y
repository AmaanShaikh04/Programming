%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    void yyerror(const char *error);
    int yyparse();
    int yylex();
%}

%union {
    char *fchar;
    double fval;
}

%token SIN COS TAN
%token<fchar> NAME
%token<fval> NUMBER
%type<fval> exp

%left '+' '-'
%left '*' '/'
%left '^'

%%
stmt:   NAME '=' exp  { printf("%s = %.2f\n", $1, $3); free($1); }
    |   exp           { printf("Result: %.2f\n", $1); }

exp:    exp '+' exp   { $$ = $1 + $3; }
    |   exp '-' exp   { $$ = $1 - $3; }
    |   exp '*' exp   { $$ = $1 * $3; }
    |   exp '/' exp   { 
                        if ($3 == 0) {
                            yyerror("Error: Division by zero.");
                            $$ = 0;
                        } else {
                            $$ = $1 / $3;
                        }
                    }
    |   exp '^' exp   { $$ = pow($1, $3); }
    |   SIN exp       { $$ = sin($2 * M_PI / 180); }
    |   COS exp       { $$ = cos($2 * M_PI / 180); }
    |   TAN exp       { $$ = tan($2 * M_PI / 180); }
    |   NUMBER        { $$ = $1; }

%%

void yyerror(const char *error) {
    printf("Syntax Error: %s\n", error);
}

int main() {
    char input[100];

    printf("\n==============================\n");
    printf("  Simple Calculator (Lex/Yacc)\n");
    printf("  Type 'Exit' to quit\n");
    printf("==============================\n");

    while (1) {
        printf("\n➤ Enter an expression: ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcasecmp(input, "Exit") == 0) {
            printf("\nExiting calculator. Goodbye!\n\n");
            break;
        }

        if (strlen(input) == 0) {
            printf("Please enter a valid expression.\n");
            continue;
        }

        yy_scan_string(input);
        yyparse();
    }

    return 0;
}
