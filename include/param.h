#ifndef PARAM_H 
#define PARAM_H 

#include "type.h"

struct param {
    struct type* type;
    struct param* next;
    char name[100];
};

struct param* makeParam(struct type* type, char* varName);
struct param* addParam(struct param* paramList, struct param* param);
struct param* convertTreeToParamList(struct tNode* paramRoot, int* numberOfParam, struct param* paramList);
struct param* getParam(struct param* paramList, char* varName);
int getParamLen(struct param* paramList);
void printParamList(struct param* paramList);

#endif 