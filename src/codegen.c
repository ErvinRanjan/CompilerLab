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

struct stack* beginLabelStack, * nextLabelStack; // keeps track of latest while begin and next labels

extern int getArrayDepth(struct tNode* braceRoot);

bool isLeaf(int nodeType) {
    return nodeType == LEAF_ID || nodeType == LEAF_NUM || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == LEAF_STR || nodeType == LEAF_TYPE_INT || nodeType == LEAF_TYPE_STR || nodeType == LEAF_ARR;
}

void resolveArrayAddrCodegen(FILE* out, struct tNode* braceRoot, struct symbol* symbolTable, int* base) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        int reg = codeGenHelper(out, braceRoot, -1, NULL, symbolTable);
        fprintf(out, "MOV [%d], R%d\n", *base, reg);
        (*base) = (*base) + 1;
        return;
    }

    resolveArrayAddrCodegen(out, braceRoot->left, symbolTable, base);
    resolveArrayAddrCodegen(out, braceRoot->middle, symbolTable, base);
}

int resolveAddr(FILE* out, struct tNode* node, struct symbol* symbolTable) {
    switch (node->nodeType) {
    case LEAF_ID:
        int reg = getFreeReg();
        fprintf(out, "MOV R%d, %d\n", reg, getMem(node->varName, symbolTable));
        return reg;
        break;
    case LEAF_ARR:
        return resolveArrayAddr(out, node, symbolTable);
        break;
    default:
    }
    return -1;
}

