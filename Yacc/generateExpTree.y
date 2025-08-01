%{
    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
%}

%union{
    struct tNode* node;
};

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt E ID

%nonassoc '='
%left '+' '-'
%left '*' '/'

%%

Program : BLOCK_BEGIN Slist BLOCK_END  {
                                codeGen(out,$<node>2);
                           }
        | BLOCK_BEGIN BLOCK_END {

                                }
        ;

Slist : Slist Stmt { 
                        $<node>$ = createOperatorNode(OP_STMTLIST,$<node>1,$<node>2); 
                    }
      | Stmt { 
                $<node>$ = $<node>1;
             }
      ;

Stmt : InputStmt 
     | OutputStmt 
     | AsgStmt 
       {
        $<node>$ = $<node>1;
       }     
     ;

InputStmt : READ '(' ID ')' ';' {
                                
                                $<node>$ = createOperatorNode(OP_READ,$<node>3,NULL);
                            }
          ;

OutputStmt : WRITE '(' E ')' ';' {
                                $<node>$ = createOperatorNode(OP_WRITE,$<node>3,NULL);
                            }
            ;

AsgStmt : ID '=' E ';' {
                      $<node>$ = createOperatorNode(OP_ASSIGN,$<node>1,$<node>3);
                    }
        ;
 
E : E '+' E {
                $<node>$ = createOperatorNode(OP_ADD,$<node>1,$<node>3);
            }
  | E '*' E {
                $<node>$ = createOperatorNode(OP_MUL,$<node>1,$<node>3);
            }
  | E '-' E {
                $<node>$ = createOperatorNode(OP_SUB,$<node>1,$<node>3);
            }
  | E '/' E {
                $<node>$ = createOperatorNode(OP_DIV,$<node>1,$<node>3);
            }
  | '(' E ')' {
                 $<node>$ = $<node>2;
              }
  | NUM 
  | ID  
  {
    $<node>$ = $<node>1;
   }
  ;

%%

int yyerror(const char* s){
    printf("Error: %s\ntoken: %s",s,yytext);
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