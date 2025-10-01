#include "reg.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "constants.h"

int regIndex = 0;

struct stack* regStack = NULL;

void backup(FILE* out) {
    if (regStack == NULL) {
        regStack = createStack(100);
    }
    push(regStack, createGeneric(LEAF_TYPE_INT, &regIndex));
    for (int i = 0;i < regIndex;i++) {
        fprintf(out, "PUSH R%d\n", i);
    }
    regIndex = 0;
}

void restore(FILE* out) {
    if (regStack == NULL || empty(regStack)) {
        printf("Error: registers have not been backed up\n");
        exit(EXIT_FAILURE);
    }
    regIndex = top(regStack).intValue;
    pop(regStack);
    for (int i = regIndex - 1;i >= 0;i--) {
        fprintf(out, "POP R%d\n", i);
    }
}

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
        printf("Error: no register to free\n");
        exit(EXIT_FAILURE);
    }
    regIndex--;
}