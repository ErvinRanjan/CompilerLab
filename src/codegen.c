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

struct stack* beginLabelStack, * nextLabelStack; // keeps track of latest while begin and next labels
extern int getArrayDepth(struct tNode* braceRoot);

bool isLeaf(int nodeType) {
    return nodeType == LEAF_ID || nodeType == LEAF_NUM || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == LEAF_STR || nodeType == LEAF_TYPE_INT || nodeType == LEAF_TYPE_STR || nodeType == LEAF_ARR || nodeType == LEAF_FUNC || nodeType == LEAF_FDECL || nodeType == LEAF_TUPLE_ACCESS;
}

void resolveArrayAddrCodegen(FILE* out, struct tNode* braceRoot, struct symbol* symbolTable, int* base, char* fname) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        int reg = codeGenHelper(out, braceRoot, -1, NULL, symbolTable, fname);
        fprintf(out, "MOV [%d], R%d\n", *base, reg);
        (*base) = (*base) + 1;
        return;
    }

    resolveArrayAddrCodegen(out, braceRoot->left, symbolTable, base, fname);
    resolveArrayAddrCodegen(out, braceRoot->middle, symbolTable, base, fname);
}

int resolveAddr(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname) {
    if (fname != NULL && (node->nodeType == LEAF_ID || node->nodeType == LEAF_TUPLE_ACCESS)) {
        return resolveAddrInFunction(out, node, symbolTable, fname);
    }
    switch (node->nodeType) {
    case LEAF_ID:
        int reg = getFreeReg();
        fprintf(out, "MOV R%d, %d\n", reg, getMem(node->varName, symbolTable));
        return reg;
        break;
    case LEAF_ARR:
        return resolveArrayAddr(out, node, symbolTable, fname);
        break;
    case LEAF_TUPLE_ACCESS: {
        struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
        int base_reg = codeGenHelper(out, node->left, -1, NULL, symbolTable, fname);
        int offs = getFieldOffset(node->middle->varName, typeTable->paramList);
        int reg = getFreeReg();
        fprintf(out, "MOV R%d, R%d\n", reg, base_reg);
        fprintf(out, "ADD R%d, %d\n", reg, offs);
        return reg;
    }
    default:
    }
    return -1;
}

int resolveArrayAddr(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname) {
    int depth = getArrayDepth(node->middle);
    int indices[100];
    int base = getFreeMem(depth);
    int x = base;
    resolveArrayAddrCodegen(out, node->middle, symbolTable, &x, fname);
    struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
    int maxSizesBase = getFreeMem(depth);
    for (int i = 0;i < depth;i++) {
        fprintf(out, "MOV [%d], %d\n", maxSizesBase + i, sym->maxSizes[i]);
    }
    int maxi = base + depth;
    int addr_reg = getFreeReg();
    if (sym->symbolType == PRIMITIVE) {
        fprintf(out, "MOV R%d, [%d]\n", addr_reg, sym->binding);
    }
    else {
        fprintf(out, "MOV R%d, %d\n", addr_reg, sym->binding);
    }
    int prod_reg = getFreeReg();
    fprintf(out, "MOV R%d, %d\n", prod_reg, 1);
    int base_reg = getFreeReg();
    int maxSizesBase_reg = getFreeReg();
    fprintf(out, "MOV R%d, %d\n", base_reg, base);
    fprintf(out, "MOV R%d, %d\n", maxSizesBase_reg, maxSizesBase);
    int op_reg = getFreeReg();
    int label = getLabel();
    fprintf(out, "L%d:\n", label);
    fprintf(out, "MOV R%d, R%d\n", op_reg, prod_reg);
    int temp = getFreeReg();
    fprintf(out, "MOV R%d, [R%d]\n", temp, base_reg);
    fprintf(out, "MUL R%d, R%d\n", op_reg, temp);
    freeReg();
    fprintf(out, "ADD R%d, R%d\n", addr_reg, op_reg);
    fprintf(out, "MOV R%d, [R%d]\n", op_reg, maxSizesBase_reg);
    fprintf(out, "MUL R%d, R%d\n", prod_reg, op_reg);
    fprintf(out, "ADD R%d, %d\n", base_reg, 1);
    fprintf(out, "ADD R%d, %d\n", maxSizesBase_reg, 1);
    fprintf(out, "MOV R%d, %d\n", op_reg, maxi);
    fprintf(out, "EQ R%d, R%d\n", op_reg, base_reg);
    fprintf(out, "JZ R%d, L%d\n", op_reg, label);
    freeReg();
    freeReg();
    freeReg();
    freeReg();
    freeMem(2 * depth);
    return addr_reg;
}

