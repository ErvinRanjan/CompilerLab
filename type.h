#ifndef TYPE_H
#define TYPE_H

#include "tree.h"
#include "symbol.h"

struct type {
    int code;
    int depth;
};

struct type* createType(int code, int depth);
struct type* typeCheck(struct tNode* root, struct symbol* symbolTable);

#endif