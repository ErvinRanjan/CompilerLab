#include "symbol.h"
#include "mem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct symbol* createSymbol(int type, char* varName, int size, int binding) {
    struct symbol* sym = malloc(sizeof(struct symbol));
    sym->type = type;
    strncpy(sym->varName, varName, strlen(varName));
    sym->size = size;
    sym->binding = binding;
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

struct symbol* populateSymbolTableGivenVarList(struct tNode* varRoot, struct symbol* symbolTable, int type) {
    if (varRoot == NULL) return symbolTable;

    // leaf
    if (varRoot->left == NULL && varRoot->middle == NULL && varRoot->right == NULL) {
        return addSymbol(symbolTable, createSymbol(type, varRoot->varName, 1, getFreeMem(1)));
    }

    symbolTable = populateSymbolTableGivenVarList(varRoot->left, symbolTable, type);
    symbolTable = populateSymbolTableGivenVarList(varRoot->middle, symbolTable, type);
    symbolTable = populateSymbolTableGivenVarList(varRoot->right, symbolTable, type);

    return symbolTable;
}

struct symbol* populateSymbolTable(struct tNode* declRoot, struct symbol* symbolTable) {
    if (declRoot == NULL) {
        return symbolTable;
    }

    if (declRoot->nodeType == OP_DECL) {
        int type = declRoot->left->type;
        symbolTable = populateSymbolTableGivenVarList(declRoot->middle, symbolTable, type);
        return symbolTable;
    }

    symbolTable = populateSymbolTable(declRoot->left, symbolTable);
    symbolTable = populateSymbolTable(declRoot->middle, symbolTable);
    symbolTable = populateSymbolTable(declRoot->right, symbolTable);

    return symbolTable;
}

struct symbol* getSymbolTable(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return NULL;
    while (symbolTable != NULL && strcmp(varName, symbolTable->varName) != 0) {
        symbolTable = symbolTable->next;
    }
    return symbolTable;
}

