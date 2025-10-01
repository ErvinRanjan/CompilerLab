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
    struct symbol* gsymbolTable = NULL;
%}

%union{
    struct tNode* node;
};

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GE LE NE EQ BREAK CONTINUE DECL ENDDECL INT STR CSTR REPEAT UNTIL DO MAIN RETURN
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt Ifstmt Whilestmt BreakStmt ContinueStmt RepeatUntilStmt DoWhileStmt B E ID BREAK CONTINUE Param ParamList Body ArgList FDef FDefBlock MainBlock GDeclBlock LDeclBlock GDeclList LDeclList GDecl LDecl Type GidList LidList Gid Lid CSTR Array BraceList Identifier

%nonassoc '='
%left '%'
%left '+' '-'
%left '*' '/'

%%

Program : GDeclBlock FDefBlock MainBlock 
        | GDeclBlock MainBlock
        | MainBlock 
        ;

MainBlock : INT MAIN '(' ')'  '{' LDeclBlock Body '}' { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable($<node>6,symbolTable,0);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck($<node>7,symbolTable);
                                                            fprintf(out,"L0:\n"); 
                                                            codeGen(out,$<node>7,symbolTable);
                                                        }
        ;

Body : BLOCK_BEGIN Slist RetStmt BLOCK_END  {
                               $<node>$ = createOperatorNode(OP_STMTLIST,$<node>2,$<node>3,NULL,-1);
                               $<node>$->label = $<node>2->label;
                           }
        | BLOCK_BEGIN BLOCK_END {
                            
                                }
        ;

GDeclBlock : DECL GDeclList ENDDECL {
                                        gsymbolTable = populateSymbolTable($<node>2,gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable(gsymbolTable);
                                    }
            | DECL ENDDECL {}
            ;

GDeclList : GDeclList GDecl {
                            $<node>$ = createOperatorNode(OP_DECLLIST,$<node>1,$<node>2,NULL,-1);
                        }
         | GDecl {
                    $<node>$ = $<node>1;
                }
         ;

GDecl : Type GidList ';' {
                        $<node>$ = createOperatorNode(OP_DECL,$<node>1,$<node>2,NULL,-1);
                    }
     ;

Type : INT 
     | STR
       {
        $<node>$ = $<node>1;
       }
     ;

GidList : GidList ',' Gid    {
                                $<node>$ = createOperatorNode(OP_VARLIST,$<node>1,$<node>3,NULL,-1);
                            }
        | Gid  {
                    $<node>$ = $<node>1;
                }
        ;

Gid : ID  
    | DeclArray
    {
        $<node>$ = $<node>1; 
    } 
    | ID '(' ParamList ')' {
                                int label = getLabel();
                                $<node>$ = createOperatorNode(LEAF_FDECL,$<node>1,$<node>3,NULL,label);
                            }
    | ID '(' ')' {  
                    int label = getLabel();
                    $<node>$ = createOperatorNode(LEAF_FDECL,$<node>1,NULL,NULL,label);
                }
    ;

ParamList : ParamList ',' Param {
                            $<node>$ = createOperatorNode(OP_PARAMLIST,$<node>1,$<node>3,NULL,-1);
                        }   
        | Param {
                $<node>$ = $<node>1;
            }
        ;

Param : Type ID {
                    $<node>$ = createOperatorNode(OP_PARAM,$<node>1,$<node>2,NULL,-1);
                }
        ;


LDeclBlock : DECL LDeclList ENDDECL {
                                        $<node>$ = $<node>2;
                                    }
            | DECL ENDDECL {}
            ;

LDeclList : LDeclList LDecl {
                            $<node>$ = createOperatorNode(OP_DECLLIST,$<node>1,$<node>2,NULL,-1);
                        }
         | LDecl {
                    $<node>$ = $<node>1;
                }
         ;

LDecl : Type LidList ';' {
                        $<node>$ = createOperatorNode(OP_DECL,$<node>1,$<node>2,NULL,-1);
                    }
     ;

LidList : LidList ',' Lid    {
                                $<node>$ = createOperatorNode(OP_VARLIST,$<node>1,$<node>3,NULL,-1);
                            }
        | Lid  {
                    $<node>$ = $<node>1;
                }
        ;

Lid : ID  
    | DeclArray
    {
        $<node>$ = $<node>1; 
    } 
    ;

FDefBlock : FDefBlock FDef 
          | FDef 
          {}
          ;

FDef : Type ID '(' ParamList ')' '{' LDeclBlock Body '}' {
                                                                typeCheckFunctionParam($<node>1->type,$<node>2->varName,$<node>4,gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol($<node>2->varName,gsymbolTable,symbolTable1);
                                                                symbolTable1 = populateSymbolTable($<node>7,symbolTable1,1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck($<node>8,symbolTable1);
                                                                funcCodeGen(out,$<node>2->varName,$<node>8,symbolTable1);
                                                        }
     | Type ID '('  ')' '{' LDeclBlock Body '}'  {
        typeCheckFunctionParam($<node>1->type,$<node>2->varName,NULL,gsymbolTable);
        struct symbol* symbolTable1 = NULL;
        symbolTable1 = addParamAsSymbol($<node>2->varName,gsymbolTable,symbolTable1);
        symbolTable1 = populateSymbolTable($<node>6,symbolTable1,1);
        symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
        typeCheck($<node>7,symbolTable1);
        funcCodeGen(out,$<node>2->varName,$<node>7,symbolTable1);
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

RetStmt : RETURN E ';'{
                    int label = getLabel();
                    $<node>$ = createOperatorNode(OP_RETURN,$<node>2,NULL,NULL,label);
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
  | ID '(' ')' {
                    $<node>$ = createOperatorNode(LEAF_FUNC,$<node>1,NULL,NULL,-1);
                } 
  | ID '(' ArgList ')' {
                            $<node>$ = createOperatorNode(LEAF_FUNC,$<node>1,$<node>3,NULL,-1);
                        }
  | NUM 
  | Identifier
  | CSTR  
  {
    $<node>$ = $<node>1;
   }
  ;

ArgList : ArgList ',' E  {
                            $<node>$ = createOperatorNode(OP_ARGLIST,$<node>1,$<node>3,NULL,-1);
                        }
        | E {
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
    initCompiler(out);
    fprintf(out,"JMP L0\n");
    yyparse();
    return 0;
}