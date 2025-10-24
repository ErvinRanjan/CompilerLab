#ifndef SYMBOL_H
#define SYMBOL_H

#include "tree.h"
#include "type.h"
#include "typeTable.h"

struct symbol {
    struct type* type;
    char varName[100];
    int val;
    char cval[100];
    int size;
    int binding;
    int symbolType;
    int maxSizes[100];
    struct symbol* next;
    int* aval;
    char** acval;
    struct param* paramList;
    int flabel;
    int isGlobal;
    int vFuncTableBaseBinding;
};

struct symbol* createSymbol(struct type* type, char* varName, int size, int binding, int symbolType, int* maxSizes);
struct symbol* createSymbolForFunction(struct type* type, char* varName, int size, struct param* paramList, int fLabel);
struct symbol* addSymbol(struct symbol* symbolTable, struct symbol* symbol);
int isSymbolPresent(struct symbol* symbolTable, struct symbol* symbol);
struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable, int isLocal);
struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable);
void printSymbolTable(char* name, struct symbol* symbolTable);
struct symbol* addParamAsSymbol(struct param* paramList, struct symbol* symbolTable);
struct symbol* getLocalVarList(struct symbol* symbolTable, int paramCount);
int getParamOffset(char* varName, struct symbol* symbolTable, int paramCount);
int getLocalVarOffset(char* varName, struct symbol* localVarList);
int isParam(char* varName, struct symbol* symbolTable, int paramCount);
int getParamLenForFunction(char* fname, struct param* paramList, struct symbol* symbolTable);
struct symbol* attachSymbolTable(struct symbol* s1, struct symbol* s2);
struct symbol* appendSymbolTable(struct symbol* s1, struct symbol* s2);
struct symbol* combineChildSymbolListWithParentSymbolList(struct symbol* childSymbolList, struct typeTable* parentTypeTable);
void populateVirtualFunctionTable(int virtualFunctionTableBaseBinding, struct symbol* symbolList);
int getFunctionOffset(struct symbol* symbolTable, struct symbol* fsymbol);
struct symbol* handlePolymorphism(int vFuncTableBaseBinding, struct symbol* parentSymbolList, struct symbol* childSymbolList);
void populateVirtualFunctionTableForSymbolTable(struct symbol* symbolTable, int isGlobal);
struct symbol* addFunctionSymbol(struct symbol* fsymbol, struct symbol* symbolTable);
struct symbol* getFSymbol(char* varName, struct param* paramList, struct symbol* symbolTable);
struct symbol* reorderClassSymbolTable(struct symbol* symbolTable);


#endif