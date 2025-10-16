#include "typeTable.h"
#include <stdlib.h>
#include <string.h>

struct typeTable* typeTableList = NULL;

void setTypeTable(struct typeTable* typeTable) {
    typeTableList = typeTable;
}

struct typeTable* getTypeTable() {
    return typeTableList;
}

struct typeTable* createTypeTable(char* name, int isClass) {
    struct typeTable* typeTable = malloc(sizeof(struct typeTable));
    if (name == NULL || strlen(name) >= 100) {
        printf("Error: could not create type table entry, either type-name is null or type-name is too long\n");
        exit(EXIT_FAILURE);
    }
    strcpy(typeTable->name, name);
    typeTable->isClass = isClass;
    typeTable->parent = NULL;
    return typeTable;
}


struct typeTable* getTypeTableWithName(char* name) {
    if (name == NULL) return NULL;
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int getTypeSize(struct type* type) {
    if (type->typename == NULL || type->depth != 0) return 1;
    struct typeTable* typeTable = getTypeTableWithName(type->typename);
    if (typeTable == NULL) {
        printf("Error: could not find type\n");
        exit(EXIT_FAILURE);
    }
    return typeTable->size;
}

int addTypeTable(struct typeTable* typeTable) {
    if (getTypeTable() == NULL) {
        setTypeTable(typeTable);
        return 0;
    }
    struct typeTable* head = getTypeTable();
    int index = 0;
    while (head->next != NULL) {
        if (strcmp(head->name, typeTable->name) == 0) {
            printf("Error: type cannot be redeclared: %s\n", typeTable->name);
            exit(EXIT_FAILURE);
        }
        head = head->next;
        index++;
    }
    if (strcmp(head->name, typeTable->name) == 0) {
        printf("Error: type cannot be redeclared: %s\n", typeTable->name);
        exit(EXIT_FAILURE);
    }
    head->next = typeTable;
    typeTable->classIndex = index + 1;
    return typeTable->classIndex;
}

void printTypeTable() {
    printf("===  TypeTable  ===\n");
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        printf("typename: %s\n", head->name);
        printParamList(head->paramList);
        printf("size : %d\n", head->size);
        head = head->next;
    }
    printf("=== === ===\n");
}

int populateTypeTable(char* typename, int isClass) {
    return addTypeTable(createTypeTable(typename, isClass));
}

void updateTypeTable(char* typename, struct param* paramList, struct symbol* symbolList) {
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        if (strcmp(typename, head->name) == 0) {
            head->paramList = paramList;
            head->size = 0;
            if (head->isClass) {
                head->symbolList = symbolList;
                while (symbolList != NULL) {
                    if (symbolList->type->typename != NULL && strcmp(symbolList->type->typename, typename) == 0 && symbolList->type->depth == 0) {
                        printf("Error: cannot self reference a incomplete type as a non pointer\n");
                        exit(EXIT_FAILURE);
                    }
                    head->size += getTypeSize(symbolList->type);
                    symbolList = symbolList->next;
                }
            }
            else {
                while (paramList != NULL) {
                    if (paramList->type->typename != NULL && strcmp(paramList->type->typename, typename) == 0 && paramList->type->depth == 0) {
                        printf("Error: cannot self reference a incomplete type as a non pointer\n");
                        exit(EXIT_FAILURE);
                    }
                    head->size += getTypeSize(paramList->type);
                    paramList = paramList->next;
                }
            }
            break;
        }
        head = head->next;
    }
}

int getFieldOffset(char* fieldName, struct typeTable* typeTable) {
    if (typeTable->isClass) {
        return getFieldOffsetForClasses(fieldName, typeTable->symbolList);
    }
    struct param* paramList = typeTable->paramList;
    int size = 0;
    while (paramList != NULL) {
        if (strcmp(fieldName, paramList->name) == 0) {
            return size;
        }
        size += getTypeSize(paramList->type);
        paramList = paramList->next;
    }
    return size;
}

int getFieldOffsetForClasses(char* fieldName, struct symbol* symbolList) {
    int size = 0;
    while (symbolList != NULL) {
        if (strcmp(fieldName, symbolList->varName) == 0) {
            return size;
        }
        size += getTypeSize(symbolList->type);
        symbolList = symbolList->next;
    }
    return size;
}

struct type* getFieldType(char* fieldName, struct param* paramList) {
    while (paramList != NULL) {
        if (strcmp(fieldName, paramList->name) == 0) {
            return paramList->type;
        }
        paramList = paramList->next;
    }
    return NULL;
}

void printClassTable() {
    printf("===  ClassTable ===\n");
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        if (head->isClass) {
            printSymbolTable(head->name, head->symbolList);
            printf("size : %d\n", head->size);
        }
        head = head->next;
    }
    printf("=== === ===\n");
}

struct typeTable* getClassTableWithIndex(int classIndex) {
    struct typeTable* typeTable = getTypeTable();
    while (typeTable != NULL) {
        if (typeTable->classIndex == classIndex) {
            return typeTable;
        }
        typeTable = typeTable->next;
    }
    return NULL;
}