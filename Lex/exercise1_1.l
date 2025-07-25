%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    int lines = 1,words = 0,characters = 0;
%}

%%

"\n" {lines++;}
[^\n ]+ {words++;characters += strlen(yytext);}
. {}

%%

int main(int argc,char** argv){
    if(argc > 1){
        FILE* fptr = fopen(argv[1],"r");
        yyin = fptr;
    }
    yylex();
    printf("Num of lines, word, characters are: %d %d %d",lines,words,characters);
    return 0;
}