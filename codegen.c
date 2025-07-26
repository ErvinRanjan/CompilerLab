#include "codegen.h"
#include "reg.h"
#include <stdio.h>
#include <string.h>

void operatorCodeGen(FILE* out, char* op, int reg1, int reg2) {
    if (strcmp(op, "+") == 0) {
        fprintf(out, "ADD R%d, R%d\n", reg1, reg2);
    }
}

void generateHeader(FILE* out, int xmagic, int entryPoint, int textSize, int dataSize, int heapSize, int stackSize, int libFlag) {
    fprintf(out, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", xmagic, entryPoint, textSize, dataSize, heapSize, stackSize, libFlag, 0);
}

int libRead(FILE* out, int fileDescriptor) {
    int reg = getReg();
    int addr = 5119; // will have to make this dynamic later  

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

    freeReg();
}

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

int codeGenHelper(FILE* out, struct tNode* root) {
    if (root == NULL) {
        return -1;
    }

    if (root->isLeaf) {
        int reg = getReg();
        fprintf(out, "MOV R%d, %d\n", reg, root->val);
        return reg;
    }

    int reg1 = codeGenHelper(out, root->left);
    int reg2 = codeGenHelper(out, root->right);
    operatorCodeGen(out, root->op, reg1, reg2);
    freeReg();

    return reg1;
}

int codeGen(FILE* out, struct tNode* root) {
    generateHeader(out, 0, 2056, 0, 0, 0, 0, 0);
    int reg = codeGenHelper(out, root);
    libWrite(out, reg, -2);
    libExit(out);
}
