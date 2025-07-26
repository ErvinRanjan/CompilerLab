%{
    #include "tree.h"
    #include <stdio.h>
    void print(struct tNode* root);
    extern FILE* yyin;
%}

%union{
    struct tNode* node;
};

%token NUM 
%type <node> NUM S E 

%left '+'

%%

S : E '\n' {
                print($<node>1);
            }
  ;
E : E '+' E {
                $<node>$ = createOperatorNode("+",$<node>1,$<node>3);
            }
  | '(' E ')' {
                 $<node>$ = $<node>2;
              }
  | NUM {
            $<node>$ = $<node>1;
        }
  ;

%%

void print(struct tNode* root){
    if(root == NULL) return;

    print(root->left);
    print(root->right);

    if(root->isLeaf){
        printf("%d ",root->val);
    } else {
        printf("%s ",root->op);
    }
}

int yyerror(const char* s){
    printf("Error: %s",s);
    return 0;
}

int main(int argc,char** argv){
    if(argc > 1){
        yyin = fopen(argv[1],"r"); 
    }
    yyparse();
    return 0;
}