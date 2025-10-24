#include "symbol.h"
#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "type.h"
#include "param.h"
#include "typeTable.h"
#include "out.h"
#include "utils.h"

extern bool isLeaf(int nodeType);

void getAndValidateArrayDetails(struct tNode* braceRoot, int* maxSizes, int* depth, int* size) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType == LEAF_NUM) {
        maxSizes[(*depth)] = braceRoot->val;
        (*depth) = (*depth) + 1;
        (*size) = (*size) * (braceRoot->val);
        return;
    }
    else if (braceRoot->nodeType != OP_BRACELIST) {
        printf("Error: non int type within braces in array declaration\n");
        exit(EXIT_FAILURE);
    }

    getAndValidateArrayDetails(braceRoot->left, maxSizes, depth, size);
    getAndValidateArrayDetails(braceRoot->middle, maxSizes, depth, size);
}

struct symbol* createSymbol(struct type* type, char* varName, int size, int binding, int symbolType, int* maxSizes) {
    struct symbol* sym = malloc(sizeof(struct symbol));
    strncpy(sym->varName, varName, strlen(varName));
    sym->size = size;
    sym->binding = binding;
    sym->symbolType = symbolType;
    sym->type = type;
    if (maxSizes != NULL) {
        for (int i = 0;i < type->depth;i++) {
            sym->maxSizes[i] = maxSizes[i];
        }
        sym->aval = malloc(sizeof(int) * size);
        sym->acval = malloc(sizeof(char) * size);
    }
    sym->paramList = NULL;
    sym->flabel = -1;
    sym->isGlobal = 0;
    return sym;
}

struct symbol* createSymbolForFunction(struct type* type, char* varName, int size, struct param* param, int fLabel) {
    struct symbol* sym = createSymbol(type, varName, size, -1, PRIMITIVE, NULL);
    sym->paramList = param;
    sym->flabel = fLabel;
    return sym;
}

struct symbol* addSymbolHelper(struct symbol* symbolTable, struct symbol* symbol) {
    if (symbol->flabel != -1) {
        return addFunctionSymbol(symbol, symbolTable);
    }
    if (symbolTable == NULL) {
        return symbol;
    }
    struct symbol* head = symbolTable;
    while (symbolTable->next != NULL) {
        if (strcmp(symbolTable->varName, symbol->varName) == 0) {
            printf("Error: repeated declaration of %s\n", symbol->varName);
            exit(EXIT_FAILURE);
        }
        symbolTable = symbolTable->next;
    }
    symbolTable->next = symbol;
    return head;
}

struct symbol* deepCopySymbol(struct symbol* symbol) {
    struct symbol* newSymbol = malloc(sizeof(struct symbol));
    newSymbol->binding = symbol->binding;
    newSymbol->flabel = symbol->flabel;
    newSymbol->isGlobal = symbol->isGlobal;
    newSymbol->type = symbol->type;
    for (int i = 0;i < symbol->type->depth;i++) {
        newSymbol->maxSizes[i] = symbol->maxSizes[i];
    }
    newSymbol->next = NULL;
    newSymbol->size = symbol->size;
    strcpy(newSymbol->varName, symbol->varName);
    newSymbol->paramList = symbol->paramList;
    newSymbol->vFuncTableBaseBinding = symbol->vFuncTableBaseBinding;
    newSymbol->acval = symbol->acval;
    newSymbol->aval = symbol->aval;
    strcpy(newSymbol->cval, symbol->cval);
    newSymbol->symbolType = symbol->symbolType;
    newSymbol->val = symbol->val;
    return newSymbol;
}

struct symbol* addSymbol(struct symbol* symbolTable, struct symbol* symbol) {
    return addSymbolHelper(symbolTable, deepCopySymbol(symbol));
}


int isSymbolPresent(struct symbol* symbolTable, struct symbol* symbol) {
    if (symbolTable == NULL) {
        return 0;
    }
    while (symbolTable->next != NULL) {
        if (strcmp(symbolTable->varName, symbol->varName) == 0) {
            return 1;
        }
        symbolTable = symbolTable->next;
    }
    return 0;
}

