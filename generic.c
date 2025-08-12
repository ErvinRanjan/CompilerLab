#include "generic.h"
#include "constants.h"
#include <stdio.h>

union generic createGeneric(int type, void* value) {
    union generic gen;
    switch (type)
    {
    case INT:
        gen.intValue = *((int*)value);
        break;
    default:
        break;
    }
    return gen;
}