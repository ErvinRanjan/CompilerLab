#include "codegen.h"
#include "reg.h"
#include "constants.h"
#include "mem.h"
#include "label.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include "typeTable.h"
#include "eval.h"
#include "utils.h"

struct stack* beginLabelStack, * nextLabelStack; // keeps track of latest while begin and next labels
extern int getArrayDepth(struct tNode* braceRoot);

int getMethodLabel(struct symbol* classInstance, char* varName) {
    struct typeTable* typeTable = getTypeTableWithName(classInstance->type->typename);
    int offs = getFunctionOffset(typeTable->symbolList, varName);
    int baseBinding = classInstance->vFuncTableBaseBinding;
    return baseBinding + offs;
}

bool isLeaf(int nodeType) {
    return nodeType == LEAF_ID || nodeType == LEAF_NUM || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == LEAF_STR || nodeType == LEAF_TYPE_INT || nodeType == LEAF_TYPE_STR || nodeType == LEAF_ARR || nodeType == LEAF_FUNC || nodeType == LEAF_FDECL || nodeType == LEAF_TUPLE_ACCESS || nodeType == OP_INITIALISE || nodeType == OP_ALLOC || nodeType == OP_FREE || nodeType == LEAF_METHOD || nodeType == LEAF_NEW;
}

void resolveArrayAddrCodegen(FILE* out, struct tNode* braceRoot, struct symbol* symbolTable, int* base, char* fname, int classIndex) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        int reg = codeGenHelper(out, braceRoot, -1, NULL, symbolTable, fname, classIndex);
        cprintf(out, "MOV [%d], R%d\n", *base, reg);
        (*base) = (*base) + 1;
        return;
    }

    resolveArrayAddrCodegen(out, braceRoot->left, symbolTable, base, fname, classIndex);
    resolveArrayAddrCodegen(out, braceRoot->middle, symbolTable, base, fname, classIndex);
}

int resolveAddr(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname, int classIndex) {
    if (fname != NULL && (node->nodeType == LEAF_ID || node->nodeType == LEAF_TUPLE_ACCESS)) {
        return resolveAddrInFunction(out, node, symbolTable, fname, classIndex);
    }
    switch (node->nodeType) {
    case LEAF_ID:
        int reg = getFreeReg();
        cprintf(out, "MOV R%d, %d\n", reg, getMem(node->varName, symbolTable));
        return reg;
        break;
    case LEAF_ARR:
        return resolveArrayAddr(out, node, symbolTable, fname, classIndex);
        break;
    case LEAF_TUPLE_ACCESS: {
        struct typeTable* typeTable = getTypeTableWithName(typeCheck(node->left, symbolTable, classIndex)->typename);
        int base_reg = codeGenHelper(out, node->left, -1, NULL, symbolTable, fname, classIndex);
        int offs = getFieldOffset(node->middle->varName, typeTable);
        int reg = getFreeReg();
        cprintf(out, "MOV R%d, R%d\n", reg, base_reg);
        cprintf(out, "ADD R%d, %d\n", reg, offs);
        return reg;
    }
    default:
    }
    return -1;
}

