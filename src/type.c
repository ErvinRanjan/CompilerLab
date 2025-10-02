#include "type.h"
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "symbol.h"
#include "param.h"
#include "utils.h"
#include "typeTable.h"

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

    typeCheckForArray(braceRoot->left, symbolTable);
    typeCheckForArray(braceRoot->middle, symbolTable);
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
    t->typename = NULL;
    return t;
}

struct type* createUserDefinedType(char* typename) {
    struct type* t = malloc(sizeof(struct type));
    t->code = -2; // user defined types equal -2 , undefined equal -1
    t->depth = 0;
    t->typename = safeStrcpy(typename);
    return t;
}

struct type* createUserDefinedTypeWithDepth(char* typename, int depth) {
    struct type* t = createUserDefinedType(typename);
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
        if (
            (typeLeft->typename != NULL
                && typeMiddle->typename != NULL
                && strcmp(typeLeft->typename, typeMiddle->typename) != 0)
            || typeLeft->code != typeMiddle->code
            || typeLeft->depth != typeMiddle->depth) {
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

void validateFunctionParamsHelper(struct tNode* argList, struct param** paramList, struct symbol* symbolTable, char* varName) {
    if (argList == NULL) return;
    if ((*paramList) == NULL) {
        printf("Error: number of arguments does not match the declaration: %s\n", varName);
        exit(EXIT_FAILURE);
    }

    if (argList->nodeType != OP_ARGLIST) {
        struct type* type = typeCheck(argList, symbolTable);
        if (!isTypeEqual((*paramList)->type, type)) {
            printf("Error: Type Mismatch between arguments of function call and function declaration for function: %s\n", varName);
            exit(EXIT_FAILURE);
        }
        *paramList = (*paramList)->next;
        return;
    }

    validateFunctionParamsHelper(argList->left, paramList, symbolTable, varName);
    validateFunctionParamsHelper(argList->middle, paramList, symbolTable, varName);
}

void validateFunctionParams(struct tNode* argList, struct param* paramList, struct symbol* symbolTable, char* varName) {
    validateFunctionParamsHelper(argList, &paramList, symbolTable, varName);
    if (paramList != NULL) {
        printf("Error: number of arguments does not match the declaration: %s\n", varName);
        exit(EXIT_FAILURE);
    }
}

struct type* validateLeafType(struct tNode* node, struct symbol* symbolTable) {
    struct symbol* symbol;
    struct param* param;
    switch (node->nodeType) {
    case LEAF_ID:
        symbol = getSymbolTable(node->varName, symbolTable);
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
        return createType(sym->type->code, 0);
    case LEAF_STR:
        return createType(LEAF_TYPE_STR, 0);
    case LEAF_TYPE_INT:
        return createType(LEAF_TYPE_INT, 0);
    case LEAF_TYPE_STR:
        return createType(LEAF_TYPE_STR, 0);
    case LEAF_FUNC:
        symbol = getSymbolTable(node->left->varName, symbolTable);
        if (symbol == NULL) {
            printf("Error: function is called but not declared for function : %s\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        validateFunctionParams(node->middle, symbol->paramList, symbolTable, node->left->varName);
        return symbol->type;
    case LEAF_TUPLE_ACCESS: {
        struct symbol* symbol = getSymbolTable(node->left->varName, symbolTable);
        if (symbol == NULL) {
            printf("Error: variable %s has not been declared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        struct typeTable* typeTable = getTypeTableWithName(symbol->type->typename);
        if (typeTable == NULL) {
            printf("Error: type is used but not declared: %s\n", symbol->type->typename);
            exit(EXIT_FAILURE);
        }
        struct param* param = getParam(typeTable->paramList, node->middle->varName);
        if (param == NULL) {
            printf("Error: type %s does not have a field %s\n", symbol->type->typename, node->middle->varName);
            exit(EXIT_FAILURE);
        }
        return param->type;
    }
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

void typeCheckFunctionParam(struct type* type, char* varName, struct tNode* paramRoot, struct symbol* symbolTable) {
    int numberOfParam = 0;
    struct param* paramList = NULL;
    paramList = convertTreeToParamList(paramRoot, &numberOfParam, paramList);
    struct symbol* sym = getSymbolTable(varName, symbolTable);
    if (sym == NULL) {
        printf("Error: function %s has not been declared\n", varName);
        exit(EXIT_FAILURE);
    }
    if (!isTypeEqual(sym->type, type)) {
        printf("Type Mismatch between return types of function declaration and definition for function : %s\n", varName);
        exit(EXIT_FAILURE);
    }
    struct param* p = sym->paramList;
    while (p != NULL && paramList != NULL) {
        if (!isTypeEqual(p->type, paramList->type)) {
            printf("Error: Type Mismatch between param types of function declaration and definition for function : %s\n", varName);
            exit(EXIT_FAILURE);
        }
        p = p->next;
        paramList = paramList->next;
    }
    if (p != NULL || paramList != NULL) {
        printf("Error: Number of arguments between function declaration and function definition don't match for function : %s\n", varName);
        exit(EXIT_FAILURE);
    }
}

int isTypeEqual(struct type* t1, struct type* t2) {
    return t1 != NULL && t2 != NULL && t1->code == t2->code && t1->depth == t2->depth;
}

