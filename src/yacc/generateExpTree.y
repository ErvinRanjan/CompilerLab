%{
    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include "symbol.h"
    #include "type.h"
    #include "label.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include "typeTable.h"
    #include "param.h"
    #include "out.h"
    #include "utils.h"
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
    struct symbol* gsymbolTable = NULL;
    int latestClassIndex = 0;
%}

%union{
    struct tNode* node;
};

%token NUM ID BLOCK_BEGIN BLOCK_END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GE LE NE EQ BREAK CONTINUE DECL ENDDECL INT STR CSTR REPEAT UNTIL DO MAIN RETURN TYPEDECL ENDTYPEDECL TUPLE STRUCT INITIALISE FREE ALLOC ARROW CLASS SELF NEW EXTENDS
%type <node> NUM Program Slist Stmt InputStmt AsgStmt OutputStmt Ifstmt Whilestmt BreakStmt ContinueStmt RepeatUntilStmt DoWhileStmt B E ID BREAK CONTINUE Param ParamList Body ArgList FDef FDefBlock MainBlock GDeclBlock LDeclBlock GDeclList LDeclList GDecl LDecl Type GidList LidList Gid Lid CSTR Array BraceList Identifier TypeDeclBlock TypeDeclList TypeDecl PartialTypeDecl InitialiseStmt FreeStmt AllocStmt ClassDeclList ClassDecl MethodDefBlock MethodDef ClassGDeclBlock ClassDeclBlock NewStmt

%nonassoc '='
%left '%'
%left '+' '-'
%left '*' '/'
%left '.' ARROW

%%

Program : TypeDeclBlock ClassDeclBlock GDeclBlock FDefBlock MainBlock 
        | TypeDeclBlock ClassDeclBlock GDeclBlock MainBlock
        | TypeDeclBlock ClassDeclBlock MainBlock
        | ClassDeclBlock GDeclBlock FDefBlock MainBlock
        | ClassDeclBlock GDeclBlock MainBlock
        | ClassDeclBlock MainBlock 
        | TypeDeclBlock GDeclBlock FDefBlock MainBlock 
        | TypeDeclBlock GDeclBlock MainBlock
        | TypeDeclBlock MainBlock
        | GDeclBlock FDefBlock MainBlock
        | GDeclBlock MainBlock
        | MainBlock 
        ;

ClassDeclBlock : ClassDeclList { printClassTable(); }
                ;

ClassDeclList : ClassDeclList ClassDecl {}
                | ClassDecl {}
                ;

ClassDecl : LeftClassDecl MethodDefBlock '}' {}
          | LeftClassDecl '}' {}
          ;

LeftClassDecl : PartialLeftClassDecl '{' ClassGDeclBlock
                {
                    struct symbol* symbolTable = NULL;
                    symbolTable = populateSymbolTable($<node>3,symbolTable,1); // setting isLocal flag to not allocate mem
                    updateTypeTable($<node>1->varName,NULL,symbolTable);
                }
                | PartialLeftClassDecl EXTENDS ID '{' ClassGDeclBlock 
                 {
                    struct symbol* symbolTable = NULL;
                    symbolTable = populateSymbolTable($<node>5,symbolTable,1); // setting isLocal flag to not allocate mem
                    struct typeTable* typeTable = updateTypeTable($<node>1->varName,NULL,symbolTable);
                    struct typeTable* parentTypeTable = getTypeTableWithName($<node>3->varName);
                    if(parentTypeTable == NULL){
                        printf("Error: class %s has not been declared but is used as a parent class to %s\n",$<node>3->varName,$<node>1->varName);
                        exit(EXIT_FAILURE);
                    } 
                    typeTable->parent = parentTypeTable;
                    typeTable->symbolList = combineChildSymbolListWithParentSymbolList(typeTable->symbolList,parentTypeTable->symbolList);
                }
              ;

