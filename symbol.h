#ifndef SYMBOL_H
#define SYMBOL_H

#include "tree.h"

struct symbol {
    int type;
    char varName[100];
    int size;
    int binding;
    struct symbol* next;
};

struct symbol* createSymbol(int type, char* varName, int size, int binding);
struct symbol* addSymbol(struct symbol* symbolTable, struct symbol* symbol);
int isSymbolPresent(struct symbol* symbolTable, struct symbol* symbol);
struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable);
struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable);

#endif