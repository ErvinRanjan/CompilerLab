%{
    #include "y.tab.h"
    #include "tree.h"
    #include "constants.h"
    #include <stdlib.h>
    #include "label.h"
    #include "type.h"

    int getDepth(char* str,int len){
        int depth = 0;
        for(int i = 0;i < len;i++){
            if(str[i] == '*'){
                depth++;
            }
        }
        return depth;
    }
%}

%%

"main" {
            return MAIN;
        }

"return" {
            return RETURN;
        }

("int")("*")+ {
                    yylval.node = createLeafNode(-1,NULL,createType(LEAF_TYPE_INT,getDepth(yytext,strlen(yytext))),-1,LEAF_TYPE_INT,NULL);
                    return INT;
                }

("str")("*")+ {
                    yylval.node = createLeafNode(-1,NULL,createType(LEAF_TYPE_STR,getDepth(yytext,strlen(yytext))),-1,LEAF_TYPE_STR,NULL);
                    return STR;
                }

"do" { return DO; }

"repeat" { return REPEAT; }

"until" { return UNTIL; }

"int" {
            yylval.node = createLeafNode(-1,NULL,createType(LEAF_TYPE_INT,0),-1,LEAF_TYPE_INT,NULL);
            return INT;
        }

"str"   {
            yylval.node = createLeafNode(-1,NULL,createType(LEAF_TYPE_STR,0),-1,LEAF_TYPE_STR,NULL);
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
            yylval.node = createLeafNode(0,NULL,createType(-1,-1),label,LEAF_BREAK,NULL);
            return BREAK;
        }

"continue" {
                int label = getLabel();
                yylval.node = createLeafNode(0,NULL,createType(-1,-1),label,LEAF_CONTINUE,NULL);
                return CONTINUE;
            }

[0-9]+ { 
            yylval.node = createLeafNode(atoi(yytext),NULL,createType(LEAF_TYPE_INT,0),-1,LEAF_NUM,NULL); 
            return NUM;
       }

\".*\" {
            char syytext[100];
            strip(syytext,yytext,'"');
            yylval.node = createLeafNode(-1,NULL,createType(LEAF_TYPE_STR,0),-1,LEAF_STR,syytext);
            return CSTR;
        }

[_a-zA-Z]+[0-9]*   {
            yylval.node = createLeafNode(0,yytext,createType(-1,-1),-1,LEAF_ID,NULL);
            return ID;
       }

[+*/\-%()=;<>,\[\]&{}]  {
            return *yytext;
        }

[ \n\t\r]+ {}

%%

int yywrap(){
    return 1;
}