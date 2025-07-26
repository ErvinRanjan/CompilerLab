#include "tree.h"
#include <stdlib.h>
#include <string.h>


struct tNode* createLeafNode(int val) {
    struct tNode* newNode = malloc(sizeof(struct tNode));
    newNode->val = val;
    newNode->isLeaf = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tNode* createOperatorNode(char* op, struct tNode* left, struct tNode* right) {
    struct tNode* newNode = malloc(sizeof(struct tNode));
    newNode->isLeaf = 0;
    strncpy(newNode->op, op, strlen(op));
    newNode->left = left;
    newNode->right = right;
    return newNode;
}