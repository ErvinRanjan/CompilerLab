#include "tree.h"
#include <stdio.h>

void print(struct tNode* root) {
    switch (root->nodeType) {
    case LEAF_ID: printf("%s ", root->varName); break;
    case LEAF_NUM: printf("%d ", root->val); break;
    case OP_ADD: printf("+ "); break;
    case OP_SUB: printf("- "); break;
    case OP_MUL: printf("* "); break;
    case OP_DIV: printf("/ "); break;
    default:
    }
}

void preorder(struct tNode* root) {
    if (root == NULL) return;
    print(root);
    preorder(root->left);
    preorder(root->middle);
}

void postorder(struct tNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->middle);
    print(root);
}