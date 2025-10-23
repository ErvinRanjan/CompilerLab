%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "constants.h"
    #include "utils.h"
    int labelToAddr[1000];
    int lines = -8;
    char filename[1000];
    int second_time = 0, baseAddr = ENTRY_POINT, endAddr = -1; 
    FILE* out;
%}

%%

"/*"([^*]|\*+[^/])*"*/\n"    {}

"\n" {
        lines++;
        if(second_time){
            fprintf(out,"%s",yytext);
        }
     }

"L"[0-9]+":\n" {
    int labelNumber;
    sscanf(yytext, "L%d", &labelNumber);
    if(!second_time){
        labelToAddr[labelNumber] = baseAddr + 2*lines;
    }
}

"L"[0-9]+ {     
                int labelNumber;
                sscanf(yytext,"L%d",&labelNumber);
                if(second_time){
                    fprintf(out,"%d",labelToAddr[labelNumber]);
                }
            }

"L-1:\n" {
            if(!second_time){
                endAddr = baseAddr + 2*lines;
            }
        }

"L-1"   {
            if(second_time){
                fprintf(out,"%d",endAddr);
            }
        }

.       {   
            if(second_time){
                fprintf(out,"%s",yytext);
            }
        }

%%

int yywrap(){
    if(!second_time){
        second_time++;
        yyin = fopen(filename,"r");
        return 0;
    }
    return 1;
}

int main(int argc,char** argv){
    memset(labelToAddr,-1,sizeof(labelToAddr));

    if(argc > 2){
        strncpy(filename,argv[1],strlen(argv[1]));
        yyin = fopen(filename,"r");
        out = fopen(argv[2],"w");
    }
    yylex();

    return 0;
}