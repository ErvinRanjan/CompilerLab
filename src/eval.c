#include "tree.h"
#include "symbol.h"
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

int BREAK = 0;

int operatorEval(struct tNode* node, char* buf, struct symbol* symbolTable) {
    int isString = 0, val;
    char cval[100];
    struct symbol* sym;
    switch (node->nodeType) {
    case OP_READ:
        scanf("%s", buf);
        sym = node->left->nodeType == LEAF_ARR ? getSymbolTable(node->left->left->varName, symbolTable) : getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("No such symbol found\n");
            exit(EXIT_FAILURE);
        }
        if (sym->type->depth != 0) {
            int offs = getArrayOffset(node->left, sym, symbolTable);
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->aval[offs] = atoi(buf);
            }
            else {
                strncpy(sym->acval[offs], buf, strlen(buf));
            }
        }
        else {
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->val = atoi(buf);
            }
            else {
                strncpy(sym->cval, buf, strlen(buf));
            }
        }
        break;
    case OP_WRITE:
        int val = evalExpr(node->left, symbolTable, cval, &isString);
        if (isString) {
            printf("%s\n", cval);
        }
        else {
            printf("%d\n", val);
        }
        break;
    case OP_ASSIGN:
        sym = node->left->nodeType == LEAF_ARR ? getSymbolTable(node->left->left->varName, symbolTable) : getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("No such symbol found\n");
            exit(EXIT_FAILURE);
        }
        val = evalExpr(node->middle, symbolTable, buf, &isString);
        if (sym->type->depth != 0) {
            int offs = getArrayOffset(node->left, sym, symbolTable);
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->aval[offs] = val;
            }
            else {
                strncpy(sym->acval[offs], buf, strlen(buf));
            }
        }
        else {
            if (sym->type->code == LEAF_TYPE_INT) {
                sym->val = val;
            }
            else {
                strncpy(sym->cval, buf, strlen(buf));
            }
        }
        break;
    case OP_IF:
        val = evalExpr(node->left, symbolTable, cval, &isString);
        if (val) {
            interpret(node->middle, symbolTable);
        }
        else {
            interpret(node->right, symbolTable);
        }
        break;
    case OP_WHILE:
        while (evalExpr(node->left, symbolTable, cval, &isString)) {
            interpret(node->middle, symbolTable);
            if (BREAK) {
                BREAK = 0;
                break;
            }
        }
        break;
    case OP_DO_WHILE:
        interpret(node->left, symbolTable);
        while (evalExpr(node->middle, symbolTable, cval, &isString)) {
            interpret(node->left, symbolTable);
            if (BREAK) {
                BREAK = 0;
                break;
            }
        }
        break;
    case OP_REPEAT_UNTIL:
        interpret(node->left, symbolTable);
        while (!evalExpr(node->middle, symbolTable, cval, &isString)) {
            interpret(node->left, symbolTable);
            if (BREAK) {
                BREAK = 0;
                break;
            }
        }
        break;
    default:
    }
}

struct tNode* findNext(struct tNode* cur, struct symbol* symbolTable) {
    if (cur == NULL || cur->nodeType == LEAF_CONTINUE || BREAK) return NULL;

    if (cur->nodeType == LEAF_BREAK) {
        BREAK = 1;
        return NULL;
    }

    while (cur->parent != NULL && cur->parent->nodeType == OP_STMTLIST && cur->parent->left != cur) {
        cur = cur->parent;
    }

    if (cur->parent == NULL || cur->parent->nodeType != OP_STMTLIST) {
        return NULL;
    }

    return cur->parent->middle;
}

