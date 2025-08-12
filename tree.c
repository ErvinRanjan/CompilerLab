#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "constants.h"

/**
 * @brief acts as a constructor for tNode
 */
struct tNode* createNode(int val, int nodeType, char* varName, int type, struct tNode* left, struct tNode* right, struct tNode* middle, int label) {
    struct tNode* newNode = malloc(sizeof(struct tNode));
    newNode->val = val;
    newNode->nodeType = nodeType;
    if (varName != NULL) {
        if (strlen(varName) >= MAX_VARNAME_LEN) {
            printf("Error: varName is greater than MAX_VARNAME_LEN - %d", MAX_VARNAME_LEN);
            exit(EXIT_FAILURE);
        }
        else {
            strncpy(newNode->varName, varName, strlen(varName));
        }
    }
    newNode->type = type;
    newNode->left = left;
    newNode->right = right;
    newNode->middle = middle;
    newNode->label = label;
    return newNode;
}

/**
 * @brief creates leafNode given params
 */
struct tNode* createLeafNode(int val, char* varName, int type, int label, int nodeType) {
    return createNode(val, nodeType, varName, type, NULL, NULL, NULL, label);
}

/**
 * @brief creates operatorNode given params
 */
struct tNode* createOperatorNode(int opCode, struct tNode* left, struct tNode* middle, struct tNode* right, int label) {
    return createNode(0, opCode, NULL, 0, left, right, middle, label);
}