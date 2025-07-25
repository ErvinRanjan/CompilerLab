%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%

[\n+*] { return *yytext; }
[0-9]+ {
            yylval = atoi(yytext);
            return NUM; 
        }
. { }

%%

int yywrap() {
    return 1;
}