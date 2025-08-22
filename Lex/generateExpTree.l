%{
    #include "y.tab.h"
    #include "tree.h"
    #include "constants.h"
    #include <stdlib.h>
    #include "label.h"
%}

%%

"int" {
            yylval.node = createLeafNode(-1,NULL,LEAF_TYPE_INT,-1,LEAF_TYPE_INT,NULL);
            return INT;
        }

"str"   {
            yylval.node = createLeafNode(-1,NULL,LEAF_TYPE_STR,-1,LEAF_TYPE_STR,NULL);
            return STR;
        }

"decl" {
        return DECL;
    }

"enddecl" {
            return ENDDECL;
        }

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

"break" {
            int label = getLabel();
            yylval.node = createLeafNode(0,NULL,-1,label,LEAF_BREAK,NULL);
            return BREAK;
        }

"continue" {
                int label = getLabel();
                yylval.node = createLeafNode(0,NULL,-1,label,LEAF_CONTINUE,NULL);
                return CONTINUE;
            }

[0-9]+ { 
            yylval.node = createLeafNode(atoi(yytext),NULL,LEAF_TYPE_INT,-1,LEAF_NUM,NULL); 
            return NUM;
       }

\".*\" {
            sprintf(yytext,"\"%s\"",yytext);
            yylval.node = createLeafNode(-1,NULL,LEAF_TYPE_STR,-1,LEAF_STR,yytext);
            return CSTR;
        }

[_a-zA-Z]+[0-9]*   {
            yylval.node = createLeafNode(0,yytext,-1,-1,LEAF_ID,NULL);
            return ID;
       }

[+*/\-()=;<>,]  {
            return *yytext;
        }

[ \n\t\r]+ {}

%%

int yywrap(){
    return 1;
}