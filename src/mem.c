#include "mem.h"
#include "constants.h"
#include "stdio.h"
#include <stdlib.h>

int mem = 4096;

int getFreeMem(int size) {
    if ((mem - MEM_START + size) >= MAX_STACK_SPACE) {
        printf("Error: cannot get free memory\n");
        exit(EXIT_FAILURE);
    }
    int prev = mem;
    mem += size;
    return prev;
}

void freeMem(int size) {
    if (mem - size < 4096) {
        printf("Error: no memory to free\n");
        exit(EXIT_FAILURE);
    }
    mem -= size;
}

int getMemPointer() {
    return mem;
}