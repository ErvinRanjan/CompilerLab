#ifndef TYPE_H
#define TYPE_H

#include "tree.h"
#include "symbol.h"
#include "param.h"

struct type {
    char* typename;
    int code;
    int depth;
};

struct type* createPrimitiveType(int code, int depth);
struct type* typeCheck(struct tNode* root, struct symbol* symbolTable);
void typeCheckFunctionParam(struct type* type, char* varName, struct tNode* paramRoot, struct symbol* symbolTable);
int isTypeEqual(struct type* t1, struct type* t2);
struct type* createUserDefinedTypeWithName(char* typename);
struct type* createUserDefinedTypeWithDepth(char* typename, int depth);
struct type* createType(char* typename, int code, int depth);

#endif