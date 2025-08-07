/**
 * @brief header file used to generate XSM machine code
 */

#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include <stdio.h>

int libRead(FILE* out, int fileDescriptor, int addr);
void libWrite(FILE* out, int data, int fileDescriptor);
void libExit(FILE* out);
void codeGen(FILE* out, struct tNode* root);

#endif