int resolveArrayAddr(FILE* out, struct tNode* node, struct symbol* symbolTable) {
    int depth = getArrayDepth(node->middle);
    int indices[100];
    int base = getFreeMem(depth);
    int x = base;
    resolveArrayAddrCodegen(out, node->middle, symbolTable, &x);
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

bool isNotConditionalStmt(int nodeType) {
    return nodeType == OP_READ || nodeType == OP_WRITE || nodeType == OP_ASSIGN || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE;
}

bool isConditionalStmt(int nodeType) {
    return nodeType == OP_IF || nodeType == OP_WHILE;
}

bool isStmt(int nodeType) {
    return isConditionalStmt(nodeType) || isNotConditionalStmt(nodeType);
}

int getMem(char* varName, struct symbol* symbolTable) {
    if (varName == NULL) return -1;

    struct symbol* sym = getSymbolTable(varName, symbolTable);

    return sym == NULL ? -1 : sym->binding;
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
void operatorCodeGen(FILE* out, struct tNode* node, int reg1, int reg2, int next, struct tNode* parent, struct symbol* symbolTable) {
    int addr_reg = -1;
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
        addr_reg = resolveAddr(out, node->left, symbolTable);
        libRead(out, XSM_STDIN, addr_reg);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        freeReg();
        break;
    case OP_ASSIGN:
        addr_reg = resolveAddr(out, node->left, symbolTable);
        fprintf(out, "MOV [R%d], R%d\n", addr_reg, reg2);
        freeReg();
        break;
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
        struct symbol* sym = getSymbolTable(node->left->varName, symbolTable);
        fprintf(out, "MOV R%d, %d\n", reg1, sym->binding);
        break;
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

/**
 * @brief generates machine code for leafs of Abstract syntax tree
 * @param out output file pointer
 * @param varName optional - only for identifiers
 * @param val optional - value for numbers
 */
int leafCodeGen(FILE* out, struct tNode* node, int next, struct symbol* symbolTable) {
    int reg = -1;
    switch (node->nodeType) {
    case LEAF_ID:
        reg = getFreeReg();
        int addr = getMem(node->varName, symbolTable);
        fprintf(out, "MOV R%d, [%d]\n", reg, addr);
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
        int addr_reg = resolveArrayAddr(out, node, symbolTable);
        fprintf(out, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
        reg = addr_reg;
        break;
    default:
    }
    return reg;
}

/**
 * @brief recursively iterates through Abstract Syntax Tree (AST) and generates machine code
 *  @param out output file pointer
 * @param root root of AST
 * @return register where result is stored
 */
int codeGenHelper(FILE* out, struct tNode* root, int next, struct tNode* parent, struct symbol* symbolTable) {
    if (root == NULL) {
        return -1;
    }

    int registers_used = 0;
    if (isStmt(root->nodeType)) {
        registers_used = getReg();
        if (root->nodeType == OP_WHILE) {
            push(beginLabelStack, createGeneric(LEAF_TYPE_INT, &(root->label)));
            push(nextLabelStack, createGeneric(LEAF_TYPE_INT, &next));
        }
        fprintf(out, "L%d:\n", root->label);
    }

    if (isLeaf(root->nodeType)) {
        return leafCodeGen(out, root, next, symbolTable);
    }

    int reg1 = -1;
    // to prevent printing extra assembly instruction
    if (root->nodeType != OP_ASSIGN) {
        reg1 = codeGenHelper(out, root->left, root->nodeType == OP_STMTLIST ? root->middle->label : next, root, symbolTable);
    }

    if (isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root, reg1, -1, next, parent, symbolTable);
    }

    int reg2 = codeGenHelper(out, root->middle, root->nodeType == OP_WHILE ? root->label : next, root, symbolTable);

    if (isConditionalStmt(root->nodeType)) {
        fprintf(out, "JMP L%d\n", next);
    }

    codeGenHelper(out, root->right, next, root, symbolTable);

    if (root->nodeType == OP_IF) {
        fprintf(out, "JMP L%d\n", next);
    }

    if (!isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root, reg1, reg2, next, parent, symbolTable);
    }

    if (root->nodeType == OP_WHILE) {
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

/**
 * @brief generates XSM machine code from AST
 * @param out output file pointer
 * @param root root of AST
 */
void codeGen(FILE* out, struct tNode* root, struct symbol* symbolTable) {
    initDataStructures();
    generateHeader(out, 0, ENTRY_POINT, 0, 0, 0, 0, 0);
    initParams(out);
    codeGenHelper(out, root, -1, NULL, symbolTable);
    fprintf(out, "L%d:\n", -1);
    libExit(out);
}

int operatorEval(struct tNode* node, int val1, int val2, char* buf, struct symbol* symbolTable) {
    int isString = 0;
    char cval[100];
    struct symbol* sym;
    switch (node->nodeType) {
    case OP_ADD:
        return val1 + val2;
        break;
    case OP_SUB:
        return val1 - val2;
        break;
    case OP_MUL:
        return val1 * val2;
        break;
    case OP_DIV:
        return val1 / val2;
        break;
    case OP_MOD:
        return val1 % val2;
        break;
    case OP_READ:
        scanf("%s", buf);
        sym = node->left->nodeType == LEAF_ARR ? getSymbolTable(node->left->left->varName, symbolTable) : getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("No such symbol found\n");
            exit(EXIT_FAILURE);
        }
        if (sym->type->depth != 0) {
            int offs = getArrayOffset(node->left, sym, symbolTable);
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->aval[offs] = atoi(buf);
            }
            else {
                strncpy(sym->acval[offs], buf, strlen(buf));
            }
        }
        else {
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->val = atoi(buf);
            }
            else {
                strncpy(sym->cval, buf, strlen(buf));
            }
        }
        break;
    case OP_WRITE:
        int val = eval(node->left, cval, &isString, symbolTable);
        if (isString) {
            printf("%s\n", cval);
        }
        else {
            printf("%d\n", val);
        }
        break;
    case OP_ASSIGN:
        sym = node->left->nodeType == LEAF_ARR ? getSymbolTable(node->left->left->varName, symbolTable) : getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("No such symbol found\n");
            exit(EXIT_FAILURE);
        }
        if (sym->type->depth != 0) {
            int offs = getArrayOffset(node->left, sym, symbolTable);
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->aval[offs] = val2;
            }
            else {
                strncpy(sym->acval[offs], buf, strlen(buf));
            }
        }
        else {
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->val = val2;
            }
            else {
                strncpy(sym->cval, buf, strlen(buf));
            }
        }
        break;
    case OP_IF:
        if (val1) {
            eval(node->middle, cval, &isString, symbolTable);
        }
        else {
            eval(node->right, cval, &isString, symbolTable);
        }
        break;
    case OP_WHILE:
        while (eval(node->left, cval, &isString, symbolTable)) {
            eval(node->middle, cval, &isString, symbolTable);
        }
        break;
    case OP_GT:
        return val1 > val2;
        break;
    case OP_LT:
        return val1 < val2;
        break;
    case OP_GE:
        return val1 >= val2;
        break;
    case OP_LE:
        return val1 <= val2;
        break;
    case OP_EQ:
        return val1 == val2;
        break;
    case OP_NE:
        return val1 != val2;
        break;
    case OP_REF:
        sym = getSymbolTable(node->left->varName, symbolTable);
        return sym->binding;
    default:
    }
}