int resolveArrayAddr(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname, int classIndex) {
    int depth = getArrayDepth(node->middle);
    int indices[100];
    int base = getFreeMem(depth);
    int x = base;
    resolveArrayAddrCodegen(out, node->middle, symbolTable, &x, fname, classIndex);
    struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
    int maxSizesBase = getFreeMem(depth);
    for (int i = 0;i < depth;i++) {
        cprintf(out, "MOV [%d], %d\n", maxSizesBase + i, sym->maxSizes[i]);
    }
    int maxi = base + depth;
    int addr_reg = getFreeReg();
    if (sym->symbolType == PRIMITIVE) {
        cprintf(out, "MOV R%d, [%d]\n", addr_reg, sym->binding);
    }
    else {
        cprintf(out, "MOV R%d, %d\n", addr_reg, sym->binding);
    }
    int prod_reg = getFreeReg();
    cprintf(out, "MOV R%d, %d\n", prod_reg, 1);
    int base_reg = getFreeReg();
    int maxSizesBase_reg = getFreeReg();
    cprintf(out, "MOV R%d, %d\n", base_reg, base);
    cprintf(out, "MOV R%d, %d\n", maxSizesBase_reg, maxSizesBase);
    int op_reg = getFreeReg();
    int label = getLabel();
    cprintf(out, "L%d:\n", label);
    cprintf(out, "MOV R%d, R%d\n", op_reg, prod_reg);
    int temp = getFreeReg();
    cprintf(out, "MOV R%d, [R%d]\n", temp, base_reg);
    cprintf(out, "MUL R%d, R%d\n", op_reg, temp);
    freeReg();
    cprintf(out, "ADD R%d, R%d\n", addr_reg, op_reg);
    cprintf(out, "MOV R%d, [R%d]\n", op_reg, maxSizesBase_reg);
    cprintf(out, "MUL R%d, R%d\n", prod_reg, op_reg);
    cprintf(out, "ADD R%d, %d\n", base_reg, 1);
    cprintf(out, "ADD R%d, %d\n", maxSizesBase_reg, 1);
    cprintf(out, "MOV R%d, %d\n", op_reg, maxi);
    cprintf(out, "EQ R%d, R%d\n", op_reg, base_reg);
    cprintf(out, "JZ R%d, L%d\n", op_reg, label);
    freeReg();
    freeReg();
    freeReg();
    freeReg();
    freeMem(2 * depth);
    return addr_reg;
}

bool isStmt(int nodeType) {
    return nodeType == OP_READ || nodeType == OP_WRITE || nodeType == OP_ASSIGN || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == OP_IF || nodeType == OP_WHILE || nodeType == OP_DO_WHILE || nodeType == OP_REPEAT_UNTIL || nodeType == OP_RETURN || nodeType == OP_ALLOC || nodeType == OP_INITIALISE || nodeType == OP_FREE || nodeType == LEAF_NEW;
}

int getMem(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return -1;

    struct symbol* sym = getSymbolTable(varName, symbolTable);

    return sym == NULL ? -1 : sym->binding;
}

void handleAssignForUserDefinedTypes(FILE* out, struct tNode* node, int addr_reg, struct symbol* symbolTable, char* fname, int classIndex) {
    struct type* type = typeCheck(node, symbolTable, classIndex);
    struct typeTable* typeTable = getTypeTableWithName(type->typename);
    if (typeTable == NULL) {
        printf("Error: type is used but not declared\n");
        exit(EXIT_FAILURE);
    }
    int base_reg = resolveAddr(out, node, symbolTable, fname, classIndex);
    struct param* paramList = typeTable->paramList;
    int size = 0;
    int reg1 = getFreeReg();
    int reg2 = getFreeReg();
    while (paramList != NULL) {
        int totalTypeSizeIncludingCur = size + getTypeSize(paramList->type);
        while (size < totalTypeSizeIncludingCur) {
            cprintf(out, "MOV R%d, R%d\n", reg1, base_reg);
            cprintf(out, "MOV R%d, R%d\n", reg2, addr_reg);
            cprintf(out, "ADD R%d, %d\n", reg1, size);
            cprintf(out, "ADD R%d, %d\n", reg2, size);
            cprintf(out, "MOV R%d, [R%d]\n", reg2, reg2);
            cprintf(out, "MOV [R%d], R%d\n", reg1, reg2);
            size++;
        }
        paramList = paramList->next;
    }
}

/**
 * @brief generates machine code for operators
 * @param out output file pointer
 * @param nodeType type of the node
 * @param reg1 register one
 * @param reg2 register two
 * @param reg3 register three
 * @param varName variable name in case of assigning or reading
 * @param label1 label one - points to self
 * @param label2 label two - points to true
 * @param label3 label three - points to false
 * @param next next instructions label
 * @param parentNodeType type of parent node
 */
