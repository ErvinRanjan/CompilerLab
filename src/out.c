#include "out.h"

FILE* outStream = NULL;

void setOutputStream(FILE* out) {
    outStream = out;
}

FILE* getOutputStream() {
    return outStream;
}