/**
 * @brief header file to handle tree creation
 */

#ifndef TNODE_H
#define TNODE_H

#include "constants.h"
#include "symbol.h"
#include "type.h"

struct tNode {
    int val;
    struct type* type;
    char varName[MAX_VARNAME_LEN];
    char stringVal[MAX_CSTR_LEN];
    int nodeType;
    int label;
    struct symbol* symbolTableEntry;
    struct tNode* left, * middle, * right;
};

struct tNode* createLeafNode(int val, char* varName, struct type* type, int label, int nodeType, char* stringVal);
struct tNode* createOperatorNode(int nodeType, struct tNode* left, struct tNode* middle, struct tNode* right, int label);

#endif