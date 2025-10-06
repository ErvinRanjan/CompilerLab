#include "param.h"
#include <stdlib.h>
#include <string.h>

struct param* makeParam(struct type* type, char* varName) {
    struct param* param = malloc(sizeof(struct param));
    param->type = type;
    if (varName != NULL && strlen(varName) <= 100) {
        strcpy(param->name, varName);
    }
    param->next = NULL;
    return param;
}

struct param* addParam(struct param* paramList, struct param* param) {
    if (paramList == NULL) return param;
    struct param* head = paramList;
    while (paramList->next != NULL) {
        if (strcmp(param->name, paramList->name) == 0) {
            printf("Error: repeated declaration of param: %s\n", param->name);
            exit(EXIT_FAILURE);
        }
        paramList = paramList->next;
    }
    paramList->next = param;
    return head;
}


struct param* convertTreeToParamList(struct tNode* paramRoot, int* numberOfParam, struct param* paramList) {
    if (paramRoot == NULL) return NULL;
    if (paramRoot->nodeType == OP_PARAM) {
        paramList = addParam(paramList, makeParam(createType(paramRoot->left->type->typename, paramRoot->left->type->code, paramRoot->left->type->depth + paramRoot->type->depth), paramRoot->middle->varName));
        *numberOfParam = *numberOfParam + 1;
        return paramList;
    }
    paramList = convertTreeToParamList(paramRoot->left, numberOfParam, paramList);
    paramList = convertTreeToParamList(paramRoot->middle, numberOfParam, paramList);
    return paramList;
}

struct param* getParam(struct param* paramList, char* varName) {
    while (paramList != NULL) {
        if (strcmp(paramList->name, varName) == 0) {
            return paramList;
        }
        paramList = paramList->next;
    }
    return NULL;
}

int getParamLen(struct param* param) {
    int count = 0;
    while (param != NULL) {
        param = param->next;
        count++;
    }
    return count;
}

void printParamList(struct param* paramList) {
    while (paramList != NULL) {
        printf("param type code : %d\n", paramList->type->code);
        printf("param type depth: %d\n", paramList->type->depth);
        printf("param name: %s\n", paramList->name);
        paramList = paramList->next;
    }
}