/**
 * @brief header file to handle tree creation
 */

#ifndef TNODE_H
#define TNODE_H

#include "constants.h"

struct tNode {
    int val;
    int type;
    char varName[MAX_VARNAME_LEN];
    int nodeType;
    int label;
    struct tNode* left, * middle, * right;
};

struct tNode* createLeafNode(int val, char* varName, int type, int label, int nodeType);
struct tNode* createOperatorNode(int nodeType, struct tNode* left, struct tNode* middle, struct tNode* right, int label);

#endif