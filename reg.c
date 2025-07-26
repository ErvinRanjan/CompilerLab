#include "reg.h"
#include <stdio.h>
#include <stdlib.h>

int regIndex = 0;

int getReg() {
    int reg = regIndex++;
    if (reg >= 20) {
        printf("Error: Ran out of registers\n");
        exit(EXIT_FAILURE);
    }
    return reg;
}

void freeReg() {
    if (regIndex == 0) {
        printf("Error: No register to free\n");
        exit(EXIT_FAILURE);
    }
    regIndex--;
}
