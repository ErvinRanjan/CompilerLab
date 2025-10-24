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
#include "codegen.h"

extern bool isLeaf(int nodeType);

void typeCheckForArray(struct tNode* braceRoot, struct symbol* symbolTable, int classIndex) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        struct type* type = typeCheck(braceRoot, symbolTable, classIndex);
        if (type->code != LEAF_TYPE_INT || type->depth != 0) {
            printf("Error: non int type in within braces in array\n");
            exit(EXIT_FAILURE);
        }
    }

    typeCheckForArray(braceRoot->left, symbolTable, classIndex);
    typeCheckForArray(braceRoot->middle, symbolTable, classIndex);
}

int max(int x, int y) {
    return x > y ? x : y;
}

int getArrayDepth(struct tNode* braceRoot) {
    return braceRoot == NULL || braceRoot->nodeType != OP_BRACELIST ? braceRoot != NULL : 1 + max(getArrayDepth(braceRoot->left), getArrayDepth(braceRoot->right));
}

struct type* createPrimitiveType(int code, int depth) {
    struct type* t = malloc(sizeof(struct type));
    t->code = code;
    t->depth = depth;
    t->typename = NULL;
    return t;
}

struct type* createUserDefinedTypeWithName(char* typename) {
    struct type* t = malloc(sizeof(struct type));
    t->code = -2; // user defined types equal -2 , undefined equal -1
    t->depth = 0;
    t->typename = safeStrcpy(typename);
    return t;
}

struct type* createUserDefinedTypeWithDepth(char* typename, int depth) {
    struct type* t = createUserDefinedTypeWithName(typename);
    t->depth = depth;
    return t;
}

struct type* createType(char* typename, int code, int depth) {
    struct type* t = createUserDefinedTypeWithName(typename);
    t->depth = depth;
    t->code = code;
    return t;
}

int handleInheritance(char* leftTypeName, char* middleTypeName) {
    struct typeTable* leftTypeTable = getTypeTableWithName(leftTypeName);
    if (leftTypeTable == NULL) return 0;
    struct typeTable* middleTypeTable = getTypeTableWithName(middleTypeName);
    if (middleTypeName == NULL) return 0;
    struct typeTable* temp = middleTypeTable;
    while (temp != NULL && temp->parent != leftTypeTable) {
        temp = temp->parent;
    }
    if (temp == NULL) return 0;
    return leftTypeTable->isClass && middleTypeTable->isClass;
}

