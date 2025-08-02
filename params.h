/**
 * container store various information related to codeGen
 */

#ifndef PARAMS_H
#define PARAMS_H

struct params {
    int reg;
    int label;
};

struct params* makeParams(int reg, int label);

#endif

