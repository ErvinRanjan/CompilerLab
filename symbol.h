#ifndef SYMBOL_H
#define SYMBOL_H

#include "tree.h"
#include "type.h"

struct symbol {
    struct type* type;
    char varName[100];
    int val;
    int size;
    int binding;
    int symbolType;
    int maxSizes[100];
    struct symbol* next;
};

struct symbol* createSymbol(struct type* type, char* varName, int size, int binding, int symbolType, int* maxSizes);
struct symbol* addSymbol(struct symbol* symbolTable, struct symbol* symbol);
int isSymbolPresent(struct symbol* symbolTable, struct symbol* symbol);
struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable);
struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable);
void printSymbolTable(struct symbol* symbolTable);

#endif