int leafCodeEval(struct tNode* node, char* cval, struct symbol* symbolTable, int* isString) {
    *isString = 0;
    struct tNode* temp, * next;
    switch (node->nodeType) {
    case LEAF_ID:
        struct symbol* sym = getSymbolTable(node->varName, symbolTable);
        if (sym->type->code == LEAF_TYPE_INT) {
            return sym->val;
        }
        else {
            *isString = 1;
            strncpy(sym->cval, cval, strlen(cval));
        }
        break;
    case LEAF_NUM:
        return node->val;
        break;
    case LEAF_STR:
        *isString = 1;
        strncpy(sym->cval, cval, strlen(cval));
        break;
    case LEAF_ARR:
        sym = getSymbolTable(node->left->varName, symbolTable);
        if (sym == NULL) {
            printf("Error: variable %s has not been declared\n", node->left->varName);
            exit(EXIT_FAILURE);
        }
        int offs = getArrayOffset(node, sym, symbolTable);
        if (sym->type->code == LEAF_TYPE_STR) {
            isString = 1;
            strncpy(cval, sym->acval[offs], strlen(sym->acval[offs]));
            return -1;
        }
        return sym->aval[offs];
        break;
    default:
    }
    return -1;
}

int getArrayOffset(struct tNode* node, struct symbol* sym, struct symbol* symbolTable) {
    int* indices = malloc(sizeof(int) * sym->type->depth);
    int depth = 0;
    getArrayIndices(node->middle, indices, &depth, symbolTable);
    int offs = 0;
    int prod = 1;
    for (int i = 0;i < depth;i++) {
        offs += indices[i] * prod;
        prod *= sym->maxSizes[i];
    }
    return offs;
}

void getArrayIndices(struct tNode* braceRoot, int* indices, int* i, struct symbol* symbolTable) {
    if (braceRoot == NULL) return;

    if (braceRoot->nodeType != OP_BRACELIST) {
        int isString = 0;
        indices[*i] = evalExpr(braceRoot, symbolTable, NULL, &isString);
        *i = (*i) + 1;
        return;
    }

    getArrayIndices(braceRoot->left, indices, i, symbolTable);
    getArrayIndices(braceRoot->middle, indices, i, symbolTable);
}

struct tNode* findFirst(struct tNode* stmtList) {
    if (stmtList == NULL || stmtList->nodeType != OP_STMTLIST) return NULL;
    while (stmtList->left != NULL && stmtList->left->nodeType == OP_STMTLIST) {
        stmtList = stmtList->left;
    }
    return stmtList->nodeType == OP_STMTLIST ? stmtList->left : stmtList;
}

int evalExpr(struct tNode* expr, struct symbol* symbolTable, char* cval, int* isString) {
    if (isLeaf(expr->nodeType)) {
        return leafCodeEval(expr, cval, symbolTable, isString);
    }
    int val1 = evalExpr(expr->left, symbolTable, cval, isString);
    int val2 = evalExpr(expr->middle, symbolTable, cval, isString);
    struct symbol* sym = NULL;
    switch (expr->nodeType) {
    case OP_ADD:
        return val1 + val2;
        break;
    case OP_SUB:
        return val1 - val2;
        break;
    case OP_MUL:
        return val1 * val2;
        break;
    case OP_DIV:
        return val1 / val2;
        break;
    case OP_MOD:
        return val1 % val2;
        break;
    case OP_GT:
        return val1 > val2;
        break;
    case OP_LT:
        return val1 < val2;
        break;
    case OP_GE:
        return val1 >= val2;
        break;
    case OP_LE:
        return val1 <= val2;
        break;
    case OP_EQ:
        return val1 == val2;
        break;
    case OP_NE:
        return val1 != val2;
        break;
    case OP_REF:
        sym = getSymbolTable(expr->left->varName, symbolTable);
        return sym->binding;
    default:
    }
    return -1;
}

