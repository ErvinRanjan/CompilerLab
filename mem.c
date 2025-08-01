#include "mem.h"

/**
 * @brief get memory address from stack if not allocated a new address is allocated
 * @param varName variable name for which address has to be fetched
 * @return memory address from stack
 */
int getMem(char* varName) {
    return 4096 + (*varName - 'a');
}