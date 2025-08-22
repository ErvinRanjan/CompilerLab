#include "type.h"
#include "constants.h"
#include "stdlib.h"
#include <stdio.h>
#include <stdbool.h>

extern bool isLeaf(int nodeType);

int validateOperatorType(int nodeType, int typeLeft, int typeMiddle) {
    switch (nodeType) {
    case OP_ADD:
        if (typeLeft == LEAF_TYPE_INT && typeMiddle == LEAF_TYPE_INT) {
            return LEAF_TYPE_INT;
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_SUB:
        if (typeLeft == LEAF_TYPE_INT && typeMiddle == LEAF_TYPE_INT) {
            return LEAF_TYPE_INT;
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_MUL:
        if (typeLeft == LEAF_TYPE_INT && typeMiddle == LEAF_TYPE_INT) {
            return LEAF_TYPE_INT;
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_DIV:
        if (typeLeft == LEAF_TYPE_INT && typeMiddle == LEAF_TYPE_INT) {
            return LEAF_TYPE_INT;
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_ASSIGN:
        if (typeLeft != typeMiddle) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_GT:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_LT:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_GE:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_LE:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_EQ:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    case OP_NE:
        if (typeLeft != LEAF_TYPE_INT || typeMiddle != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return -1;
    default:
    }
    return -1;
}

int validateLeafType(int nodeType, int type, char* varName, struct symbol* symbolTable) {
    switch (nodeType) {
    case LEAF_ID:
        struct symbol* symbol = getSymbolTable(varName, symbolTable);
        if (symbol == NULL) {
            printf("Error: variable %s has not been declared\n", varName);
            exit(EXIT_FAILURE);
        }
        return symbol->type;
    case LEAF_NUM:
        return LEAF_TYPE_INT;
    case LEAF_STR:
        return LEAF_TYPE_STR;
    case LEAF_TYPE_INT:
        return LEAF_TYPE_INT;
    case LEAF_TYPE_STR:
        return LEAF_TYPE_STR;
    default:
    }
    return -1;
}

int typeCheck(struct tNode* root, struct symbol* symbolTable) {
    if (root == NULL) return -1;

    if (isLeaf(root->nodeType)) {
        return validateLeafType(root->nodeType, root->type, root->varName, symbolTable);
    }

    int typeLeft = typeCheck(root->left, symbolTable);
    int typeMiddle = typeCheck(root->middle, symbolTable);

    return validateOperatorType(root->nodeType, typeLeft, typeMiddle);
}