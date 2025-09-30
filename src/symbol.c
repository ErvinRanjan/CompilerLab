#include "symbol.h"
#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "type.h"
#include "param.h"

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
    return sym;
}

struct symbol* createSymbolForFunction(struct type* type, char* varName, int size, struct param* param, int fLabel) {
    struct symbol* sym = createSymbol(type, varName, size, -1, PRIMITIVE, NULL);
    sym->paramList = param;
    sym->flabel = fLabel;
    return sym;
}

struct symbol* addSymbol(struct symbol* symbolTable, struct symbol* symbol) {
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
    case LEAF_ID:
        return createSymbol(type, varRoot->varName, 1, isLocal ? -1 : getFreeMem(1), PRIMITIVE, NULL);
    case LEAF_NUM:
        return createSymbol(type, varRoot->varName, 1, isLocal ? -1 : getFreeMem(1), PRIMITIVE, NULL);
    case LEAF_ARR:
        int depth = 0, size = 1;
        int maxSizes[100];
        getAndValidateArrayDetails(varRoot->middle, maxSizes, &depth, &size);
        return createSymbol(createType(type->code, depth), varRoot->left->varName, size, isLocal ? -1 : getFreeMem(size), ARRAY, maxSizes);
    case LEAF_FDECL:
        paramList = convertTreeToParamList(varRoot->middle, &numberOfParam, paramList);
        return createSymbolForFunction(type, varRoot->left->varName, numberOfParam, paramList, varRoot->label);
    default:
        printf("Error: Symbol is not recognized\n");
        exit(EXIT_FAILURE);
    }
    return createSymbol(createType(-1, 0), NULL, -1, -1, -1, NULL);
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

void printSymbolTable(struct symbol* symbolTable) {
    while (symbolTable != NULL) {
        printf("varName: %s\n", symbolTable->varName);
        printf("type: %d\n", symbolTable->type->code);
        printf("pointer depth: %d\n", symbolTable->type->depth);
        printf("binding: %d\n", symbolTable->binding);
        printf("val: %d\n", symbolTable->val);
        printf("size: %d\n", symbolTable->size);
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

struct symbol* addParamAsSymbol(char* varName, struct symbol* gsymbolTable, struct symbol* symbolTable) {
    struct symbol* functionSymbol = getSymbolTable(varName, gsymbolTable);
    if (functionSymbol == NULL) {
        printf("Error: function has not been declared : %s\n", varName);
        exit(EXIT_FAILURE);
    }
    struct param* paramList = functionSymbol->paramList;
    while (paramList != NULL) {
        symbolTable = addSymbol(symbolTable, createSymbol(paramList->type, paramList->name, 1, -1, PRIMITIVE, NULL));
        paramList = paramList->next;
    }
    return symbolTable;
}

