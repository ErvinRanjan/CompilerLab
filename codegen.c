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
void operatorCodeGen(FILE* out, int nodeType, int reg1, int reg2, int reg3, char* varName, int label1, int label2, int next, struct tNode* parent, struct symbol* symbolTable) {
    int addr = -1;
    switch (nodeType) {
    case OP_ADD:
        fprintf(out, "ADD R%d, R%d\n", reg1, reg2);
        break;
    case OP_SUB:
        fprintf(out, "SUB R%d, R%d\n", reg1, reg2);
        break;
    case OP_MUL:
        fprintf(out, "MUL R%d, R%d\n", reg1, reg2);
        break;
    case OP_DIV:
        fprintf(out, "DIV R%d, R%d\n", reg1, reg2);
        break;
    case OP_READ:
        addr = getMem(varName, symbolTable);
        libRead(out, XSM_STDIN, addr);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        break;
    case OP_ASSIGN:
        addr = getMem(varName, symbolTable);
        fprintf(out, "MOV [%d], R%d\n", addr, reg2);
        break;
    case OP_IF:
        fprintf(out, "JNZ R%d, L%d\n", reg1, label1);
        fprintf(out, "JMP L%d\n", label2);
        break;
    case OP_WHILE:
        fprintf(out, "JZ R%d, L%d\n", reg1, next);
        break;
    case OP_GT:
        fprintf(out, "GT R%d, R%d\n", reg1, reg2);
        break;
    case OP_LT:
        fprintf(out, "LT R%d, R%d\n", reg1, reg2);
        break;
    case OP_GE:
        fprintf(out, "GE R%d, R%d\n", reg1, reg2);
        break;
    case OP_LE:
        fprintf(out, "LE R%d, R%d\n", reg1, reg2);
        break;
    case OP_EQ:
        fprintf(out, "EQ R%d, R%d\n", reg1, reg2);
        break;
    case OP_NE:
        fprintf(out, "NE R%d, R%d\n", reg1, reg2);
        break;
    case OP_STMTLIST:
        if (parent != NULL) {
            if (parent->nodeType == OP_IF) {
                fprintf(out, "JMP L%d\n", next);
            }
            else if (parent->nodeType == OP_WHILE) {
                fprintf(out, "JMP L%d\n", parent->label);
            }
        }
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
int libRead(FILE* out, int fileDescriptor, int addr) {
    int reg = getReg();

    fprintf(out, "MOV R%d, \"Read\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "MOV R%d, %d\n", reg, fileDescriptor);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "MOV R%d, %d\n", reg, addr);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "CALL 0\n");
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "POP R%d\n", reg);
    fprintf(out, "MOV R%d, [%d]\n", reg, addr);

    return reg;
}

/**
 * @brief generates XSM machine code for library write
 * @param regNum register
 * @param fileDescriptor file descriptor to write to
 */
void libWrite(FILE* out, int regNum, int fileDescriptor) {
    int reg = getReg();

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
    int reg = getReg();

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
int leafCodeGen(FILE* out, int nodeType, char* varName, int val, char* stringVal, int next, struct symbol* symbolTable) {
    int reg = -1;
    switch (nodeType) {
    case LEAF_ID:
        reg = getReg();
        int addr = getMem(varName, symbolTable);
        fprintf(out, "MOV R%d, [%d]\n", reg, addr);
        break;
    case LEAF_NUM:
        reg = getReg();
        fprintf(out, "MOV R%d, %d\n", reg, val);
        break;
    case LEAF_STR:
        reg = getReg();
        fprintf(out, "MOV R%d, %s\n", reg, stringVal);
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
    default:
    }
    return reg;
}

bool isLeaf(int nodeType) {
    return nodeType == LEAF_ID || nodeType == LEAF_NUM || nodeType == LEAF_BREAK || nodeType == LEAF_CONTINUE || nodeType == LEAF_STR || nodeType == LEAF_TYPE_INT || nodeType == LEAF_TYPE_STR;
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

    if (isStmt(root->nodeType)) {
        if (root->nodeType == OP_WHILE) {
            push(beginLabelStack, createGeneric(LEAF_TYPE_INT, &(root->label)));
            push(nextLabelStack, createGeneric(LEAF_TYPE_INT, &next));
        }
        fprintf(out, "L%d:\n", root->label);
    }

    if (isLeaf(root->nodeType)) {
        return leafCodeGen(out, root->nodeType, root->varName, root->val, root->stringVal, next, symbolTable);
    }

    int label1 = root->middle != NULL ? root->middle->label : next;
    int label2 = root->right != NULL ? root->right->label : next;

    int reg1 = codeGenHelper(out, root->left, root->nodeType == OP_STMTLIST ? root->middle->label : next, root, symbolTable);

    if (isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root->nodeType, reg1, -1, -1, root->left->varName, label1, label2, next, parent, symbolTable);
    }

    int reg2 = codeGenHelper(out, root->middle, root->nodeType == OP_WHILE ? root->label : next, root, symbolTable);
    int reg3 = codeGenHelper(out, root->right, next, root, symbolTable);

    if (!isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root->nodeType, reg1, reg2, reg3, root->left->varName, label1, label2, next, parent, symbolTable);
        freeReg();
    }

    if (root->nodeType == OP_WHILE) {
        pop(beginLabelStack);
        pop(nextLabelStack);
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