int leafCodeEval(struct tNode* node, char* cval, struct symbol* symbolTable, int* isString) {
    *isString = 0;
    switch (node->nodeType) {
    case LEAF_ID:
        struct symbol* sym = getSymbolTable(node->varName, symbolTable);
        if (sym->type->code == LEAF_TYPE_INT) {
            return sym->val;
        }
        else {
            *isString = 1;
            strncpy(sym->cval, cval, strlen(cval));
        }
        break;
    case LEAF_NUM:
        return node->val;
        break;
    case LEAF_STR:
        *isString = 1;
        strncpy(sym->cval, cval, strlen(cval));
        break;
    case LEAF_BREAK:
        struct tNode* temp = node;
        while (temp != NULL && temp->nodeType != OP_WHILE) {
            temp = temp->parent;
        }
        if (temp == NULL) {
            printf("Error: break in a non while loop\n");
            exit(EXIT_FAILURE);
        }
        while (temp != NULL && temp->nodeType != OP_STMTLIST && temp->middle != node) {
            temp = temp->parent;
        }
        if (temp == NULL) {
            exit(EXIT_SUCCESS);
        }
        eval(temp->middle, cval, isString, symbolTable);
        break;
    case LEAF_CONTINUE:
        temp = node;
        while (temp != NULL && temp->nodeType != OP_WHILE) {
            temp = temp->parent;
        }
        if (temp == NULL) {
            printf("Error: break in a non while loop\n");
            exit(EXIT_FAILURE);
        }
        eval(temp, cval, isString, symbolTable);
        break;
    case LEAF_ARR:
        sym = getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("Error: variable %s has not been declared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        int offs = getArrayOffset(node, sym, symbolTable);
        if (sym->type->code == LEAF_TYPE_STR) {
            isString = 1;
            strncpy(cval, sym->acval[offs], strlen(sym->acval[offs]));
            return -1;
        }
        return sym->aval[offs];
        break;
    default:
    }
    return -1;
}

int getArrayOffset(struct tNode* node, struct symbol* sym, struct symbol* symbolTable) {
    int* indices = malloc(sizeof(int) * sym->type->depth);
    int depth = 0;
    getArrayIndices(node->middle, indices, &depth, symbolTable);
    int offs = 0;
    int prod = 1;
    for (int i = 0;i < depth;i++) {
        offs += indices[i] * prod;
        prod *= sym->maxSizes[i];
    }
    return offs;
}

void getArrayIndices(struct tNode* braceRoot, int* indices, int* i, struct symbol* symbolTable) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        int isString = 0;
        indices[*i] = eval(braceRoot, NULL, &isString, symbolTable);
        *i = (*i) + 1;
        return;
    }

    getArrayIndices(braceRoot->left, indices, i, symbolTable);
    getArrayIndices(braceRoot->middle, indices, i, symbolTable);
}

int eval(struct tNode* root, char* cval, int* isString, struct symbol* symbolTable) {
    if (root == NULL) {
        *isString = 0;
        return -1;
    }

    if (isLeaf(root->nodeType)) {
        return leafCodeEval(root, cval, symbolTable, isString);
    }

    int val1 = eval(root->left, cval, isString, symbolTable);

    if (isConditionalStmt(root->nodeType)) {
        operatorEval(root, val1, -1, NULL, symbolTable);
    }
    else {
        int val2 = eval(root->middle, cval, isString, symbolTable);
        eval(root->right, cval, isString, symbolTable);
        operatorEval(root, val1, val2, cval, symbolTable);
    }
}