void printStmt(struct tNode* stmt) {
    if (stmt == NULL) return;
    switch (stmt->nodeType) {
    case OP_READ:
        printf("read( ");
        printf("%s", stmt->left->nodeType == LEAF_ARR ? stmt->left->left->varName : stmt->left->varName);
        printf(" )\n");
        break;
    case OP_WRITE:
        printf("write( ");
        printExpr(stmt->left);
        printf(")\n");
        break;
    case OP_ASSIGN:
        printExpr(stmt->left);
        printf("= ");
        printExpr(stmt->middle);
        printf("\n");
        break;
    case OP_IF:
        printf("if( ");
        printExpr(stmt->left);
        printf(")\n");
        break;
    case OP_WHILE:
        printf("while( ");
        printExpr(stmt->left);
        printf(")\n");
        break;
    case OP_DO_WHILE:
        printf("do-while( ");
        printExpr(stmt->middle);
        printf(")\n");
        break;
    case OP_REPEAT_UNTIL:
        printf("repeat-until( ");
        printExpr(stmt->middle);
        printf(")\n");
        break;
    case LEAF_BREAK:
        printf("break\n");
        break;
    case LEAF_CONTINUE:
        printf("continue\n");
        break;
    default:
    }
}

void printExpr(struct tNode* expr) {
    if (expr == NULL) return;

    if (expr->nodeType == LEAF_ID) {
        printf("%s ", expr->varName);
        return;
    }

    if (expr->nodeType == LEAF_NUM) {
        printf("%d ", expr->val);
        return;
    }

    if (expr->nodeType == LEAF_STR) {
        printf("%s ", expr->stringVal);
        return;
    }

    if (expr->nodeType == LEAF_ARR) {
        printf("%s ", expr->left->varName);
        return;
    }

    if (expr->nodeType == LEAF_TUPLE_ACCESS) {
        printExpr(expr->left);
        printf(". ");
        printExpr(expr->middle);
        return;
    }

    if (expr->nodeType != OP_DREF && expr->nodeType != OP_REF) {
        printExpr(expr->left);
    }

    struct symbol* sym = NULL;
    switch (expr->nodeType) {
    case OP_ADD:
        printf("+ ");
        break;
    case OP_SUB:
        printf("- ");
        break;
    case OP_MUL:
        printf("* ");
        break;
    case OP_DIV:
        printf("/ ");
        break;
    case OP_MOD:
        printf("% ");
        break;
    case OP_GT:
        printf("> ");
        break;
    case OP_LT:
        printf("< ");
        break;
    case OP_GE:
        printf(">= ");
        break;
    case OP_LE:
        printf("<= ");
        break;
    case OP_EQ:
        printf("== ");
        break;
    case OP_NE:
        printf("!= ");
        break;
    case OP_REF:
        printf("& ");
        printExpr(expr->left);
        break;
    case OP_DREF:
        printf("* ");
        printExpr(expr->left);
        break;
    default:
    }

    printExpr(expr->middle);
}


void fprintStmt(FILE* out, struct tNode* stmt) {
    if (stmt == NULL) return;
    switch (stmt->nodeType) {
    case OP_READ:
        fprintf(out, "read( ");
        fprintf(out, "%s", stmt->left->nodeType == LEAF_ARR ? stmt->left->left->varName : stmt->left->varName);
        fprintf(out, " )\n");
        break;
    case OP_WRITE:
        fprintf(out, "write( ");
        fprintExpr(out, stmt->left);
        fprintf(out, ")\n");
        break;
    case OP_ASSIGN:
        fprintExpr(out, stmt->left);
        fprintf(out, "= ");
        fprintExpr(out, stmt->middle);
        fprintf(out, "\n");
        break;
    case OP_IF:
        fprintf(out, "if( ");
        fprintExpr(out, stmt->left);
        fprintf(out, ")\n");
        break;
    case OP_WHILE:
        fprintf(out, "while( ");
        fprintExpr(out, stmt->left);
        fprintf(out, ")\n");
        break;
    case OP_DO_WHILE:
        fprintf(out, "do-while( ");
        fprintExpr(out, stmt->middle);
        fprintf(out, ")\n");
        break;
    case OP_REPEAT_UNTIL:
        fprintf(out, "repeat-until( ");
        fprintExpr(out, stmt->middle);
        fprintf(out, ")\n");
        break;
    case LEAF_BREAK:
        fprintf(out, "break\n");
        break;
    case LEAF_CONTINUE:
        fprintf(out, "continue\n");
        break;
    case OP_RETURN:
        fprintf(out, "return ");
        fprintExpr(out, stmt->left);
        fprintf(out, "\n");
    default:
    }
}