void operatorCodeGen(FILE* out, struct tNode* node, int reg1, int reg2, int next, struct tNode* parent, struct symbol* symbolTable, char* fname, int classIndex) {
    int addr_reg = -1;
    int paramCount = getParamLenForFunction(fname, symbolTable);
    switch (node->nodeType) {
    case OP_ADD:
        cprintf(out, "ADD R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_SUB:
        cprintf(out, "SUB R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_MUL:
        cprintf(out, "MUL R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_DIV:
        cprintf(out, "DIV R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_MOD:
        cprintf(out, "MOD R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_READ:
        addr_reg = resolveAddr(out, node->left, symbolTable, fname, classIndex);
        libRead(out, XSM_STDIN, addr_reg);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        freeReg();
        break;
    case OP_ASSIGN: {
        struct symbol* symbolMiddle = getSymbolTable(node->middle->varName, symbolTable);
        struct type* typeLeft = typeCheck(node->left, symbolTable, classIndex);
        struct type* typeMiddle = typeCheck(node->middle, symbolTable, classIndex);
        if (handleInheritance(typeLeft->typename, typeMiddle->typename)) {
            struct symbol* symbolLeft = getSymbolTable(node->left->varName, symbolTable);
            struct typeTable* typeTableLeft = getTypeTableWithName(typeLeft->typename);
            struct typeTable* typeTableMiddle = getTypeTableWithName(typeMiddle->typename);
            handlePolymorphism(symbolLeft->vFuncTableBaseBinding, typeTableLeft->symbolList, typeTableMiddle->symbolList);
        }
        if (symbolMiddle != NULL && symbolMiddle->type->typename != NULL && symbolMiddle->type->depth == 0) {
            handleAssignForUserDefinedTypes(out, node->left, reg2, symbolTable, fname, classIndex);
        }
        else {
            addr_reg = node->left->nodeType == OP_DREF ? reg1 : resolveAddr(out, node->left, symbolTable, fname, classIndex);
            cprintf(out, "MOV [R%d], R%d\n", addr_reg, reg2);
            freeReg();
        }
        break;
    }
    case OP_IF:
        cprintf(out, "JNZ R%d, L%d\n", reg1, node->middle != NULL ? node->middle->label : next);
        cprintf(out, "JMP L%d\n", node->right != NULL ? node->right->label : next);
        break;
    case OP_WHILE:
        cprintf(out, "JZ R%d, L%d\n", reg1, next);
        break;
    case OP_GT:
        cprintf(out, "GT R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_LT:
        cprintf(out, "LT R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_GE:
        cprintf(out, "GE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_LE:
        cprintf(out, "LE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_EQ:
        cprintf(out, "EQ R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_NE:
        cprintf(out, "NE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_REF:
        addr_reg = resolveAddr(out, node->left, symbolTable, fname, classIndex);
        cprintf(out, "MOV R%d, R%d\n", reg1, addr_reg);
        //!TODO: freeReg
        break;
    case OP_DREF:
        cprintf(out, "MOV R%d, [R%d]\n", reg1, reg1);
        break;
    case OP_REPEAT_UNTIL:
        cprintf(out, "JZ R%d, L%d\n", reg2, node->label);
        break;
    case OP_DO_WHILE:
        cprintf(out, "JNZ R%d, L%d\n", reg2, node->label);
        break;
    case OP_RETURN: {
        if (fname == NULL) return;
        int reg = getReg();
        cprintf(out, "MOV R%d, BP\n", reg);
        cprintf(out, "SUB R%d, 2\n", reg);
        cprintf(out, "MOV [R%d], R%d\n", reg, reg1);
        freeReg();
    }
    default:
    }
}

/**
 * @brief generates the header for according to ABI
 * @param out output file pointer
 * @param ... other params are accoring to ABI specification
 */
void generateHeader(FILE* out, int xmagic, int entryPoint, int textSize, int dataSize, int heapSize, int stackSize, int libFlag) {
    cprintf(out, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", xmagic, entryPoint, textSize, dataSize, heapSize, stackSize, libFlag, 0);
}

/**
 * @brief generates XSM machine code for library read
 * @param out output file pointer
 * @param fileDescriptor fileDesscriptor to read from
 * @param addr buffer address
 */
int libRead(FILE* out, int fileDescriptor, int addr_reg) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Read\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "MOV R%d, %d\n", reg, fileDescriptor);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "MOV R%d, R%d\n", reg, addr_reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "CALL 0\n");
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "MOV R%d, [R%d]\n", reg, addr_reg);

    return reg;
}

/**
 * @brief generates XSM machine code for library write
 * @param regNum register
 * @param fileDescriptor file descriptor to write to
 */
void libWrite(FILE* out, int regNum, int fileDescriptor) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Write\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "MOV R%d, %d\n", reg, fileDescriptor);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "MOV R%d, R%d\n", reg, regNum);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "CALL 0\n");

    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);

}

/**
 * @brief generates XSM machine code for exit
 * @param out output file pointer
 */
void libExit(FILE* out) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Exit\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "CALL 0\n");

    freeReg();
}

void libFree(FILE* out, int binding_reg) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Free\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "MOV R%d, R%d\n", reg, binding_reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "CALL 0\n");

    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
}