PartialLeftClassDecl : CLASS ID {
                        latestClassIndex =  populateTypeTable($<node>2->varName,1);
                        $<node>$ = $<node>2;
                     }
                     ;

ClassGDeclBlock : DECL ENDDECL {}
                | DECL GDeclList ENDDECL {
                    $<node>$ = $<node>2;
                }
                ;

MethodDefBlock : MethodDefBlock MethodDef {}
                | MethodDef {}
                ;

MethodDef : Type Pid '(' ParamList ')' '{' LDeclBlock Body '}' {
                                                                $<node>1->type->depth += $<node>2->type->depth;
                                                                struct symbol* symbolTable2 = getClassTableWithIndex(latestClassIndex)->symbolList;
                                                                symbolTable2->isGlobal = 1;
                                                                typeCheckFunctionParam($<node>1->type,$<node>2->varName,$<node>4,symbolTable2);
                                                                struct symbol* symbolTable1 = NULL;
                                                                int numberOfParam = 0;
                                                                struct param* paramList = NULL;
                                                                paramList = convertTreeToParamList($<node>4,&numberOfParam,paramList);
                                                                symbolTable1 = addParamAsSymbol(paramList,symbolTable1);
                                                                symbolTable1 = populateSymbolTable($<node>7,symbolTable1,1);
                                                                printSymbolTable($<node>2->varName,symbolTable1);
                                                                typeCheck($<node>8,symbolTable1,latestClassIndex);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,symbolTable2);
                                                                populateParent($<node>8);
                                                                funcCodeGen(out,$<node>2->varName,paramList,$<node>8,symbolTable1,latestClassIndex);
                                                        }
          | Type Pid '(' ')' '{' LDeclBlock Body '}' {
                        $<node>1->type->depth += $<node>2->type->depth;
                        struct symbol* symbolTable2 = getClassTableWithIndex(latestClassIndex)->symbolList;
                        symbolTable2->isGlobal = 1;
                        typeCheckFunctionParam($<node>1->type,$<node>2->varName,NULL,symbolTable2);
                        struct symbol* symbolTable1 = NULL;
                        symbolTable1 = populateSymbolTable($<node>6,symbolTable1,1);
                        typeCheck($<node>7,symbolTable1,latestClassIndex);
                        symbolTable1 = appendSymbolTable(symbolTable1,symbolTable2);
                        populateParent($<node>7);
                        funcCodeGen(out,$<node>2->varName,NULL,$<node>7,symbolTable1,latestClassIndex);
          }
          ;

TypeDeclBlock : TYPEDECL ENDTYPEDECL {}
              | TYPEDECL TypeDeclList ENDTYPEDECL {
                printTypeTable();
              }
              ;

TypeDeclList : TypeDecl TypeDeclList {}
            | TypeDecl {}
            ;

TypeDecl : PartialTypeDecl '{' ParamList '}' ';' {
                int numberOfParam = 0;
                updateTypeTable($<node>1->varName,convertTreeToParamList($<node>3,&numberOfParam,NULL),NULL);
            }
        ;   

PartialTypeDecl : STRUCT ID {
                        populateTypeTable($<node>2->varName,0);
                        $<node>$ = $<node>2;
            } 
                ;

MainBlock : INT MAIN '(' ')'  '{' LDeclBlock Body '}' { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable($<node>6,symbolTable,0);
                                                            printSymbolTable("main",symbolTable);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck($<node>7,symbolTable,-1);
                                                            cprintf(out,"L0:\n"); 
                                                            populateParent($<node>7);
                                                            codeGen(out,$<node>7,symbolTable);
                                                        }
        ;

Body : BLOCK_BEGIN Slist RetStmt BLOCK_END 
                                {
                                    $<node>$ = createOperatorNode(OP_STMTLIST,$<node>2,$<node>3,NULL,-1);
                                    $<node>$->label = $<node>2->label;
                                }
        | BLOCK_BEGIN RetStmt BLOCK_END {
            $<node>$ = $<node>2;
        }
        | BLOCK_BEGIN BLOCK_END {}
        ;

