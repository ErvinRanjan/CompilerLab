#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include "param.h"
#include "type.h"

struct typeTable {
    char name[100];
    struct param* paramList;
    int size;
    struct typeTable* next;
};

struct typeTable* getTypeTable();
void setTypeTable(struct typeTable* typeTable);
struct typeTable* createTypeTable(char* name, struct param* paramList);
void addTypeTable(struct typeTable* typeTable);
void printTypeTable();
struct typeTable* getTypeTableWithName(char* name);
int getTypeSize(struct type* type);
void populateTypeTable(char* typename, struct param* paramList);
int getFieldOffset(char* fieldName, struct param* paramList);

#endif