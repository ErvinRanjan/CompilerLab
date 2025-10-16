/**
 * @brief header file used to generate XSM machine code
 */

#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include "symbol.h"
#include <stdio.h>

int libRead(FILE* out, int fileDescriptor, int addr);
void libWrite(FILE* out, int data, int fileDescriptor);
void libExit(FILE* out);
void codeGen(FILE* out, struct tNode* root, struct symbol* symbolTable);
void populateParent(struct tNode* root);
void initCompiler(FILE* out);
void funcCodeGen(FILE* out, char* funcName, struct tNode* root, struct symbol* symbolTable, int classIndex);
void printNode(struct tNode* node);

#endif