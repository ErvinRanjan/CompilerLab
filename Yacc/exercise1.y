%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    extern FILE* yyin;
%}

%token NUM
%left '+' 
%left '*'

%%


program : expr '\n' {printf("\nProgram Completed");}
        ;
expr : expr '+' expr {printf("+ ");}
     | expr '*' expr {printf("* ");}
     | NUM {printf("%d ",$1);}
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