struct symbol* createSymbolForIdentifier(struct tNode* varRoot, struct type* type, int isLocal) {
    struct param* paramList = NULL;
    int numberOfParam = 0;
    switch (varRoot->nodeType) {
    case LEAF_ID: {
        struct type* t = type->typename == NULL ? createPrimitiveType(type->code, type->depth + varRoot->type->depth) : createUserDefinedTypeWithDepth(type->typename, type->depth + varRoot->type->depth);
        struct symbol* sym = createSymbol(t, varRoot->varName, 1, isLocal ? -1 : getFreeMem(getTypeSize(t)), PRIMITIVE, NULL);
        struct typeTable* typeTable = getTypeTableWithName(type->typename);
        if (typeTable != NULL && typeTable->isClass) {
            sym->vFuncTableBaseBinding = getFreeMem(8);
        }
        return sym;
    }
    case LEAF_NUM: {
        return createSymbol(type, varRoot->varName, 1, isLocal ? -1 : getFreeMem(1), PRIMITIVE, NULL);
    }
    case LEAF_ARR: {
        int depth = 0, size = 1;
        int maxSizes[100];
        getAndValidateArrayDetails(varRoot->middle, maxSizes, &depth, &size);
        depth += varRoot->type->depth;
        struct type* t = type->typename == NULL ? createPrimitiveType(type->code, depth) : createUserDefinedTypeWithDepth(type->typename, depth);
        return createSymbol(t, varRoot->left->varName, size, isLocal ? -1 : getFreeMem(size), ARRAY, maxSizes);
    }
    case LEAF_FDECL: {
        paramList = convertTreeToParamList(varRoot->middle, &numberOfParam, paramList);
        struct type* t = type->typename == NULL ? createPrimitiveType(type->code, type->depth + varRoot->type->depth) : createUserDefinedTypeWithDepth(type->typename, type->depth + varRoot->type->depth);
        return createSymbolForFunction(t, varRoot->left->varName, numberOfParam, paramList, varRoot->label);
    }
    default:
        printf("Error: Symbol is not recognized\n");
        exit(EXIT_FAILURE);
    }
    return createSymbol(createPrimitiveType(-1, 0), NULL, -1, -1, -1, NULL);
}

struct symbol* populateSymbolTableGivenVarList(struct tNode* varRoot, struct symbol* symbolTable, struct type* type, int isLocal) {
    if (varRoot == NULL) return symbolTable;

    if (isLeaf(varRoot->nodeType)) {
        return addSymbol(symbolTable, createSymbolForIdentifier(varRoot, type, isLocal));
    }

    symbolTable = populateSymbolTableGivenVarList(varRoot->left, symbolTable, type, isLocal);
    symbolTable = populateSymbolTableGivenVarList(varRoot->middle, symbolTable, type, isLocal);

    return symbolTable;
}

struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable, int isLocal) {
    if (declRoot == NULL) {
        return symbolTable;
    }

    if (declRoot->nodeType == OP_DECL) {
        symbolTable = populateSymbolTableGivenVarList(declRoot->middle, symbolTable, declRoot->left->type, isLocal);
        return symbolTable;
    }

    symbolTable = populateSymbolTable(declRoot->left, symbolTable, isLocal);
    symbolTable = populateSymbolTable(declRoot->middle, symbolTable, isLocal);

    return symbolTable;
}

struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return NULL;
    struct symbol* temp = symbolTable;
    while (temp != NULL && strcmp(varName, temp->varName) != 0) {
        temp = temp->next;
    }
    return temp;
}

void printSymbolTable(char* name, struct symbol* symbolTable) {
    printf("Symbol Table for %s\n", name);
    while (symbolTable != NULL) {
        printf("varName: %s\n", symbolTable->varName);
        if (symbolTable->type->typename != NULL) {
            printf("typename: %s\n", symbolTable->type->typename);
        }
        printf("type: %d\n", symbolTable->type->code);
        printf("pointer depth: %d\n", symbolTable->type->depth);
        printf("binding: %d\n", symbolTable->binding);
        printf("val: %d\n", symbolTable->val);
        printf("size: %d\n", symbolTable->size);
        printf("flabel: %d\n", symbolTable->flabel);
        printf("vFuncTableBaseBinding: %d\n", symbolTable->vFuncTableBaseBinding);
        struct param* p = symbolTable->paramList;
        if (p != NULL) {
            printf("parameters\n");
        }
        while (p != NULL) {
            printf("type: %d, name: %s\n", p->type->code, p->name);
            p = p->next;
        }
        symbolTable = symbolTable->next;
    }
}

struct symbol* addParamAsSymbol(struct param* paramList, struct symbol* symbolTable) {
    while (paramList != NULL) {
        symbolTable = addSymbol(symbolTable, createSymbol(paramList->type, paramList->name, 1, -1, PRIMITIVE, NULL));
        paramList = paramList->next;
    }
    return symbolTable;
}

struct symbol* getLocalVarList(struct symbol* symbolTable, int paramCount) {
    while (symbolTable != NULL && paramCount > 0) {
        symbolTable = symbolTable->next;
        paramCount--;
    }
    return symbolTable;
}

