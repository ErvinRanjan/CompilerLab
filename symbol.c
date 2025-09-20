#include "symbol.h"
#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "type.h"

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
    sym->type = type;
    strncpy(sym->varName, varName, strlen(varName));
    sym->size = size;
    sym->binding = binding;
    sym->symbolType = symbolType;
    sym->type = type;
    if (maxSizes != NULL) {
        for (int i = 0;i < type->depth;i++) {
            sym->maxSizes[i] = maxSizes[i];
        }
    }
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

struct symbol* createSymbolForIdentifier(struct tNode* varRoot, struct type* type) {
    switch (varRoot->nodeType) {
    case LEAF_ID:
        return createSymbol(type, varRoot->varName, 1, getFreeMem(1), PRIMITIVE, NULL);
    case LEAF_NUM:
        return createSymbol(type, varRoot->varName, 1, getFreeMem(1), PRIMITIVE, NULL);
    case LEAF_ARR:
        int depth = 0, size = 1;
        int maxSizes[100];
        getAndValidateArrayDetails(varRoot->middle, maxSizes, &depth, &size);
        return createSymbol(createType(type->code, depth), varRoot->left->varName, size, getFreeMem(size), ARRAY, maxSizes);
    default:
        printf("Error: Symbol is not recognized\n");
        exit(EXIT_FAILURE);
    }
    return createSymbol(createType(-1, 0), NULL, -1, -1, -1, NULL);
}

struct symbol* populateSymbolTableGivenVarList(struct tNode* varRoot, struct symbol* symbolTable, struct type* type) {
    if (varRoot == NULL) return symbolTable;

    if (isLeaf(varRoot->nodeType)) {
        return addSymbol(symbolTable, createSymbolForIdentifier(varRoot, type));
    }

    symbolTable = populateSymbolTableGivenVarList(varRoot->left, symbolTable, type);
    symbolTable = populateSymbolTableGivenVarList(varRoot->middle, symbolTable, type);

    return symbolTable;
}

struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable) {
    if (declRoot == NULL) {
        return symbolTable;
    }

    if (declRoot->nodeType == OP_DECL) {
        symbolTable = populateSymbolTableGivenVarList(declRoot->middle, symbolTable, declRoot->left->type);
        return symbolTable;
    }

    symbolTable = populateSymbolTable(declRoot->left, symbolTable);
    symbolTable = populateSymbolTable(declRoot->middle, symbolTable);

    return symbolTable;
}

struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return NULL;
    while (symbolTable != NULL && strcmp(varName, symbolTable->varName) != 0) {
        symbolTable = symbolTable->next;
    }
    return symbolTable;
}

void printSymbolTable(struct symbol* symbolTable) {
    while (symbolTable != NULL) {
        printf("varName: %s\n", symbolTable->varName);
        printf("type: %d\n", symbolTable->type->code);
        printf("pointer depth: %d\n", symbolTable->type->depth);
        printf("binding: %d\n", symbolTable->binding);
        symbolTable = symbolTable->next;
    }
}

