/**
 *  @brief header file to handle register allocation, retrieval ...
 */

#ifndef REG_H
#define REG_H

#include <stdio.h>

int getFreeReg();
void freeReg();
int getReg();
void setReg(int reg);
void backup(FILE* out);
void restore(FILE* out);

#endif