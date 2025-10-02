%{
    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include "symbol.h"
    #include "type.h"
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

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GE LE NE EQ BREAK CONTINUE DECL ENDDECL INT STR CSTR REPEAT UNTIL DO
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt Ifstmt Whilestmt BreakStmt ContinueStmt RepeatUntilStmt DoWhileStmt B E ID BREAK CONTINUE Declarations DeclList Decl Type VarList CSTR Array BraceList Identifier

%nonassoc '='
%left '%'
%left '+' '-'
%left '*' '/'

%%

Program :  Declarations Slist   {
                                struct symbol* symbolTable = NULL;
                                symbolTable = populateSymbolTable($<node>1,symbolTable);
                                printSymbolTable(symbolTable);
                                typeCheck($<node>2,symbolTable);
                                populateParent($<node>2);
                                //interpret($<node>2,symbolTable);
                                codeGen(out,$<node>2,symbolTable);
                           }
        ;

Declarations : DECL DeclList ENDDECL {
                                        $<node>$ = $<node>2;
                                    }
            | DECL ENDDECL {}
            ;

DeclList : DeclList Decl {
                            $<node>$ = createOperatorNode(OP_DECLLIST,$<node>1,$<node>2,NULL,-1);
                        }
         | Decl {
                    $<node>$ = $<node>1;
                }
         ;

Decl : Type VarList ';' {
                        $<node>$ = createOperatorNode(OP_DECL,$<node>1,$<node>2,NULL,-1);
                    }
     ;

Type : INT 
     | STR
       {
        $<node>$ = $<node>1;
       }
     ;

VarList : VarList ',' ID    {
                                $<node>$ = createOperatorNode(OP_VARLIST,$<node>1,$<node>3,NULL,-1);
                            }
        | ID    {
                    $<node>$ = $<node>1;
                }
        | VarList ',' DeclArray  {
                                $<node>$ = createOperatorNode(OP_VARLIST,$<node>1,$<node>3,NULL,-1);
                            }
        | DeclArray  {
                    $<node>$ = $<node>1;
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
     | RepeatUntilStmt 
     | DoWhileStmt
       {   
        $<node>$ = $<node>1;
       }     
     ;

Ifstmt : IF '(' B ')' THEN Slist ELSE Slist ENDIF ';' { 
                                                        int label = getLabel();
                                                        $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,$<node>8,label);
                                                  }
        |  IF '(' B ')' THEN Slist ENDIF ';' {     
                                            int label = getLabel();
                                            $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,NULL,label);
                                        }
     ;


Whilestmt : WHILE '(' B ')' DO Slist ENDWHILE ';' {   
                                                    int label = getLabel();
                                                    $<node>$ = createOperatorNode(OP_WHILE,$<node>3,$<node>6,NULL,label);
                                                }
          ;

InputStmt : READ '(' Identifier ')' ';' {
                                int label = getLabel();
                                $<node>$ = createOperatorNode(OP_READ,$<node>3,NULL,NULL,label);
                            }
          ;

OutputStmt : WRITE '(' E ')' ';' {
                                int label = getLabel();
                                $<node>$ = createOperatorNode(OP_WRITE,$<node>3,NULL,NULL,label);
                            }
            ;

AsgStmt : Identifier '=' E ';' {
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

RepeatUntilStmt  : REPEAT Slist UNTIL '(' B ')' ';' {
                    int label = getLabel();
                    $<node>$ = createOperatorNode(OP_REPEAT_UNTIL,$<node>2,$<node>5,NULL,label);
                }
                ;

DoWhileStmt : DO Slist WHILE '(' B ')' ';' {
                    int label = getLabel();
                    $<node>$ = createOperatorNode(OP_DO_WHILE,$<node>2,$<node>5,NULL,label);
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
  | E '%' E {
                $<node>$ = createOperatorNode(OP_MOD,$<node>1,$<node>3,NULL,-1);
            }
  | '&' ID {
                $<node>$ = createOperatorNode(OP_REF,$<node>2,NULL,NULL,-1); 
            }
  | '*' E {
                $<node>$ = createOperatorNode(OP_DREF,$<node>2,NULL,NULL,-1);
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

DeclArray : ID DeclBraceList {
                        $<node>$ = createOperatorNode(LEAF_ARR,$<node>1,$<node>2,NULL,-1);
                    }

DeclBraceList : DeclBraceList '[' NUM ']' {
                                        $<node>$ = createOperatorNode(OP_BRACELIST,$<node>1,$<node>3,NULL,-1);
                                    }
          | '[' NUM ']' {
                            $<node>$ = $<node>2;
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
            | '*' E {
                $<node>$ = createOperatorNode(OP_DREF,$<node>2,NULL,NULL,-1);
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