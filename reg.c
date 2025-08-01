#include "reg.h"
#include <stdio.h>
#include <stdlib.h>

int regIndex = 0;

/**
 * @brief used to save all registers
 * @param out output file pointer
 */
int pushContext(FILE* out) {
    for (int i = 0;i < regIndex;i++) {
        fprintf(out, "PUSH R%d\n", i);
    }
    return regIndex;
}

/**
 * @brief restores saved values of registers
 * @param out output file pointer
 * @param till register till which we must restore context
 */
void popContext(FILE* out, int till) {
    for (int i = 0;i < till;i++) {
        fprintf(out, "POP R%d\n", i);
    }
}

/**
 * @brief gets the min index register available
 */
int getReg() {
    int reg = regIndex++;
    if (reg >= 20) {
        printf("Error: Ran out of registers\n");
        exit(EXIT_FAILURE);
    }
    return reg;
}

/**
 * @brief frees the max index register used
 */
void freeReg() {
    if (regIndex == 0) {
        printf("Error: No register to free\n");
        exit(EXIT_FAILURE);
    }
    regIndex--;
}
