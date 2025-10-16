#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include "param.h"
#include "type.h"
#include "symbol.h"

struct typeTable {
    char name[100];
    struct param* paramList;
    struct symbol* symbolList;
    int size;
    struct typeTable* parent;
    struct typeTable* next;
    int isClass;
    int classIndex;
};

struct typeTable* getTypeTable();
void setTypeTable(struct typeTable* typeTable);
struct typeTable* createTypeTable(char* name, int isClass);
int addTypeTable(struct typeTable* typeTable);
void printTypeTable();
void printClassTable();
struct typeTable* getTypeTableWithName(char* name);
int getTypeSize(struct type* type);
int populateTypeTable(char* typename, int isClass);
int getFieldOffset(char* fieldName, struct typeTable* typeTable);
struct type* getFieldType(char* fieldName, struct param* paramList);
void updateTypeTable(char* typename, struct param* paramList, struct symbol* symbolList);
struct typeTable* getClassTableWithIndex(int classIndex);

#endif