#ifndef _BTTREE_H
#define _BTTREE_H

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

Status InitTree(BinaryTree *bt);
BTNode * NewNode(ElemType val, BTNode *left_node, BTNode *right_node);
Status GetRootVal(BinaryTree *bt, ElemType *val);
Status MakeTree(BinaryTree *bt, ElemType val, 
                BinaryTree *left_tree, BinaryTree *right_tree);
Status PreOrderNode(BTNode *node);
Status PreOrderTree(BinaryTree *bt);
Status InOrderNode(BTNode *node);
Status InOrderTree(BinaryTree *bt);
Status PostOrderNode(BTNode *node);
Status PostOrderTree(BinaryTree *bt);

#endif