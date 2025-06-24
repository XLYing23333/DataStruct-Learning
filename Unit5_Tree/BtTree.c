#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERR 0

typedef int BOOL;
typedef int Status;
typedef char ElemType;

typedef struct btnode {
    ElemType data;
    struct btnode *left_c;
    struct btnode *right_c;
} BTNode;

typedef struct {
    BTNode *root;
} BinaryTree;

Status InitTree(BinaryTree *bt){
    bt->root = NULL;
    printf("{InitTree} Init the tree Successed.\n");
    return OK;
}

BTNode * NewNode(ElemType val, BTNode *left_node, BTNode *right_node) {
    BTNode *new_node = (BTNode *)malloc(sizeof(BTNode));
    new_node->data = val;
    new_node->left_c = left_node;
    new_node->right_c = right_node;
    printf("{NewNode} Create New Node {val: %c}.\n", val);
    return new_node;
} 

Status GetRootVal(BinaryTree *bt, ElemType *val) {
    if (bt->root) {
        *val = bt->root->data;
        return OK;
    }
    else {
        printf("\n");
        return ERR;
    }
}

Status MakeTree(BinaryTree *bt, ElemType val, 
                BinaryTree *left_tree, BinaryTree *right_tree) {
    if (bt->root || left_tree == right_tree) {
        return ERR;
    }
    bt->root = NewNode(val, left_tree->root, right_tree->root);
    left_tree->root = NULL;
    right_tree->root = NULL;
    return OK;
}

Status test() {
    BinaryTree a, b, x, y, z;
    InitTree(&a);
    InitTree(&b);
    InitTree(&x);
    InitTree(&y);
    InitTree(&z);
    MakeTree(&y, 'E', &a, &b);
    MakeTree(&z, 'F', &a, &b);
    MakeTree(&x, 'C', &y, &z);
    MakeTree(&y, 'B', &a, &b);
    MakeTree(&z, 'D', &y, &x);
    return OK;
}

int main() {
    test();
    return 0;
}