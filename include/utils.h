#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdarg.h>

void strip(char* dest, char* src, char ch);
char* safeStrcpy(char* src);
void cprintf(FILE* out, char* fmt, ...);
int getLines();

#endif