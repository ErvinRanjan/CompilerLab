%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    extern FILE* yyin;
%}

%union{
    char name[100];
}

%token operand
%type <name> operand 

%left '+'
%left '*'

%%


program : expr '\n' {printf("%s\n",$<name>1);}
        ;
expr : expr '+' expr {sprintf($<name>$,"%s%s%s","+",$<name>1,$<name>3);}
     | expr '*' expr {sprintf($<name>$,"%s%s%s","*",$<name>1,$<name>3);}
     | operand {sprintf($<name>$,"%s",$<name>1);}
     ;

%%

int yyerror(const char* s){
   printf("Error : %s",s);
   return 0;
}

int main(int argc,char** argv){
    if(argc > 1){
        FILE* fptr = fopen(argv[1],"r");
        yyin = fptr;
    }
    yyparse();
    return 0;
}