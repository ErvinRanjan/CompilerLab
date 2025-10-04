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

struct typeTable* createTypeTable(char* name, struct param* paramList) {
    struct typeTable* typeTable = malloc(sizeof(struct typeTable));
    if (name == NULL || strlen(name) >= 100) {
        printf("Error: could not create type table entry, either type-name is null or type-name is too long\n");
        exit(EXIT_FAILURE);
    }
    strcpy(typeTable->name, name);
    typeTable->paramList = paramList; // passing ref, no deep copy
    while (paramList != NULL) {
        typeTable->size = typeTable->size + getTypeSize(paramList->type);
        paramList = paramList->next;
    }
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

void addTypeTable(struct typeTable* typeTable) {
    if (getTypeTable() == NULL) {
        setTypeTable(typeTable);
        return;
    }
    struct typeTable* head = getTypeTable();
    while (head->next != NULL) {
        if (strcmp(head->name, typeTable->name) == 0) {
            printf("Error: type cannot be redeclared: %s\n", typeTable->name);
            exit(EXIT_FAILURE);
        }
        head = head->next;
    }
    if (strcmp(head->name, typeTable->name) == 0) {
        printf("Error: type cannot be redeclared: %s\n", typeTable->name);
        exit(EXIT_FAILURE);
    }
    head->next = typeTable;
}

void printTypeTable() {
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        printf("typename: %s\n", head->name);
        printParamList(head->paramList);
        printf("size : %d\n", head->size);
        head = head->next;
    }
}

void populateTypeTable(char* typename, struct param* paramList) {
    addTypeTable(createTypeTable(typename, paramList));
}

void updateTypeTable(char* typename, struct param* paramList) {
    struct typeTable* head = getTypeTable();
    while (head != NULL) {
        if (strcmp(typename, head->name) == 0) {
            head->paramList = paramList;
            break;
        }
        head = head->next;
    }
}

int getFieldOffset(char* fieldName, struct param* paramList) {
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

struct type* getFieldType(char* fieldName, struct param* paramList) {
    while (paramList != NULL) {
        if (strcmp(fieldName, paramList->name) == 0) {
            return paramList->type;
        }
        paramList = paramList->next;
    }
    return NULL;
}