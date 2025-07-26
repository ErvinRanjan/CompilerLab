%{
    #include "y.tab.h"
    #include "tree.h"
    #include <stdlib.h>
%}

%%

[0-9]+ { 
            yylval.node = createLeafNode(atoi(yytext)); 
            return NUM;
       }

[\n+*/\-()]  {
            return *yytext;
        }

[ \t\r] {}

%%

int yywrap(){
    return 1;
}