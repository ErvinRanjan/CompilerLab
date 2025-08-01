#include "codegen.h"
#include "reg.h"
#include "constants.h"
#include "mem.h"
#include <stdio.h>
#include <string.h>


/**
 * @brief generates machine code for operators
 * @param out output file pointer
 * @param nodeType type of the node
 * @param reg1 register one
 * @param reg2 register two
 * @param varName variable name in case of assigning or reading
 */
void operatorCodeGen(FILE* out, int nodeType, int reg1, int reg2, char* varName) {
    int addr = getMem(varName);
    switch (nodeType) {
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
    case OP_READ:
        libRead(out, XSM_STDIN, addr);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        break;
    case OP_ASSIGN:
        fprintf(out, "MOV [%d], R%d\n", addr, reg2);
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

    int regs = pushContext(out);
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
    popContext(out, regs);

    return reg;
}

/**
 * @brief generates XSM machine code for library write
 * @param regNum register
 * @param fileDescriptor file descriptor to write to
 */
void libWrite(FILE* out, int regNum, int fileDescriptor) {
    int reg = getReg();

    int regs = pushContext(out);
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

    popContext(out, regs);

    freeReg();
}

/**
 * @brief generates XSM machine code for exit
 * @param out output file pointer
 */
void libExit(FILE* out) {
    int reg = getReg();

    int regs = pushContext(out);

    fprintf(out, "MOV R%d, \"Exit\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "CALL 0\n");

    popContext(out, regs);

    freeReg();
}

/**
 * @brief generates machine code for leafs of Abstract syntax tree
 * @param out output file pointer
 * @param varName optional - only for identifiers
 * @param val optional - value for numbers
 */
int leafCodeGen(FILE* out, int nodeType, char* varName, int val) {
    int reg = getReg();
    switch (nodeType) {
    case LEAF_ID:
        int addr = getMem(varName);
        fprintf(out, "MOV R%d, [%d]\n", reg, addr);
        break;
    case LEAF_NUM:
        fprintf(out, "MOV R%d, %d\n", reg, val);
        break;
    default:
    }
    return reg;
}

/**
 * @brief recursively iterates through Abstract Syntax Tree (AST) and generates machine code
 *  @param out output file pointer
 * @param root root of AST
 * @return register where result is stored if any
 */
int codeGenHelper(FILE* out, struct tNode* root) {
    if (root == NULL) {
        return -1;
    }

    if (root->nodeType == LEAF_ID || root->nodeType == LEAF_NUM) {
        return leafCodeGen(out, root->nodeType, root->varName, root->val);
    }

    int reg1 = codeGenHelper(out, root->left);
    int reg2 = codeGenHelper(out, root->right);
    operatorCodeGen(out, root->nodeType, reg1, reg2, root->left->varName);
    return reg1;
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
int codeGen(FILE* out, struct tNode* root) {
    generateHeader(out, 0, ENTRY_POINT, 0, 0, 0, 0, 0);
    initParams(out);
    codeGenHelper(out, root);
    libExit(out);
}