bool isStmt(int nodeType) {
    return nodeType == OP_READ || nodeType == OP_WRITE || nodeType == OP_ASSIGN || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == OP_IF || nodeType == OP_WHILE || nodeType == OP_DO_WHILE || nodeType == OP_REPEAT_UNTIL || nodeType == OP_RETURN;
}

int getMem(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return -1;

    struct symbol* sym = getSymbolTable(varName, symbolTable);

    return sym == NULL ? -1 : sym->binding;
}

void handleAssignForUserDefinedTypes(FILE* out, struct tNode* node, int addr_reg, struct symbol* symbolTable, char* fname) {
    struct symbol* symbol = getSymbolTable(node->varName, symbolTable);
    struct typeTable* typeTable = getTypeTableWithName(symbol->type->typename);
    if (typeTable == NULL) {
        printf("Error: type is used but not declared\n");
        exit(EXIT_FAILURE);
    }
    int base_reg = resolveAddr(out, node, symbolTable, fname);
    struct param* paramList = typeTable->paramList;
    int size = 0;
    int reg1 = getFreeReg();
    int reg2 = getFreeReg();
    while (paramList != NULL) {
        int totalTypeSizeIncludingCur = size + getTypeSize(paramList->type);
        while (size < totalTypeSizeIncludingCur) {
            fprintf(out, "MOV R%d, R%d\n", reg1, base_reg);
            fprintf(out, "MOV R%d, R%d\n", reg2, addr_reg);
            fprintf(out, "ADD R%d, %d\n", reg1, size);
            fprintf(out, "ADD R%d, %d\n", reg2, size);
            fprintf(out, "MOV R%d, [R%d]\n", reg2, reg2);
            fprintf(out, "MOV [R%d], R%d\n", reg1, reg2);
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
void operatorCodeGen(FILE* out, struct tNode* node, int reg1, int reg2, int next, struct tNode* parent, struct symbol* symbolTable, char* fname) {
    int addr_reg = -1;
    int paramCount = getParamLenForFunction(fname, symbolTable);
    switch (node->nodeType) {
    case OP_ADD:
        fprintf(out, "ADD R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_SUB:
        fprintf(out, "SUB R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_MUL:
        fprintf(out, "MUL R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_DIV:
        fprintf(out, "DIV R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_MOD:
        fprintf(out, "MOD R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_READ:
        addr_reg = resolveAddr(out, node->left, symbolTable, fname);
        libRead(out, XSM_STDIN, addr_reg);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        freeReg();
        break;
    case OP_ASSIGN: {
        struct symbol* symbolMiddle = getSymbolTable(node->middle->varName, symbolTable);
        if (symbolMiddle != NULL && symbolMiddle->type->typename != NULL) {
            handleAssignForUserDefinedTypes(out, node->left, reg2, symbolTable, fname);
        }
        else {
            addr_reg = node->left->nodeType == OP_DREF ? reg1 : resolveAddr(out, node->left, symbolTable, fname);
            fprintf(out, "MOV [R%d], R%d\n", addr_reg, reg2);
            freeReg();
        }
        break;
    }
    case OP_IF:
        fprintf(out, "JNZ R%d, L%d\n", reg1, node->middle != NULL ? node->middle->label : next);
        fprintf(out, "JMP L%d\n", node->right != NULL ? node->right->label : next);
        break;
    case OP_WHILE:
        fprintf(out, "JZ R%d, L%d\n", reg1, next);
        break;
    case OP_GT:
        fprintf(out, "GT R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_LT:
        fprintf(out, "LT R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_GE:
        fprintf(out, "GE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_LE:
        fprintf(out, "LE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_EQ:
        fprintf(out, "EQ R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_NE:
        fprintf(out, "NE R%d, R%d\n", reg1, reg2);
        freeReg();
        break;
    case OP_REF:
        addr_reg = resolveAddr(out, node->left, symbolTable, fname);
        fprintf(out, "MOV R%d, R%d\n", reg1, addr_reg);
        //!TODO: freeReg
        break;
    case OP_DREF:
        fprintf(out, "MOV R%d, [R%d]\n", reg1, reg1);
        break;
    case OP_REPEAT_UNTIL:
        fprintf(out, "JZ R%d, L%d\n", reg2, node->label);
        break;
    case OP_DO_WHILE:
        fprintf(out, "JNZ R%d, L%d\n", reg2, node->label);
        break;
    case OP_RETURN: {
        if (fname == NULL) return;
        int reg = getReg();
        fprintf(out, "MOV R%d, BP\n", reg);
        fprintf(out, "SUB R%d, 2\n", reg);
        fprintf(out, "MOV [R%d], R%d\n", reg, reg1);
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
    fprintf(out, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", xmagic, entryPoint, textSize, dataSize, heapSize, stackSize, libFlag, 0);
}

/**
 * @brief generates XSM machine code for library read
 * @param out output file pointer
 * @param fileDescriptor fileDesscriptor to read from
 * @param addr buffer address
 */
int libRead(FILE* out, int fileDescriptor, int addr_reg) {
    int reg = getFreeReg();

    fprintf(out, "MOV R%d, \"Read\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "MOV R%d, %d\n", reg, fileDescriptor);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "MOV R%d, R%d\n", reg, addr_reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "CALL 0\n");
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "MOV R%d, [R%d]\n", reg, addr_reg);

    return reg;
}

/**
 * @brief generates XSM machine code for library write
 * @param regNum register
 * @param fileDescriptor file descriptor to write to
 */
void libWrite(FILE* out, int regNum, int fileDescriptor) {
    int reg = getFreeReg();

    fprintf(out, "MOV R%d, \"Write\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);

    fprintf(out, "MOV R%d, %d\n", reg, fileDescriptor);
    fprintf(out, "PUSH R%d\n", reg);

    fprintf(out, "MOV R%d, R%d\n", reg, regNum);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);

    fprintf(out, "CALL 0\n");

    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);

}

/**
 * @brief generates XSM machine code for exit
 * @param out output file pointer
 */
void libExit(FILE* out) {
    int reg = getFreeReg();

    fprintf(out, "MOV R%d, \"Exit\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "CALL 0\n");

    freeReg();
}

int isLValue(struct tNode* root) {
    if (root == NULL) return 0;
    struct tNode* prev = NULL;
    while (root != NULL && root->nodeType != OP_ASSIGN) {
        prev = root;
        root = root->parent;
    }
    return root != NULL && root->left == prev;
}

int pushFuncArgs(FILE* out, struct tNode* argList, struct symbol* symbolTable, char* fname) {
    if (argList == NULL) return 0;

    if (argList->nodeType != OP_ARGLIST) {
        int reg = codeGenHelper(out, argList, -1, NULL, symbolTable, fname);
        fprintf(out, "PUSH R%d\n", reg);
        return 1;
    }

    // we need to push in reverse so first middle then left
    int numOfRegInMiddle = pushFuncArgs(out, argList->middle, symbolTable, fname);
    int numOfRegInLeft = pushFuncArgs(out, argList->left, symbolTable, fname);

    return numOfRegInLeft + numOfRegInMiddle;
}

/**
 * @brief generates machine code for leafs of Abstract syntax tree
 * @param out output file pointer
 * @param varName optional - only for identifiers
 * @param val optional - value for numbers
 */
int leafCodeGen(FILE* out, struct tNode* node, int next, struct symbol* symbolTable, char* fname) {
    if (fname != NULL && (node->nodeType == LEAF_ID || node->nodeType == LEAF_TUPLE_ACCESS)) {
        return leafCodeGenForFunction(out, fname, node, symbolTable);
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
        if (sym->type->typename != NULL) {
            fprintf(out, "MOV R%d, %d\n", reg, addr);
        }
        else if (sym->type->depth == 0 || !isLValue(node)) {
            fprintf(out, "MOV R%d, [%d]\n", reg, addr);
        }
        else {
            fprintf(out, "MOV R%d, %d\n", reg, addr);
        }
        break;
    case LEAF_NUM:
        reg = getFreeReg();
        fprintf(out, "MOV R%d, %d\n", reg, node->val);
        break;
    case LEAF_STR:
        reg = getFreeReg();
        fprintf(out, "MOV R%d, \"%s\"\n", reg, node->stringVal);
        break;
    case LEAF_BREAK:
        if (empty(nextLabelStack)) {
            printf("Error: break in a non while block\n");
            exit(EXIT_FAILURE);
        }
        int latestNextWhileLabel = top(nextLabelStack).intValue;
        fprintf(out, "JMP L%d\n", latestNextWhileLabel);
        break;
    case LEAF_CONTINUE:
        if (empty(beginLabelStack)) {
            printf("Error: continue in a non while block\n");
            exit(EXIT_FAILURE);
        }
        int latestBeginWhileLabel = top(beginLabelStack).intValue;
        fprintf(out, "JMP L%d\n", latestBeginWhileLabel);
        break;
    case LEAF_ARR:
        int addr_reg = resolveArrayAddr(out, node, symbolTable, fname);
        fprintf(out, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
        reg = addr_reg;
        break;
    case LEAF_FUNC: {
        backup(out);
        char* calleeFname = node->left->varName;
        struct symbol* fsymbol = getSymbolTable(calleeFname, symbolTable);
        if (fsymbol == NULL) {
            printf("Error: no such function: %s\n", calleeFname);
            exit(EXIT_FAILURE);
        }
        int args = pushFuncArgs(out, node->middle, symbolTable, fname);
        fprintf(out, "PUSH R0\n"); // return value
        fprintf(out, "CALL L%d\n", fsymbol->flabel);
        if (getReg() == MAX_REG) {
            printf("Error: run out of registers\n");
            exit(EXIT_FAILURE);
        }
        fprintf(out, "POP R19\n");
        for (int i = 0;i < args;i++) {
            fprintf(out, "POP R0\n");
        }
        restore(out);
        reg = getFreeReg();
        fprintf(out, "MOV R%d, R19\n", reg);
        break;
    }
    case LEAF_TUPLE_ACCESS: {
        int reg = resolveAddr(out, node, symbolTable, NULL);
        struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
        struct type* fieldType = getFieldType(node->middle->varName, typeTable->paramList);
        if (fieldType->depth == 0 || !isLValue(node)) {
            fprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        else {
            fprintf(out, "MOV R%d, R%d\n", reg, reg);
        }
        return reg;
        break;
    }
    default:
    }
    return reg;
}

int resolveAddrInFunction(FILE* out, struct tNode* node, struct symbol* symbolTable, char* fname) {
    int reg = getFreeReg();
    int paramCount = getParamLenForFunction(fname, symbolTable);
    if (isParam(node->varName, symbolTable, paramCount)) {
        int offs = getParamOffset(node->varName, symbolTable, paramCount);
        fprintf(out, "MOV R%d, BP\n", reg);
        fprintf(out, "SUB R%d, 3\n", reg);
        fprintf(out, "SUB R%d, %d\n", reg, offs);
    }
    else {
        int offs;
        if (node->nodeType == LEAF_ID) {
            offs = getLocalVarOffset(node->varName, getLocalVarList(symbolTable, paramCount));
            if (offs == -1) {
                return resolveAddr(out, node, symbolTable, NULL); // global
            }
            fprintf(out, "MOV R%d, BP\n", reg);
            fprintf(out, "ADD R%d, %d\n", reg, offs);
            fprintf(out, "ADD R%d, 1\n", reg);
        }
        else if (node->nodeType == LEAF_TUPLE_ACCESS) {
            int base_reg = codeGenHelper(out, node->left, -1, NULL, symbolTable, fname);
            struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
            int offs = getFieldOffset(node->middle->varName, typeTable->paramList);
            fprintf(out, "ADD R%d, %d\n", base_reg, offs);
            return base_reg;
        }

    }
    return reg;
}

int leafCodeGenForFunction(FILE* out, char* fname, struct tNode* node, struct symbol* symbolTable) {
    switch (node->nodeType) {
    case LEAF_ID: {
        int reg = resolveAddrInFunction(out, node, symbolTable, fname);
        struct symbol* sym = getSymbolTable(node->varName, symbolTable);
        if (sym == NULL) {
            printf("Error: variable has not been declared: %s\n", node->varName);
            exit(EXIT_FAILURE);
        }
        if (sym->type->typename == NULL && (sym->type->depth == 0 || !isLValue(node))) {
            fprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        return reg;
        break;
    }
    case LEAF_TUPLE_ACCESS: {
        int reg = resolveAddrInFunction(out, node, symbolTable, fname);
        struct typeTable* typeTable = getTypeTableWithName(node->left->type->typename);
        struct type* fieldType = getFieldType(node->middle->varName, typeTable->paramList);
        if (fieldType->depth == 0 || !isLValue(node)) {
            fprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        }
        else {
            fprintf(out, "MOV R%d, R%d\n", reg, reg);
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
int codeGenHelper(FILE* out, struct tNode* root, int next, struct tNode* parent, struct symbol* symbolTable, char* fname) {
    if (root == NULL) {
        return -1;
    }

    int registers_used = 0;
    if (isStmt(root->nodeType)) {
        registers_used = getReg();
        if (root->nodeType == OP_WHILE || root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) {
            push(beginLabelStack, createGeneric(LEAF_TYPE_INT, &(root->label)));
            push(nextLabelStack, createGeneric(LEAF_TYPE_INT, &next));
        }
        fprintf(out, "L%d:\n", root->label);
    }

    if (isLeaf(root->nodeType)) {
        return leafCodeGen(out, root, next, symbolTable, fname);
    }


    int reg1 = -1;
    // to prevent printing extra assembly instruction
    if (root->nodeType != OP_ASSIGN || root->left->nodeType == OP_DREF) {
        reg1 = codeGenHelper(out, root->left, root->nodeType == OP_STMTLIST ? root->middle->label : (root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) ? root->label : next, root, symbolTable, fname);
    }

    if (root->nodeType == OP_IF || root->nodeType == OP_WHILE) {
        operatorCodeGen(out, root, reg1, -1, next, parent, symbolTable, fname);
    }

    int reg2 = codeGenHelper(out, root->middle, root->nodeType == OP_WHILE ? root->label : next, root, symbolTable, fname);

    if (root->nodeType == OP_IF) {
        fprintf(out, "JMP L%d\n", next);
    }
    else if (root->nodeType == OP_WHILE) {
        fprintf(out, "JMP L%d\n", root->label);
    }

    codeGenHelper(out, root->right, next, root, symbolTable, fname);

    if (root->nodeType == OP_IF) {
        fprintf(out, "JMP L%d\n", next);
    }

    if (root->nodeType != OP_IF && root->nodeType != OP_WHILE) {
        operatorCodeGen(out, root, reg1, reg2, next, parent, symbolTable, fname);
    }

    if (root->nodeType == OP_WHILE || root->nodeType == OP_REPEAT_UNTIL || root->nodeType == OP_DO_WHILE) {
        pop(beginLabelStack);
        pop(nextLabelStack);
    }

    if (isStmt(root->nodeType)) {
        setReg(registers_used);
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
    fprintf(out, "MOV SP, %d\n", INIT_SP);
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
    codeGenHelper(out, root, -1, NULL, symbolTable, NULL);
    fprintf(out, "L%d:\n", -1);
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
            fprintf(out, "%s R%d\n", pushOrPop ? "PUSH" : "POP", 0);
        }
        lVarList = lVarList->next;
    }
}

void funcCodeGen(FILE* out, char* funcName, struct tNode* root, struct symbol* symbolTable) {
    struct symbol* fsymbol = getSymbolTable(funcName, symbolTable);
    fprintf(out, "L%d:\n", fsymbol->flabel);
    fprintf(out, "PUSH BP\n");
    fprintf(out, "MOV BP, SP\n");
    pushOrPopLocalVariables(out, funcName, symbolTable, 1);
    codeGenHelper(out, root, -1, NULL, symbolTable, funcName);
    pushOrPopLocalVariables(out, funcName, symbolTable, 0);
    fprintf(out, "POP BP\n");
    fprintf(out, "RET\n");
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

