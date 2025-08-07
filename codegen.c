#include "codegen.h"
#include "reg.h"
#include "constants.h"
#include "mem.h"
#include "label.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isNotConditionalStmt(int nodeType) {
    return nodeType == OP_READ || nodeType == OP_WRITE || nodeType == OP_ASSIGN;
}

bool isConditionalStmt(int nodeType) {
    return nodeType == OP_IF || nodeType == OP_WHILE;
}

bool isStmt(int nodeType) {
    return isConditionalStmt(nodeType) || isNotConditionalStmt(nodeType);
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
void operatorCodeGen(FILE* out, int nodeType, int reg1, int reg2, int reg3, char* varName, int label1, int label2, int label3, int next, struct tNode* parent) {
    int addr = getMem(varName);
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
        libRead(out, XSM_STDIN, addr);
        break;
    case OP_WRITE:
        libWrite(out, reg1, XSM_STDOUT);
        break;
    case OP_ASSIGN:
        fprintf(out, "MOV [%d], R%d\n", addr, reg2);
        break;
    case OP_IF:
        fprintf(out, "JNZ R%d, L%d\n", reg1, label2);
        fprintf(out, "JMP L%d\n", label3);
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
    default:
    }

    if (nodeType == OP_STMTLIST && parent != NULL) {
        if (parent->nodeType == OP_IF) {
            fprintf(out, "JMP L%d\n", next);
        }
        else if (parent->nodeType == OP_WHILE) {
            fprintf(out, "JMP L%d\n", parent->label);
        }
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
 * @return register where result is stored
 */
int codeGenHelper(FILE* out, struct tNode* root, int next, struct tNode* parent) {
    if (root == NULL) {
        return -1;
    }

    if (root->nodeType == LEAF_ID || root->nodeType == LEAF_NUM) {
        return leafCodeGen(out, root->nodeType, root->varName, root->val);
    }


    int label1 = root->label;
    int label2 = root->middle != NULL ? root->middle->label : next;
    int label3 = root->right != NULL ? root->right->label : next;

    if (isStmt(root->nodeType)) {
        fprintf(out, "L%d:\n", root->label);
    }

    int reg1 = codeGenHelper(out, root->left, root->nodeType == OP_STMTLIST ? root->middle->label : next, root);

    if (isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root->nodeType, reg1, -1, -1, root->left->varName, label1, label2, label3, next, parent);
    }

    int reg2 = codeGenHelper(out, root->middle, next, root);
    int reg3 = codeGenHelper(out, root->right, next, root);

    if (!isConditionalStmt(root->nodeType)) {
        operatorCodeGen(out, root->nodeType, reg1, reg2, reg3, root->left->varName, label1, label2, label3, next, parent);
        freeReg();
    }

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
void codeGen(FILE* out, struct tNode* root) {
    generateHeader(out, 0, ENTRY_POINT, 0, 0, 0, 0, 0);
    initParams(out);
    codeGenHelper(out, root, -1, NULL);
    fprintf(out, "L%d:\n", -1);
    libExit(out);
}
