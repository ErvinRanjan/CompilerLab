%{
    #include "y.tab.h"
    #include "tree.h"
    #include "constants.h"
    #include <stdlib.h>
%}

%%

"<=" {
        return LE;
    }

">=" {
        return GE;
     }

"==" {
        return EQ;
    }

"!=" {
        return NE;
     }

"if" {
        return IF;
     }

"else" {
            return ELSE;
        }

"then" {
            return THEN;
        }

"endif" {
            return ENDIF;
        }

"while" {
            return WHILE;
        }

"do"    {
            return DO;
        }

"endwhile" {
                return ENDWHILE;
            }

"begin" {
            return BLOCK_BEGIN;
        }

"end"   {
            return BLOCK_END;
        }

"read"  {
            return READ;
        }

"write" {
            return WRITE;
        }

[0-9]+ { 
            yylval.node = createLeafNode(atoi(yytext),NULL,INT); 
            return NUM;
       }

[a-z]   {
            yylval.node = createLeafNode(0,yytext,INT);
            return ID;
       }

[+*/\-()=;<>]  {
            return *yytext;
        }

[ \n\t\r]+ {}

%%

int yywrap(){
    return 1;
}