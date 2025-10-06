#ifndef EVAL_H
#define EVAL_H

void interpret(struct tNode* stmtList, struct symbol* symbolTable);
void printStmt(struct tNode* stmt);
void fprintStmt(FILE* out, struct tNode* stmt);

#endif 