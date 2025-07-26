%{
    #include "tree.h"
    #include "codegen.h"
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE* yyin;
    FILE* out;
%}

%union{
    struct tNode* node;
};

%token NUM 
%type <node> NUM S E 

%left '+' '-'
%left '*' '/'

%%

S : E '\n' {
                codeGen(out,$<node>1);
            }
  ;
E : E '+' E {
                $<node>$ = createOperatorNode("+",$<node>1,$<node>3);
            }
  | E '*' E {
                $<node>$ = createOperatorNode("*",$<node>1,$<node>3);
            }
  | E '-' E {
                $<node>$ = createOperatorNode("-",$<node>1,$<node>3);
            }
  | E '/' E {
                $<node>$ = createOperatorNode("/",$<node>1,$<node>3);
            }
  | '(' E ')' {
                 $<node>$ = $<node>2;
              }
  | NUM {
            $<node>$ = $<node>1;
        }
  ;

%%

int yyerror(const char* s){
    printf("Error: %s",s);
    return 0;
}

int main(int argc,char** argv){
    if(argc > 2){
        yyin = fopen(argv[1],"r"); 
        out = fopen(argv[2],"w");
    } else{
        printf("Insufficient Args: <exe> <input> <output>\n");
        exit(EXIT_FAILURE);
    }
    yyparse();
    return 0;
}