GDeclBlock : DECL GDeclList ENDDECL {   
                                        $<node>$ = $<node>2;
                                        gsymbolTable = populateSymbolTable($<node>2,gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
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
     | ID
       {
        struct typeTable* type = getTypeTableWithName($<node>1->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",$<node>1->varName);
            exit(EXIT_FAILURE);
        }
        $<node>1->type = createUserDefinedTypeWithName($<node>1->varName);
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
                                $<node>$ = createOperatorNode(LEAF_FDECL,$<node>1,$<node>3,NULL,10);
                                $<node>$->type = $<node>1->type;
                            }
    | ID '(' ')' {  
                    $<node>$ = createOperatorNode(LEAF_FDECL,$<node>1,NULL,NULL,10);
                    $<node>$->type = $<node>1->type;
                }
    | '*' Gid {
                    $<node>2->type->depth = $<node>2->type->depth + 1;
                    $<node>$ = $<node>2;
                }
    ;

ParamList : ParamList ',' Param {
                            $<node>$ = createOperatorNode(OP_PARAMLIST,$<node>1,$<node>3,NULL,-1);
                        }   
        | Param {
                $<node>$ = $<node>1;
            }
        ;

Param : Type Pid {
                    $<node>$ = createOperatorNode(OP_PARAM,$<node>1,$<node>2,NULL,-1);
                    $<node>$->type = $<node>2->type;
                }
        ;

Pid : ID {
            $<node>$ = $<node>1;
            }
    | '*' Pid {
            $<node>2->type->depth = $<node>2->type->depth + 1;
            $<node>$ = $<node>2; 
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
    | '*' Lid {
        $<node>2->type->depth = $<node>2->type->depth + 1;
        $<node>$ = $<node>2;
    }
    ;

FDefBlock : FDefBlock FDef 
          | FDef 
          {}
          ;

FDef : Type Pid '(' ParamList ')' '{' LDeclBlock Body '}' {
                                                                $<node>1->type->depth += $<node>2->type->depth;
                                                                typeCheckFunctionParam($<node>1->type,$<node>2->varName,$<node>4,gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                struct param* paramList = NULL;
                                                                int numberOfParam = 0;
                                                                paramList = convertTreeToParamList($<node>4,&numberOfParam,paramList);
                                                                symbolTable1 = addParamAsSymbol(paramList,symbolTable1);
                                                                symbolTable1 = populateSymbolTable($<node>7,symbolTable1,1);
                                                                printSymbolTable($<node>2->varName,symbolTable1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck($<node>8,symbolTable1,-1);
                                                                populateParent($<node>8);
                                                                funcCodeGen(out,$<node>2->varName,paramList,$<node>8,symbolTable1,-1);
                                                        }
     | Type Pid '('  ')' '{' LDeclBlock Body '}'  {
        $<node>1->type->depth += $<node>2->type->depth;
        typeCheckFunctionParam($<node>1->type,$<node>2->varName,NULL,gsymbolTable);
        struct symbol* symbolTable1 = NULL;
        symbolTable1 = populateSymbolTable($<node>6,symbolTable1,1);
        symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
        typeCheck($<node>7,symbolTable1,-1);
        populateParent($<node>7);
        funcCodeGen(out,$<node>2->varName,NULL,$<node>7,symbolTable1,-1);
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
     | InitialiseStmt 
     | FreeStmt
     | AllocStmt
     | NewStmt
       {   
        $<node>$ = $<node>1;
       }     
     ;

AllocStmt : Identifier '=' ALLOC '(' ')' ';' {
    int label = getLabel();
    $<node>$ = createOperatorNode(OP_ALLOC,$<node>1,NULL,NULL,label);
} 
;

NewStmt : Identifier '=' NEW '(' ID ')' ';' {
    int label = getLabel();
    $<node>$ = createOperatorNode(LEAF_NEW,$<node>1,$<node>5,NULL,label);
} 
;

InitialiseStmt : INITIALISE '(' ')' ';' {
    int label = getLabel();
    $<node>$ = createOperatorNode(OP_INITIALISE,NULL,NULL,NULL,label);
}
;

FreeStmt : FREE '(' Identifier ')' ';' {
    int label = getLabel();
    $<node>$ = createOperatorNode(OP_FREE,$<node>3,NULL,NULL,label);
}
;

RetStmt : RETURN E ';'{
                    int label = getLabel();
                    $<node>$ = createOperatorNode(OP_RETURN,$<node>2,NULL,NULL,label);
        }
        ;

Ifstmt : IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'{ 
                                                        int label = getLabel();
                                                        $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,$<node>8,label);
                                                  }
        |  IF '(' B ')' THEN Slist ENDIF ';'{     
                                            int label = getLabel();
                                            $<node>$ = createOperatorNode(OP_IF,$<node>3,$<node>6,NULL,label);
                                        }
     ;


Whilestmt : WHILE '(' B ')' DO Slist ENDWHILE ';'{   
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
  | '(' E ')' {
                 $<node>$ = $<node>2;
              }
  | ID '(' ')' {
                    $<node>$ = createOperatorNode(LEAF_FUNC,$<node>1,NULL,NULL,-1);
                } 
  | ID '(' ArgList ')' {
                            $<node>$ = createOperatorNode(LEAF_FUNC,$<node>1,$<node>3,NULL,-1);
                        }
  | E '.' ID '(' ')' {
                            $<node>$ = createOperatorNode(LEAF_METHOD,$<node>1,$<node>3,NULL,-1);
                        }
  | E '.' ID '(' ArgList ')' {
                            $<node>$ = createOperatorNode(LEAF_METHOD,$<node>1,$<node>3,$<node>5,-1);
                        }
| E ARROW ID '(' ')' {      
                            struct tNode* temp = createOperatorNode(OP_DREF,$<node>1,NULL,NULL,-1);
                            $<node>$ = createOperatorNode(LEAF_METHOD,temp,$<node>3,NULL,-1);
                        }
  | E ARROW ID '(' ArgList ')' {
                            struct tNode* temp = createOperatorNode(OP_DREF,$<node>1,NULL,NULL,-1);
                            $<node>$ = createOperatorNode(LEAF_METHOD,temp,$<node>3,$<node>5,-1);
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
                        $<node>$->type = $<node>1->type;
                    }
            ;

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
        ;

BraceList : BraceList '[' E ']' {
                                        $<node>$ = createOperatorNode(OP_BRACELIST,$<node>1,$<node>3,NULL,-1);
                                    }
          | '[' E ']' {
                            $<node>$ = $<node>2;
                        }
          ;

Identifier : ID 
            | Array 
            | SELF
            {
                $<node>$ = $<node>1;
            }
            | '*' E {
                $<node>$ = createOperatorNode(OP_DREF,$<node>2,NULL,NULL,-1);
            }
            | E '.' ID {
                $<node>$ = createOperatorNode(LEAF_TUPLE_ACCESS,$<node>1,$<node>3,NULL,-1);
            }
            | E ARROW ID {
                struct tNode* temp = createOperatorNode(OP_DREF,$<node>1,NULL,NULL,-1);
                $<node>$ = createOperatorNode(LEAF_TUPLE_ACCESS,temp,$<node>3,NULL,-1);
            }
            ;

%%

int yyerror(const char* s){
    printf("Error: %s\ntoken: %s\n",s,yytext); 
    return 0;
}

int main(int argc,char** argv){
    if(argc > 2){
        yyin = fopen(argv[1],"r"); 
        out = fopen(argv[2],"w");
        setOutputStream(out);
    } else{
        printf("Insufficient Args: <exe> <input> <output>\n");
        exit(EXIT_FAILURE);
    }
    initCompiler(out);
    cprintf(out,"JMP L0\n");
    yyparse();
    return 0;
}