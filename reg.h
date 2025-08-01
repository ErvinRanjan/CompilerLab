/**
 *  @brief header file to handle register allocation, retrieval ...
 */

#ifndef REG_H
#define REG_H

#include <stdio.h>

int pushContext(FILE* out);
void popContext(FILE* out, int till);
int getReg();
void freeReg();

#endif