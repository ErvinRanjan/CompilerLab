#include "type.h"
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "symbol.h"

extern bool isLeaf(int nodeType);

void typeCheckForArray(struct tNode* braceRoot, struct symbol* symbolTable) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        struct type* type = typeCheck(braceRoot, symbolTable);
        if (type->code != LEAF_TYPE_INT || type->depth != 0) {
            printf("Error: non int type in within braces in array\n");
            exit(EXIT_FAILURE);
        }
    }

    typeCheck(braceRoot->left, symbolTable);
    typeCheck(braceRoot->middle, symbolTable);
}

int max(int x, int y) {
    return x > y ? x : y;
}

int getArrayDepth(struct tNode* braceRoot) {
    return braceRoot == NULL || braceRoot->nodeType != OP_BRACELIST ? braceRoot != NULL : 1 + max(getArrayDepth(braceRoot->left), getArrayDepth(braceRoot->right));
}

struct type* createType(int code, int depth) {
    struct type* t = malloc(sizeof(struct type));
    t->code = code;
    t->depth = depth;
    return t;
}

struct type* validateOperatorType(int nodeType, struct type* typeLeft, struct type* typeMiddle) {
    switch (nodeType) {
    case OP_ADD:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createType(LEAF_TYPE_INT, 0);
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_SUB:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createType(LEAF_TYPE_INT, 0);
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_MUL:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createType(LEAF_TYPE_INT, 0);
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_DIV:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createType(LEAF_TYPE_INT, 0);
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_MOD:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createType(LEAF_TYPE_INT, 0);
        }
        else {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
    case OP_ASSIGN:
        if (typeLeft->code != typeMiddle->code || typeLeft->depth != typeMiddle->depth) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_GT:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_LT:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_GE:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_LE:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_EQ:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_NE:
        if (typeLeft->code != LEAF_TYPE_INT || typeMiddle->code != LEAF_TYPE_INT) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(-1, 0);
    case OP_REF:
        return createType(typeLeft->code, typeLeft->depth + 1);
    case OP_DREF:
        return createType(typeLeft->code, typeLeft->depth - 1);
    default:
    }
    return createType(-1, 0);
}

struct type* validateLeafType(struct tNode* node, struct symbol* symbolTable) {
    switch (node->nodeType) {
    case LEAF_ID:
        struct symbol* symbol = getSymbolTable(node->varName, symbolTable);
        if (symbol == NULL) {
            printf("Error: variable %s has not been declared\n", node->varName);
            exit(EXIT_FAILURE);
        }
        return symbol->type;
    case LEAF_NUM:
        return createType(LEAF_TYPE_INT, 0);
    case LEAF_ARR:
        typeCheckForArray(node->middle, symbolTable);
        struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("variable %s is undeclared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        if (getArrayDepth(node->middle) != sym->type->depth) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return sym->type;
    case LEAF_STR:
        return createType(LEAF_TYPE_STR, 0);
    case LEAF_TYPE_INT:
        return createType(LEAF_TYPE_INT, 0);
    case LEAF_TYPE_STR:
        return createType(LEAF_TYPE_STR, 0);
    default:
    }
    return createType(-1, 0);
}

struct type* typeCheck(struct tNode* root, struct symbol* symbolTable) {
    if (root == NULL) return createType(-1, 0);

    if (isLeaf(root->nodeType)) {
        return validateLeafType(root, symbolTable);
    }

    struct type* typeLeft = typeCheck(root->left, symbolTable);
    struct type* typeMiddle = typeCheck(root->middle, symbolTable);

    return validateOperatorType(root->nodeType, typeLeft, typeMiddle);
}