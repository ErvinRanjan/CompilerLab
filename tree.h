struct tNode {
    int val, isLeaf;
    char op[3];
    struct tNode* left, * right;
};

struct tNode* createLeafNode(int val);
struct tNode* createOperatorNode(char* op, struct tNode* left, struct tNode* right);




