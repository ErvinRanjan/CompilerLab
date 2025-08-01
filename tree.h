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
    struct tNode* left, * right;
};

struct tNode* createLeafNode(int val, char* varName, int type);
struct tNode* createOperatorNode(int nodeType, struct tNode* left, struct tNode* right);

#endif