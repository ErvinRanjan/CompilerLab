%{
    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include "symbol.h"
    #include "type.h"
    #include "label.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include "exercise.h"
    extern FILE* yyin;
    extern char* yytext;
    extern int lines;
    FILE* out;
%}

%union{
    struct tNode* node;
};

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GE LE NE EQ BREAK CONTINUE DECL ENDDECL INT STR CSTR
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt Ifstmt Whilestmt BreakStmt ContinueStmt B E ID BREAK CONTINUE Declarations DeclList Decl Type VarList CSTR Array BraceList Identifier

%nonassoc '='
%left '%'
%left '+' '-'
%left '*' '/'

%%

P : E { preorder($<node>1); printf("\n"); postorder($<node>1); }
  ;
 
E : '+' E E  {
                $<node>$ = createOperatorNode(OP_ADD,$<node>2,$<node>3,NULL,-1);
            }
  | '*' E E {
                $<node>$ = createOperatorNode(OP_MUL,$<node>2,$<node>3,NULL,-1);
            }
  | '-' E E {
                $<node>$ = createOperatorNode(OP_SUB,$<node>2,$<node>3,NULL,-1);
            }
  | '/' E E {
                $<node>$ = createOperatorNode(OP_DIV,$<node>2,$<node>3,NULL,-1);
            }
  | '(' E ')' {
                 $<node>$ = $<node>2;
              }
  | NUM 
  | Identifier
  | CSTR  
  {
    $<node>$ = $<node>1;
   }
  ;

Array : ID BraceList {
                        $<node>$ = createOperatorNode(LEAF_ARR,$<node>1,$<node>2,NULL,-1);
                    }

BraceList : BraceList '[' E ']' {
                                        $<node>$ = createOperatorNode(OP_BRACELIST,$<node>1,$<node>3,NULL,-1);
                                    }
          | '[' E ']' {
                            $<node>$ = $<node>2;
                        }
          ;

Identifier : ID 
            | Array 
            {
                $<node>$ = $<node>1;
            }
            ;

%%

int yyerror(const char* s){
    printf("Error: %s\ntoken: %s\n",s,yytext);
    printf("Line number: %d\n",lines + 1);
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