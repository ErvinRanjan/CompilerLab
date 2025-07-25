%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%

[\n+*] { return *yytext; }
[^ +*\r\t]+ {
            sprintf(yylval.name,"%s",yytext);
            return operand; 
        }
. { }

%%

int yywrap() {
    return 1;
}