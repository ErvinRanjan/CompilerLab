%option noyywrap

%{
#include <stdio.h>
#include <string.h>
int integers = 0,floats = 0;
%}

d [0-9]

%%

{d}+"."{d}* {floats++;}
{d}+ {integers++;}
. {}

%%

int main(int argc,char** argv){
    if(argc > 1){
        FILE* fptr = fopen(argv[1],"r");
        yyin = fptr;
    }
    yylex();
    printf("floats: %d\nintegers: %d\n",floats,integers);
    return 0;
}