int getParamOffset(char* varName, struct symbol* symbolTable, int paramCount) {
    int offs = 0;
    while (symbolTable != NULL && strcmp(varName, symbolTable->varName) != 0) {
        symbolTable = symbolTable->next;
        offs++;
    }
    if (symbolTable == NULL || offs >= paramCount) {
        printf("Error: no such parameter exists for function: %s\n", varName);
        exit(EXIT_FAILURE);
    }
    return offs;
}

int getLocalVarOffset(char* varName, struct symbol* localVarList) {
    int offs = 0;
    int isGlobal = 0;
    while (localVarList != NULL && strcmp(varName, localVarList->varName) != 0) {
        offs += getTypeSize(localVarList->type);
        localVarList = localVarList->next;
        isGlobal |= localVarList->isGlobal;
    }
    if (localVarList == NULL) {
        printf("Error: no such local variable exists for function: %s\n", varName);
        exit(EXIT_FAILURE);
    }
    if (isGlobal) {
        return -1;
    }
    return offs;
}


int isParam(char* varName, struct symbol* symbolTable, int paramCount) {
    while (symbolTable != NULL && paramCount > 0) {
        if (strcmp(varName, symbolTable->varName) == 0) {
            return 1;
        }
        symbolTable = symbolTable->next;
        paramCount--;
    }
    return 0;
}

int getParamLenForFunction(char* fname, struct param* paramList, struct symbol* symbolTable) {
    if (fname == NULL) return 0;
    struct symbol* fsymbol = getFSymbol(fname, paramList, symbolTable);
    if (fsymbol == NULL) {
        printf("Error: no such function: %s\n", fname);
        exit(EXIT_FAILURE);
    }
    int paramCount = getParamLen(fsymbol->paramList);
    return paramCount;
}

struct symbol* appendSymbolTable(struct symbol* s1, struct symbol* s2) {
    if (s1 == NULL) return s2;
    struct symbol* head = s1;
    while (s1->next != NULL) {
        s1 = s1->next;
    }
    s1->next = s2;
    return head;
}

struct symbol* handlePolymorphism(int vFuncTableBaseBinding, struct symbol* parentSymbolList, struct symbol* childSymbolList) {
    FILE* out = getOutputStream();
    int reg = getFreeReg();
    // virtual function table base binding  - vftbb
    int vftbb = vFuncTableBaseBinding;
    int offs = 0;
    while (parentSymbolList != NULL) {
        if (parentSymbolList->flabel == -1) {
            parentSymbolList = parentSymbolList->next;
            continue;
        }
        struct symbol* symbol = parentSymbolList->flabel != -1 ? getFSymbol(parentSymbolList->varName, parentSymbolList->paramList, childSymbolList) : getSymbolTable(parentSymbolList->varName, childSymbolList);
        int flabel = 0;
        if (symbol == NULL) {
            flabel = parentSymbolList->flabel;
        }
        else {
            flabel = symbol->flabel;
        }
        fprintf(out, "MOV R%d, %d\n", reg, flabel);
        fprintf(out, "MOV [%d], R%d\n", vftbb + offs, reg);
        offs++;
        parentSymbolList = parentSymbolList->next;
    }
    freeReg();
}

struct symbol* combineChildSymbolListWithParentSymbolList(struct symbol* childSymbolList, struct symbol* parentSymbolList) {
    struct symbol* symbolList = NULL;
    struct symbol* childSymbolListHead = childSymbolList;
    int combinedMethodCount = 0;
    int combinedAttributeCount = 0;
    while (childSymbolList != NULL) {
        struct symbol* symbol = childSymbolList->flabel != -1 ? getFSymbol(childSymbolList->varName, childSymbolList->paramList, parentSymbolList) : getSymbolTable(childSymbolList->varName, parentSymbolList);
        if (childSymbolList->flabel == -1 && symbol != NULL) {
            printf("Error: cannot redeclare class attributes\n");
            exit(EXIT_FAILURE);
        }
        symbolList = addSymbol(symbolList, childSymbolList);
        if (childSymbolList->flabel == -1) {
            combinedAttributeCount++;
        }
        else {
            combinedMethodCount++;
        }
        childSymbolList = childSymbolList->next;
    }
    while (parentSymbolList != NULL) {
        struct symbol* symbol = parentSymbolList->flabel != -1 ? getFSymbol(parentSymbolList->varName, parentSymbolList->paramList, childSymbolListHead) : getSymbolTable(parentSymbolList->varName, childSymbolListHead);
        if (symbol == NULL || parentSymbolList->flabel == -1) {
            symbolList = addSymbol(symbolList, parentSymbolList);
        }
        if (parentSymbolList->flabel == -1) {
            combinedAttributeCount++;
        }
        else {
            combinedMethodCount++;
        }
        parentSymbolList = parentSymbolList->next;
    }
    if (combinedMethodCount > 8) {
        printf("Error: Child Class can have at max only 8 methods\n");
        exit(EXIT_FAILURE);
    }
    else if (combinedAttributeCount > 8) {
        printf("Error: Child Class can have at max only 8 attributes\n");
        exit(EXIT_FAILURE);
    }
    return symbolList;
}

