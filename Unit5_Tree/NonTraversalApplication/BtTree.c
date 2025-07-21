#include "BtTree.h"
#include <stdio.h>
#include <stdlib.h>



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

Status PreOrderNode(BTNode *node) {
    if (!node) {
        return OK;
    }
    printf("%c", node->data);
    PreOrderNode(node->left_c);
    PreOrderNode(node->right_c);
    return OK;
}

Status PreOrderTree(BinaryTree *bt) {
    printf("{PreOrderTree} Order: ");
    PreOrderNode(bt->root);
    printf("\n");
    return OK;
}

Status InOrderNode(BTNode *node) {
    if (!node) {
        return OK;
    }
    InOrderNode(node->left_c);
    printf("%c", node->data);
    InOrderNode(node->right_c);
    return OK;
}

Status InOrderTree(BinaryTree *bt) {
    printf("{InOrderTree} Order: ");
    InOrderNode(bt->root);
    printf("\n");
    return OK;
}

Status PostOrderNode(BTNode *node) {
    if (!node) {
        return OK;
    }
    PostOrderNode(node->left_c);
    PostOrderNode(node->right_c);
    printf("%c", node->data);
    return OK;
}

Status PostOrderTree(BinaryTree *bt) {
    printf("{PostOrderTree} Order: ");
    PostOrderNode(bt->root);
    printf("\n");
    return OK;
}
