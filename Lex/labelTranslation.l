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

"\n" {

        lines++;
        if(once){
            fprintf(out,"%s",yytext);
        }
     }

"L"[0-9]+":\n" {  
                int labelNumber;
                sscanf(yytext,"L%d",&labelNumber);
                if(!once){
                    labelToAddr[labelNumber] = baseAddr + 2*lines;
                }
            }

"L"[0-9]+ {     
                int labelNumber;
                sscanf(yytext,"L%d",&labelNumber);
                if(once){
                    fprintf(out,"%d",labelToAddr[labelNumber]);
                }
            }

"L-1:\n" {
            if(!once){
                endAddr = baseAddr + 2*lines;
            }
        }

"L-1"   {
            if(once){
                fprintf(out,"%d",endAddr);
            }
        }

.       {   
            if(once){
                fprintf(out,"%s",yytext);
            }
        }

%%

int yywrap(){
    if(!once){
        once++;
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