void populateVirtualFunctionTable(int virtualFunctionTableBaseBinding, struct symbol* symbolList) {
    FILE* out = getOutputStream();
    int offset = 0;
    int reg = getFreeReg();
    while (symbolList != NULL) {
        if (symbolList->flabel != -1) {
            cprintf(out, "MOV R%d, %d\n", reg, symbolList->flabel);
            cprintf(out, "MOV [%d], R%d\n", virtualFunctionTableBaseBinding + offset, reg);
            offset++;
        }
        symbolList = symbolList->next;
    }
    freeReg();
}

void populateVirtualFunctionTableForSymbolTable(struct symbol* symbolTable, int isGlobal) {
    if (isGlobal) {
        while (symbolTable != NULL) {
            struct typeTable* t = getTypeTableWithName(symbolTable->type->typename);
            if (t != NULL && t->isClass) {
                populateVirtualFunctionTable(symbolTable->vFuncTableBaseBinding, t->symbolList);
            }
            symbolTable = symbolTable->next;
        }
    }
    else {
        while (symbolTable != NULL && !(symbolTable->isGlobal)) {
            struct typeTable* t = getTypeTableWithName(symbolTable->type->typename);
            if (t != NULL && t->isClass) {
                populateVirtualFunctionTable(symbolTable->vFuncTableBaseBinding, t->symbolList);
            }
            symbolTable = symbolTable->next;
        }
    }
}

int getFunctionOffset(struct symbol* symbolTable, struct symbol* fsymbol) {
    int offs = 0;
    while (symbolTable != NULL) {
        if (symbolTable->flabel != -1 && areFunctionSymbolsEqual(fsymbol->varName, fsymbol->paramList, symbolTable)) {
            return offs;
        }
        if (symbolTable->flabel != -1) offs++;
        symbolTable = symbolTable->next;
    }
    return -1;
}

int areFunctionSymbolsEqual(char* varName, struct param* paramList, struct symbol* fsymbol) {
    if (strcmp(varName, fsymbol->varName) != 0) {
        return 0;
    }
    struct param* paramList1 = paramList;
    struct param* paramList2 = fsymbol->paramList;
    while (paramList1 != NULL && paramList2 != NULL) {
        if (!isTypeEqual(paramList1->type, paramList2->type)) {
            return 0;
        }
        paramList1 = paramList1->next;
        paramList2 = paramList2->next;
    }
    return paramList1 == NULL && paramList2 == NULL;
}

struct symbol* addFunctionSymbolHelper(struct symbol* fsymbol, struct symbol* symbolTable) {
    if (symbolTable == NULL) return fsymbol;
    struct symbol* head = symbolTable;
    while (symbolTable->next != NULL) {
        if (symbolTable->flabel != -1 && areFunctionSymbolsEqual(fsymbol->varName, fsymbol->paramList, symbolTable)) {
            printf("Error: cannot redeclare function %s\n", fsymbol->varName);
            exit(EXIT_FAILURE);
        }
        symbolTable = symbolTable->next;
    }
    if (symbolTable->flabel != -1 && areFunctionSymbolsEqual(fsymbol->varName, fsymbol->paramList, symbolTable)) {
        printf("Error: cannot redeclare function %s\n", fsymbol->varName);
        exit(EXIT_FAILURE);
    }
    symbolTable->next = fsymbol;
    return head;
}

struct symbol* addFunctionSymbol(struct symbol* fsymbol, struct symbol* symbolTable) {
    return addFunctionSymbolHelper(deepCopySymbol(fsymbol), symbolTable);
}

struct symbol* getFSymbol(char* varName, struct param* paramList, struct symbol* symbolTable) {
    while (symbolTable != NULL) {
        if (symbolTable->flabel != -1 && areFunctionSymbolsEqual(varName, paramList, symbolTable)) {
            return symbolTable;
        }
        symbolTable = symbolTable->next;
    }
    return NULL;
}