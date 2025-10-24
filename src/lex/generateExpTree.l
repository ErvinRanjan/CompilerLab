%{
    #include "y.tab.h"
    #include "tree.h"
    #include "constants.h"
    #include <stdlib.h>
    #include "label.h"
    #include "type.h"
%}

%%

"/*"([^*]|\*+[^/])*"*/"    {}

"//"[^\n]* {}

"extends" {
    return EXTENDS;
}

"new" {
        return NEW;
    }

"self" {
            yylval.node = createLeafNode(-1,NULL,NULL,-1,LEAF_SELF,NULL);
            return SELF;
        }

"class" {
                return CLASS;
            }

"->" {
    return ARROW;
}

"initialise" {
                return INITIALISE;
        }

"free" {
    return FREE;
}

"alloc" {
    return ALLOC;
}

"struct" {
            return STRUCT;
        }

"tuple" {
            return TUPLE;
            }

"typedecl" {
                return TYPEDECL;
        }

"endtypedecl" {
                return ENDTYPEDECL;
            }

"main" {
            return MAIN;
        }

"return" {
            return RETURN;
        }

"do" { return DO; }

"repeat" { return REPEAT; }

"until" { return UNTIL; }

"int" {
            yylval.node = createLeafNode(-1,NULL,createPrimitiveType(LEAF_TYPE_INT,0),-1,LEAF_TYPE_INT,NULL);
            return INT;
        }

"str"   {
            yylval.node = createLeafNode(-1,NULL,createPrimitiveType(LEAF_TYPE_STR,0),-1,LEAF_TYPE_STR,NULL);
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
            yylval.node = createLeafNode(0,NULL,createPrimitiveType(-1,-1),label,LEAF_BREAK,NULL);
            return BREAK;
        }

"continue" {
                int label = getLabel();
                yylval.node = createLeafNode(0,NULL,createPrimitiveType(-1,-1),label,LEAF_CONTINUE,NULL);
                return CONTINUE;
            }

[0-9]+ { 
            yylval.node = createLeafNode(atoi(yytext),NULL,createPrimitiveType(LEAF_TYPE_INT,0),-1,LEAF_NUM,NULL); 
            return NUM;
    }

\"[^\"]+\" {
            char syytext[100];
            strip(syytext,yytext,'"');
            yylval.node = createLeafNode(-1,NULL,createPrimitiveType(LEAF_TYPE_STR,0),-1,LEAF_STR,syytext);
            return CSTR;
        }

[_a-zA-Z]+[0-9]*   {
            yylval.node = createLeafNode(0,yytext,createPrimitiveType(-1,0),-1,LEAF_ID,NULL);
            return ID;
    }

[\.+*/\-%()=;<>,\[\]&{}]  {
            return *yytext;
        }

[ \t\r]+ {}

[\n] {
    }

%%

int yywrap(){
    return 1;
}