void fprintfArr(FILE* out, struct tNode* braceRoot) {
    if (braceRoot == NULL) return;

    fprintf(out, "[ ");
    if (braceRoot->nodeType != OP_BRACELIST) {
        fprintExpr(out, braceRoot);
        fprintf(out, "] ");
        return;
    }

    fprintfArr(out, braceRoot->left);
    fprintfArr(out, braceRoot->middle);
}

void fprintfFunc(FILE* out, struct tNode* argList) {
    if (argList == NULL) return;

    if (argList->nodeType != OP_ARGLIST) {
        fprintExpr(out, argList);
        return;
    }

    fprintfFunc(out, argList->left);
    fprintfFunc(out, argList->middle);
}

void fprintExpr(FILE* out, struct tNode* expr) {
    if (expr == NULL) return;

    if (expr->nodeType == LEAF_ID) {
        fprintf(out, "%s ", expr->varName);
        return;
    }

    if (expr->nodeType == LEAF_NUM) {
        fprintf(out, "%d ", expr->val);
        return;
    }

    if (expr->nodeType == LEAF_STR) {
        fprintf(out, "%s ", expr->stringVal);
        return;
    }

    if (expr->nodeType == LEAF_ARR) {
        fprintf(out, "%s ", expr->left->varName);
        fprintfArr(out, expr->middle);
        return;
    }

    if (expr->nodeType == LEAF_TUPLE_ACCESS) {
        fprintExpr(out, expr->left);
        fprintf(out, ". ");
        fprintExpr(out, expr->middle);
        return;
    }

    if (expr->nodeType == LEAF_FUNC) {
        fprintExpr(out, expr->left);
        fprintf(out, "( ");
        fprintfFunc(out, expr->middle);
        fprintf(out, ") ");
        return;
    }

    if (expr->nodeType == LEAF_SELF) {
        fprintf(out, "self ");
        return;
    }

    if (expr->nodeType != OP_DREF && expr->nodeType != OP_REF) {
        fprintExpr(out, expr->left);
    }

    struct symbol* sym = NULL;
    switch (expr->nodeType) {
    case OP_ADD:
        fprintf(out, "+ ");
        break;
    case OP_SUB:
        fprintf(out, "- ");
        break;
    case OP_MUL:
        fprintf(out, "* ");
        break;
    case OP_DIV:
        fprintf(out, "/ ");
        break;
    case OP_MOD:
        fprintf(out, "% ");
        break;
    case OP_GT:
        fprintf(out, "> ");
        break;
    case OP_LT:
        fprintf(out, "< ");
        break;
    case OP_GE:
        fprintf(out, ">= ");
        break;
    case OP_LE:
        fprintf(out, "<= ");
        break;
    case OP_EQ:
        fprintf(out, "== ");
        break;
    case OP_NE:
        fprintf(out, "!= ");
        break;
    case OP_REF:
        fprintf(out, "& ");
        fprintExpr(out, expr->left);
        break;
    case OP_DREF:
        fprintf(out, "* ");
        fprintExpr(out, expr->left);
        break;
    default:
    }

    fprintExpr(out, expr->middle);
}

void interpret(struct tNode* stmtList, struct symbol* symbolTable) {
    if (stmtList == NULL) return;
    struct tNode* stmt = findFirst(stmtList);
    char buf[100];
    while (stmt != NULL) {
        // printStmt(stmt);
        operatorEval(stmt, buf, symbolTable);
        stmt = findNext(stmt, symbolTable);
    }
}