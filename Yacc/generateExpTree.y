%{
    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include "label.h"
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
%}

%union{
    struct tNode* node;
};

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GE LE NE EQ BREAK CONTINUE
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt Ifstmt Whilestmt BreakStmt ContinueStmt B E ID BREAK CONTINUE 

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
                        $<node>$ = createOperatorNode(OP_STMTLIST,$<node>1,$<node>2,NULL,-1);
                        $<node>$->label = $<node>1->label;
                    }
      | Stmt { 
                $<node>$ = $<node>1;
             }
      ;

Stmt : InputStmt 
     | OutputStmt 
     | AsgStmt 
     | Ifstmt
     | Whilestmt
     | BreakStmt
     | ContinueStmt
       {   
        $<node>$ = $<node>1;
       }     
     ;

Ifstmt : IF '(' B ')' THEN Slist ELSE Slist ENDIF { 
                                                        int label = getLabel();
                                                        $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,$<node>8,label);
                                                  }
        |  IF '(' B ')' THEN Slist ENDIF {     
                                            int label = getLabel();
                                            $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,NULL,label);
                                        }
     ;


Whilestmt : WHILE '(' B ')' DO Slist ENDWHILE {   
                                                    int label = getLabel();
                                                    $<node>$ = createOperatorNode(OP_WHILE,$<node>3,$<node>6,NULL,label);
                                                }
          ;

InputStmt : READ '(' ID ')' ';' {
                                int label = getLabel();
                                $<node>$ = createOperatorNode(OP_READ,$<node>3,NULL,NULL,label);
                            }
          ;

OutputStmt : WRITE '(' E ')' ';' {
                                int label = getLabel();
                                $<node>$ = createOperatorNode(OP_WRITE,$<node>3,NULL,NULL,label);
                            }
            ;

AsgStmt : ID '=' E ';' {
                      int label = getLabel();
                      $<node>$ = createOperatorNode(OP_ASSIGN,$<node>1,$<node>3,NULL,label);
                    }
        ;

BreakStmt : BREAK ';'
ContinueStmt : CONTINUE ';' 
        {
            $<node>$ = $<node>1;
        }
        ;   

B : E '<' E {
                $<node>$ = createOperatorNode(OP_LT,$<node>1,$<node>3,NULL,-1);
            }
  | E '>' E {
                $<node>$ = createOperatorNode(OP_GT,$<node>1,$<node>3,NULL,-1);
            }
  | E GE E {
                $<node>$ = createOperatorNode(OP_GE,$<node>1,$<node>3,NULL,-1);
            }
  | E LE E {
                $<node>$ = createOperatorNode(OP_LE,$<node>1,$<node>3,NULL,-1);
            }
  | E NE E {
                $<node>$ = createOperatorNode(OP_NE,$<node>1,$<node>3,NULL,-1);
            }
  | E EQ E {
                $<node>$ = createOperatorNode(OP_EQ,$<node>1,$<node>3,NULL,-1);
            }
  ;
 
E : E '+' E {
                $<node>$ = createOperatorNode(OP_ADD,$<node>1,$<node>3,NULL,-1);
            }
  | E '*' E {
                $<node>$ = createOperatorNode(OP_MUL,$<node>1,$<node>3,NULL,-1);
            }
  | E '-' E {
                $<node>$ = createOperatorNode(OP_SUB,$<node>1,$<node>3,NULL,-1);
            }
  | E '/' E {
                $<node>$ = createOperatorNode(OP_DIV,$<node>1,$<node>3,NULL,-1);
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