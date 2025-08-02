#include "params.h"
#include <stdlib.h>

/**
 * @brief acts as a constructor for params
 */
struct params* makeParams(int reg, int label) {
    struct params* params = malloc(sizeof(struct params));
    params->reg = reg;
    params->label = label;
    return params;
}