struct type* validateOperatorType(struct tNode* node, struct type* typeLeft, struct type* typeMiddle, struct symbol* symbolTable, int classIndex) {
    int nodeType = node->nodeType;
    switch (nodeType) {
    case OP_ASSIGN: {
        if (((typeLeft->code == LEAF_TYPE_INT || typeLeft->depth != 0) && (typeMiddle->code == LEAF_TYPE_INT || typeMiddle->depth != 0)) // pointer-int
            || (typeLeft->typename != NULL && typeLeft->typename == typeMiddle->typename) // primitive-user
            || (typeLeft->code == typeMiddle->code)
            || handleInheritance(typeLeft->typename, typeMiddle->typename)) { // primitive-non-user
            return createPrimitiveType(-1, 0);
        }
        printf("Type Mismatch\n");
        exit(EXIT_FAILURE);
    }
    case OP_ADD:
    case OP_SUB:
    case OP_MUL:
    case OP_DIV:
    case OP_MOD:
        if (typeLeft->code == LEAF_TYPE_INT && typeMiddle->code == LEAF_TYPE_INT) {
            return createPrimitiveType(LEAF_TYPE_INT, typeLeft->depth);
        }
        printf("Error: Type Mismatch\n");
        exit(EXIT_FAILURE);
        break;
    case OP_GT:
    case OP_LT:
    case OP_GE:
    case OP_LE:
    case OP_EQ:
    case OP_NE:
        if ((typeLeft->code == LEAF_TYPE_INT || typeLeft->depth != 0) && (typeMiddle->code == LEAF_TYPE_INT || typeMiddle->depth != 0)) {
            return createPrimitiveType(-1, 0);
        }
        printf("Error: Type Mismatch\n");
        exit(EXIT_FAILURE);
    case OP_REF:
        return typeLeft->typename == NULL ? createPrimitiveType(typeLeft->code, typeLeft->depth + 1) : createUserDefinedTypeWithDepth(typeLeft->typename, typeLeft->depth + 1);
    case OP_DREF:
        if (typeLeft->depth == 0) {
            printf("Error: cannot dereference primitive types\n");
            exit(EXIT_FAILURE);
        }
        return typeLeft->typename == NULL ? createPrimitiveType(typeLeft->code, typeLeft->depth - 1) : createUserDefinedTypeWithDepth(typeLeft->typename, typeLeft->depth - 1);
    case OP_ALLOC: {
        struct type* type = typeCheck(node->left, symbolTable, classIndex);
        if (type->depth == 0) {
            printf("Error : type must be a pointer\n");
            exit(EXIT_FAILURE);
        }
        if (getTypeSize(type) > 8) {
            printf("Error: user defined types are only allowed 8 fields of memory\n");
            exit(EXIT_FAILURE);
        }
        break;
    }
    case OP_FREE: {
        struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("Error : variable %s has not been declared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
    }
    default:
    }

    return createPrimitiveType(-1, 0);
}

void validateFunctionParamsHelper(struct tNode* argList, struct param** paramList, struct symbol* symbolTable, char* varName, int classIndex) {
    if (argList == NULL) return;
    if ((*paramList) == NULL) {
        printf("Error: number of arguments does not match the declaration: %s\n", varName);
        exit(EXIT_FAILURE);
    }

    if (argList->nodeType != OP_ARGLIST) {
        struct type* type = typeCheck(argList, symbolTable, classIndex);
        if (!isTypeEqual((*paramList)->type, type)) {
            printf("Error: Type Mismatch between arguments of function call and function declaration for function: %s\n", varName);
            exit(EXIT_FAILURE);
        }
        *paramList = (*paramList)->next;
        return;
    }

    validateFunctionParamsHelper(argList->left, paramList, symbolTable, varName, classIndex);
    validateFunctionParamsHelper(argList->middle, paramList, symbolTable, varName, classIndex);
}

void validateFunctionParams(struct tNode* argList, struct param* paramList, struct symbol* symbolTable, char* varName, int classIndex) {
    validateFunctionParamsHelper(argList, &paramList, symbolTable, varName, classIndex);
    if (paramList != NULL) {
        printf("Error: number of arguments does not match the declaration: %s\n", varName);
        exit(EXIT_FAILURE);
    }
}

struct type* validateLeafType(struct tNode* node, struct symbol* symbolTable, int classIndex) {
    struct symbol* symbol;
    struct param* param;
    switch (node->nodeType) {
    case LEAF_ID: {
        symbol = getSymbolTable(node->varName, symbolTable);
        if (symbol == NULL) {
            printf("Error: variable %s has not been declared\n", node->varName);
            exit(EXIT_FAILURE);
        }
        return symbol->type;
    }
    case LEAF_NUM:
        return createPrimitiveType(LEAF_TYPE_INT, 0);
    case LEAF_ARR:
        typeCheckForArray(node->middle, symbolTable, classIndex);
        struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("variable %s is undeclared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        int d = getArrayDepth(node->middle);
        if (d > sym->type->depth) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        return createType(sym->type->typename, sym->type->code, sym->type->depth - d);
    case LEAF_STR:
        return createPrimitiveType(LEAF_TYPE_STR, 0);
    case LEAF_TYPE_INT:
        return createPrimitiveType(LEAF_TYPE_INT, 0);
    case LEAF_TYPE_STR:
        return createPrimitiveType(LEAF_TYPE_STR, 0);
    case LEAF_FUNC: {
        struct param* paramList = NULL;
        paramList = convertArgTreeToParamList(node->middle, paramList, symbolTable, classIndex);
        symbol = getFSymbol(node->left->varName, paramList, symbolTable);
        if (symbol == NULL) {
            printf("Error: function is called but not declared for function : %s\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        validateFunctionParams(node->middle, symbol->paramList, symbolTable, node->left->varName, classIndex);
        return symbol->type;
    }
    case LEAF_TUPLE_ACCESS: {
        if (node->left->nodeType == LEAF_SELF) {
            if (classIndex == -1) {
                printf("Error : self cannot be used outside a class\n");
                exit(EXIT_FAILURE);
            }
            else {
                struct typeTable* classContext = getClassTableWithIndex(classIndex);
                struct symbol* symbol = getSymbolTable(node->middle->varName, classContext->symbolList);
                if (symbol == NULL) {
                    printf("Error: No such field exists for the class: %s\n", classContext->name);
                    exit(EXIT_FAILURE);
                }
                return symbol->type;
            }
        }
        node->left->type = typeCheck(node->left, symbolTable, classIndex);
        struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
        if (typeTable == NULL) {
            printf("Error: type is used but not declared: %s\n", node->left->type->typename);
            exit(EXIT_FAILURE);
        }
        if (typeTable->isClass && classIndex != typeTable->classIndex) {
            printf("Error : cannot access class members outside class, class is private\n");
            exit(EXIT_FAILURE);
        }
        if (typeTable->isClass) {
            struct symbol* symbol = getSymbolTable(node->middle->varName, typeTable->symbolList);
            if (symbol == NULL) {
                printf("Error : no such field : %s exists for class : %s\n", node->middle->varName, typeTable->name);
                exit(EXIT_FAILURE);
            }
            return symbol->type;
        }
        struct param* param = getParam(typeTable->paramList, node->middle->varName);
        if (param == NULL) {
            printf("Error: type %s does not have a field %s\n", node->left->type->typename, node->middle->varName);
            exit(EXIT_FAILURE);
        }
        return param->type;
    }
    case LEAF_METHOD: {
        if (node->left->nodeType == LEAF_SELF) {
            if (classIndex == -1) {
                printf("Error : self cannot be used outside a class\n");
                exit(EXIT_FAILURE);
            }
            else {
                struct typeTable* classContext = getClassTableWithIndex(classIndex);
                struct param* paramList = NULL;
                paramList = convertArgTreeToParamList(node->right, paramList, symbolTable, classIndex);
                struct symbol* symbol = getFSymbol(node->middle->varName, paramList, classContext->symbolList);
                if (symbol == NULL) {
                    printf("Error: No such field exists for the class: %s\n", classContext->name);
                    exit(EXIT_FAILURE);
                }
                validateFunctionParams(node->right, symbol->paramList, symbolTable, node->middle->varName, classIndex);
                return symbol->type;
            }
        }
        node->left->type = typeCheck(node->left, symbolTable, classIndex);
        struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
        if (typeTable == NULL) {
            printf("Error: class is used but not declared: %s\n", node->left->type->typename);
            exit(EXIT_FAILURE);
        }
        if ((typeTable->isClass) == 0) {
            printf("Error : user defined types cannot invoke methods: %s\n", typeTable->name);
            exit(EXIT_FAILURE);
        }
        struct param* paramList = NULL;
        paramList = convertArgTreeToParamList(node->right, paramList, symbolTable, classIndex);
        struct symbol* symbol = getFSymbol(node->middle->varName, paramList, typeTable->symbolList);
        if (symbol == NULL) {
            printf("Error: No such method exists for the class: %s\n", typeTable->name);
            exit(EXIT_FAILURE);
        }
        validateFunctionParams(node->right, symbol->paramList, symbolTable, node->middle->varName, classIndex);
        return symbol->type;
    }
    case LEAF_NEW: {
        struct type* type = typeCheck(node->left, symbolTable, classIndex);
        struct typeTable* typeTable = getTypeTableWithName(type->typename);
        if (typeTable == NULL || !(typeTable->isClass) || (strcmp(typeTable->name, node->middle->varName) != 0 && !handleInheritance(typeTable->name, node->middle->varName)) || type->depth != 1) {
            printf("Error: Type Mismatch\n");
            exit(EXIT_FAILURE);
        }
        break;
    }
    default:
    }
    return createPrimitiveType(-1, 0);
}

struct type* typeCheck(struct tNode* root, struct symbol* symbolTable, int classIndex) {
    if (root == NULL) return createPrimitiveType(-1, 0);

    if (isLeaf(root->nodeType)) {
        root->type = validateLeafType(root, symbolTable, classIndex);
        return root->type;
    }

    struct type* typeLeft = typeCheck(root->left, symbolTable, classIndex);
    struct type* typeMiddle = typeCheck(root->middle, symbolTable, classIndex);

    root->type = validateOperatorType(root, typeLeft, typeMiddle, symbolTable, classIndex);
    return root->type;
}

void typeCheckFunctionParam(struct type* type, char* varName, struct tNode* paramRoot, struct symbol* symbolTable) {
    int numberOfParam = 0;
    struct param* paramList = NULL;
    paramList = convertTreeToParamList(paramRoot, &numberOfParam, paramList);
    struct symbol* sym = getFSymbol(varName, paramList, symbolTable);
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
    return t1 != NULL && t2 != NULL && (t1->code == t2->code || (t1->typename != NULL && t2->typename != NULL && strcmp(t1->typename, t2->typename) == 0)) && t1->depth == t2->depth;
}

