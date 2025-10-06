%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "constants.h"
    int labelToAddr[1000];
    int lines = -8;
    char filename[1000];
    int once = 0, baseAddr = ENTRY_POINT, endAddr = -1; 
    FILE* out;
%}

%%



.       {   
            fprintf(out,"%s",yytext);
        }

%%

int yywrap(){
    return 1;
}

int main(int argc,char** argv){
    if(argc > 2){
        strncpy(filename,argv[1],strlen(argv[1]));
        yyin = fopen(filename,"r");
        out = fopen(argv[2],"w");
    }
    yylex();
    return 0;
}