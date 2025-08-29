#include "reg.h"
#include <stdio.h>
#include <stdlib.h>

int regIndex = 0;


int getReg() {
    return regIndex;
}

void setReg(int reg) {
    regIndex = reg;
}


/**
 * @brief gets the min index register available
 */
int getFreeReg() {
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