int libAlloc(FILE* out) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Alloc\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "CALL 0\n");

    int reg1 = getFreeReg();
    cprintf(out, "POP R%d\n", reg1);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);

    return reg1;
}

void libInitialise(FILE* out) {
    int reg = getFreeReg();

    cprintf(out, "MOV R%d, \"Initialise\"\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);
    cprintf(out, "PUSH R%d\n", reg);

    cprintf(out, "CALL 0\n");

    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
    cprintf(out, "POP R%d\n", reg);
}

int isLValue(struct tNode* root) {
    if (root == NULL) return 0;
    struct tNode* prev = root;
    root = root->parent;
    while (root != NULL && root->nodeType != OP_ASSIGN && root->nodeType != LEAF_TUPLE_ACCESS && root->nodeType != LEAF_ARR && root->nodeType != LEAF_METHOD) {
        prev = root;
        root = root->parent;
    }
    return root != NULL && root->nodeType != LEAF_ARR && root->left == prev;
}

int pushFuncArgs(FILE* out, struct tNode* argList, struct symbol* symbolTable, char* fname, int classIndex) {
    if (argList == NULL) return 0;

    if (argList->nodeType != OP_ARGLIST) {
        int reg = codeGenHelper(out, argList, -1, NULL, symbolTable, fname, classIndex);
        cprintf(out, "PUSH R%d\n", reg);
        return 1;
    }

    // we need to push in reverse so first middle then left
    int numOfRegInMiddle = pushFuncArgs(out, argList->middle, symbolTable, fname, classIndex);
    int numOfRegInLeft = pushFuncArgs(out, argList->left, symbolTable, fname, classIndex);

    return numOfRegInLeft + numOfRegInMiddle;
}

struct tNode* getVarDescendant(struct tNode* node) {
    while (node != NULL && node->nodeType != LEAF_ID) {
        if (node->nodeType == LEAF_TUPLE_ACCESS) return node->middle;
        node = node->left;
    }
    return node;
}

/**
 * @brief generates machine code for leafs of Abstract syntax tree
 * @param out output file pointer
 * @param varName optional - only for identifiers
 * @param val optional - value for numbers
 */
int leafCodeGen(FILE* out, struct tNode* node, int next, struct symbol* symbolTable, char* fname, int classIndex) {
    if (fname != NULL && (node->nodeType == LEAF_ID || node->nodeType == LEAF_TUPLE_ACCESS)) {
        return leafCodeGenForFunction(out, fname, node, symbolTable, classIndex);
    }
    int reg = -1;
    struct symbol* sym = NULL;
    struct tNode* prev = NULL;
    int addr = -1;
    switch (node->nodeType) {
    case LEAF_ID:
        reg = getFreeReg();
        struct symbol* sym = getSymbolTable(node->varName, symbolTable);
        addr = sym->binding;
        if (isLValue(node) || (sym->type->typename != NULL && sym->type->depth == 0)) {
            cprintf(out, "MOV R%d, %d\n", reg, addr);
        }
        else {
            cprintf(out, "MOV R%d, [%d]\n", reg, addr);
        }
        break;
    case LEAF_NUM:
        reg = getFreeReg();
        cprintf(out, "MOV R%d, %d\n", reg, node->val);
        break;
    case LEAF_STR:
        reg = getFreeReg();
        cprintf(out, "MOV R%d, \"%s\"\n", reg, node->stringVal);
        break;
    case LEAF_BREAK:
        if (empty(nextLabelStack)) {
            printf("Error: break in a non while block\n");
            exit(EXIT_FAILURE);
        }
        int latestNextWhileLabel = top(nextLabelStack).intValue;
        cprintf(out, "JMP L%d\n", latestNextWhileLabel);
        break;
    case LEAF_CONTINUE:
        if (empty(beginLabelStack)) {
            printf("Error: continue in a non while block\n");
            exit(EXIT_FAILURE);
        }
        int latestBeginWhileLabel = top(beginLabelStack).intValue;
        cprintf(out, "JMP L%d\n", latestBeginWhileLabel);
        break;
    case LEAF_ARR: {
        int addr_reg = resolveArrayAddr(out, node, symbolTable, fname, classIndex);
        struct type* type = typeCheck(node, symbolTable, classIndex);
        if (!isLValue(node) && (type->typename == NULL || type->depth != 0)) {
            cprintf(out, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
        }
        reg = addr_reg;
        break;
    }
    case LEAF_FUNC: {
        backup(out);
        char* calleeFname = node->left->varName;
        struct symbol* fsymbol = getSymbolTable(calleeFname, symbolTable);
        if (fsymbol == NULL) {
            printf("Error: no such function: %s\n", calleeFname);
            exit(EXIT_FAILURE);
        }
        int args = pushFuncArgs(out, node->middle, symbolTable, fname, classIndex);
        cprintf(out, "PUSH R0\n"); // return value
        cprintf(out, "CALL %d\n", fsymbol->flabel);
        if (getReg() == MAX_REG) {
            printf("Error: run out of registers\n");
            exit(EXIT_FAILURE);
        }
        cprintf(out, "POP R19\n");
        for (int i = 0;i < args;i++) {
            cprintf(out, "POP R0\n");
        }
        restore(out);
        reg = getFreeReg();
        cprintf(out, "MOV R%d, R19\n", reg);
        break;
    }
    case LEAF_TUPLE_ACCESS: {
        int reg = resolveAddr(out, node, symbolTable, NULL, classIndex);
        if (!isLValue(node)) {
            cprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        return reg;
        break;
    }
    case LEAF_NEW: {
        struct type* type = typeCheck(node->left, symbolTable, classIndex);
        struct typeTable* typeTable = getTypeTableWithName(type->typename);
        if (typeTable != NULL && handleInheritance(typeTable->name, node->middle->varName)) {
            handlePolymorphism(getSymbolTable(node->left->varName, symbolTable)->vFuncTableBaseBinding, typeTable->symbolList, getTypeTableWithName(node->middle->varName)->symbolList);
        }
    }
    case OP_ALLOC: {
        int reg = libAlloc(out);
        int addr_reg = resolveAddr(out, node->left, symbolTable, fname, classIndex);
        cprintf(out, "MOV [R%d], R%d\n", addr_reg, reg);
        break;
    }
    case OP_FREE: {
        int addr_reg = resolveAddr(out, node->left, symbolTable, fname, classIndex);
        cprintf(out, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
        libFree(out, addr_reg);
        break;
    }
    case OP_INITIALISE:
        libInitialise(out);
        break;
    case LEAF_METHOD: {
        backup(out);
        struct typeTable* typeTable;
        char* calleeFname = node->middle->varName;
        if (node->left->nodeType != LEAF_SELF) {
            struct type* type = typeCheck(node->left, symbolTable, classIndex);
            typeTable = getTypeTableWithName(type->typename);
        }
        else {
            typeTable = getClassTableWithIndex(classIndex);
        }
        struct symbol* fsymbol = getSymbolTable(calleeFname, typeTable->symbolList);
        if (fsymbol == NULL) {
            printf("Error: no such function: %s\n", calleeFname);
            exit(EXIT_FAILURE);
        }
        int reg;
        if (node->left->nodeType != LEAF_SELF) {
            reg = codeGenHelper(out, node->left, -1, NULL, symbolTable, fname, classIndex);
        }
        else {
            reg = getFreeReg();
            cprintf(out, "MOV R%d, BP\n", reg);
            cprintf(out, "SUB R%d, %d\n", reg, getParamLenForFunction(fsymbol->varName, typeTable->symbolList) + 3);
            cprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        cprintf(out, "PUSH R%d\n", reg);
        int args = pushFuncArgs(out, node->right, symbolTable, fname, classIndex);
        cprintf(out, "PUSH R0\n"); // return value
        if (node->left->nodeType == LEAF_SELF) {
            cprintf(out, "CALL %d\n", fsymbol->flabel);
        }
        else {
            int reg = getFreeReg();
            cprintf(out, "MOV R%d, [%d]\n", reg, getMethodLabel(getSymbolTable(getVarDescendant(node)->varName, symbolTable), calleeFname));
            cprintf(out, "CALL R%d\n", reg);
            freeReg();
        }
        if (getReg() == MAX_REG) {
            printf("Error: run out of registers\n");
            exit(EXIT_FAILURE);
        }
        cprintf(out, "POP R19\n");
        for (int i = 0;i < args;i++) {
            cprintf(out, "POP R0\n");
        }
        cprintf(out, "POP R0\n");
        restore(out);
        reg = getFreeReg();
        cprintf(out, "MOV R%d, R19\n", reg);
        return reg;
        break;
    }
    default:
    }
    return reg;
}

int resolveAddrInFunction(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname, int classIndex) {
    int reg = getFreeReg();
    int paramCount = getParamLenForFunction(fname, symbolTable);
    if (isParam(node->varName, symbolTable, paramCount)) {
        int offs = getParamOffset(node->varName, symbolTable, paramCount);
        cprintf(out, "MOV R%d, BP\n", reg);
        cprintf(out, "SUB R%d, 3\n", reg);
        cprintf(out, "SUB R%d, %d\n", reg, offs);
    }
    else {
        int offs;
        if (node->nodeType == LEAF_ID) {
            offs = getLocalVarOffset(node->varName, getLocalVarList(symbolTable, paramCount));
            if (offs == -1) {
                return resolveAddr(out, node, symbolTable, NULL, classIndex); // global
            }
            cprintf(out, "MOV R%d, BP\n", reg);
            cprintf(out, "ADD R%d, %d\n", reg, offs);
            cprintf(out, "ADD R%d, 1\n", reg);
        }
        else if (node->nodeType == LEAF_TUPLE_ACCESS) {
            int base_reg;
            struct typeTable* typeTable;
            if (node->left->nodeType == LEAF_SELF) {
                cprintf(out, "MOV R%d, BP\n", reg);
                cprintf(out, "SUB R%d, %d\n", reg, paramCount + 3);
                base_reg = reg;
                typeTable = getClassTableWithIndex(classIndex);
            }
            else {
                base_reg = codeGenHelper(out, node->left, -1, NULL, symbolTable, fname, classIndex);
                typeTable = getTypeTableWithName(typeCheck(node->left, symbolTable, classIndex)->typename);
            }
            offs = getFieldOffset(node->middle->varName, typeTable);
            if (node->left->nodeType == LEAF_SELF) {
                cprintf(out, "MOV R%d, [R%d]\n", base_reg, base_reg);
            }
            cprintf(out, "ADD R%d, %d\n", base_reg, offs);
            return base_reg;
        }

    }
    return reg;
}

int leafCodeGenForFunction(FILE* out, char* fname, struct tNode* node, struct symbol* symbolTable, int classIndex) {
    switch (node->nodeType) {
    case LEAF_ID: {
        int reg = resolveAddrInFunction(out, node, symbolTable, fname, classIndex);
        struct symbol* sym = getSymbolTable(node->varName, symbolTable);
        if (sym == NULL) {
            printf("Error: variable has not been declared: %s\n", node->varName);
            exit(EXIT_FAILURE);
        }
        if (!isLValue(node) && (sym->type->typename == NULL || sym->type->depth != 0)) {
            cprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        return reg;
        break;
    }
    case LEAF_TUPLE_ACCESS: {
        int reg = resolveAddrInFunction(out, node, symbolTable, fname, classIndex);
        if (!isLValue(node)) {
            cprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        return reg;
        break;
    }
    default:
    }
    return -1;
}

/**
 * @brief recursively iterates through Abstract Syntax Tree (AST) and generates machine code
 *  @param out output file pointer
 * @param root root of AST
 * @return register where result is stored
 */
int codeGenHelper(FILE* out, struct tNode* root, int next, struct tNode* parent, struct symbol* symbolTable, char* fname, int classIndex) {
    if (root == NULL) {
        return -1;
    }

    int registers_used = 0;
    if (isStmt(root->nodeType)) {
        if (root->nodeType == OP_WHILE || root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) {
            push(beginLabelStack, createGeneric(LEAF_TYPE_INT, &(root->label)));
            push(nextLabelStack, createGeneric(LEAF_TYPE_INT, &next));
        }
        fprintf(out, "L%d:\n", root->label);
    }

    if (isLeaf(root->nodeType)) {
        return leafCodeGen(out, root, next, symbolTable, fname, classIndex);
    }


    int reg1 = -1;
    // to prevent printing extra assembly instruction
    if (root->nodeType != OP_ASSIGN || root->left->nodeType == OP_DREF) {
        reg1 = codeGenHelper(out, root->left, root->nodeType == OP_STMTLIST ? root->middle->label : (root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) ? root->label : next, root, symbolTable, fname, classIndex);
    }

    if (root->nodeType == OP_IF || root->nodeType == OP_WHILE) {
        operatorCodeGen(out, root, reg1, -1, next, parent, symbolTable, fname, classIndex);
    }

    int reg2 = codeGenHelper(out, root->middle, root->nodeType == OP_WHILE ? root->label : next, root, symbolTable, fname, classIndex);

    if (root->nodeType == OP_IF) {
        cprintf(out, "JMP L%d\n", next);
    }
    else if (root->nodeType == OP_WHILE) {
        cprintf(out, "JMP L%d\n", root->label);
    }

    codeGenHelper(out, root->right, next, root, symbolTable, fname, classIndex);

    if (root->nodeType == OP_IF) {
        cprintf(out, "JMP L%d\n", next);
    }

    if (root->nodeType != OP_IF && root->nodeType != OP_WHILE) {
        operatorCodeGen(out, root, reg1, reg2, next, parent, symbolTable, fname, classIndex);
    }

    if (root->nodeType == OP_WHILE || root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) {
        pop(beginLabelStack);
        pop(nextLabelStack);
    }

    if (isStmt(root->nodeType)) {
        setReg(0);
    }
    return reg1;
}

void initDataStructures() {
    beginLabelStack = createStack(MAX_ARR_LEN);
    nextLabelStack = createStack(MAX_ARR_LEN);
}

/**
 * @brief generates XSM machine code to initialise stack pointer ...
 */
void initParams(FILE* out) {
    cprintf(out, "MOV SP, %d\n", INIT_SP);
    printf("here: %d\n", getLines());
}

void initCompiler(FILE* out) {
    initDataStructures();
    generateHeader(out, 0, ENTRY_POINT, 0, 0, 0, 0, 0);
    initParams(out);
}

/**
 * @brief generates XSM machine code from AST
 * @param out output file pointer
 * @param root root of AST
 */
void codeGen(FILE* out, struct tNode* root, struct symbol* symbolTable) {
    populateVirtualFunctionTableForSymbolTable(symbolTable, 1);
    codeGenHelper(out, root, -1, NULL, symbolTable, NULL, -1);
    cprintf(out, "L%d:\n", -1);
    libExit(out);
}

void pushOrPopLocalVariables(FILE* out, char* funcName, struct symbol* symbolTable, int pushOrPop) {
    struct symbol* fsymbol = getSymbolTable(funcName, symbolTable);
    if (fsymbol == NULL) {
        printf("Error: no such function has been declared\n");
        exit(EXIT_FAILURE);
    }
    struct symbol* lVarList = getLocalVarList(symbolTable, getParamLen(fsymbol->paramList));
    while (lVarList != NULL && !(lVarList->isGlobal)) {
        int size = getTypeSize(lVarList->type);
        for (int i = 0;i < size;i++) {
            cprintf(out, "%s R%d\n", pushOrPop ? "PUSH" : "POP", 0);
        }
        lVarList = lVarList->next;
    }
}

void funcCodeGen(FILE* out, char* funcName, struct tNode* root, struct symbol* symbolTable, int classIndex) {
    struct symbol* fsymbol = getSymbolTable(funcName, symbolTable);
    fsymbol->flabel = 2 * getLines() + ENTRY_POINT;
    populateVirtualFunctionTableForSymbolTable(symbolTable, 0);
    cprintf(out, "PUSH BP\n");
    cprintf(out, "MOV BP, SP\n");
    pushOrPopLocalVariables(out, funcName, symbolTable, 1);
    codeGenHelper(out, root, -1, NULL, symbolTable, funcName, classIndex);
    pushOrPopLocalVariables(out, funcName, symbolTable, 0);
    cprintf(out, "POP BP\n");
    cprintf(out, "RET\n");
}

void populateParent(struct tNode* root) {
    if (root == NULL) return;

    if (root->left != NULL) root->left->parent = root;
    if (root->middle != NULL) root->middle->parent = root;
    if (root->right != NULL) root->right->parent = root;

    populateParent(root->left);
    populateParent(root->middle);
    populateParent(root->right);
}

