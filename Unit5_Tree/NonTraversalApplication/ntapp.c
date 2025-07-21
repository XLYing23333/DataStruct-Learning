// 二叉树的非递归中序遍历
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "BtTree.h"

#define STACKSIZE 100

BinaryTree CreateDemoTree() {
    BinaryTree a, b, x, y, z;
    InitTree(&a); InitTree(&b);  // Create Empty root
    InitTree(&x); InitTree(&y); InitTree(&z); 
    MakeTree(&y, 'D', &a, &b);
    MakeTree(&z, 'E', &a, &b);
    MakeTree(&x, 'C', &y, &z);
    MakeTree(&y, 'B', &a, &b);
    MakeTree(&z, 'A', &y, &x);
    return z;
}

// 获取中序遍历规则下待访问的第一个node
BTNode* GetFirst(BinaryTree *tree, Stack *S) {
    BTNode *node = tree->root;
    if(!node) {
        // 如果树为空，则返回NULL
        return NULL;
    }
    while(node->left_c != NULL) {
        Push(S, node);
        node = node->left_c;
    }
    return node;
}

// 获取current node在中序遍历规则下的下一个node
BTNode* GetNext(BTNode *current, Stack *S) {
    BTNode *node;
    if (current->right_c!=NULL) {
        node = current->right_c;
        while(node->left_c!=NULL) {
            Push(S, node);
            node = node->left_c;
        }
        current = node;
    }
    else if(!IsEmpty(S)){
        Pop(S, &current);
    }
    else {
        current = NULL;
        return NULL;
    }
    return current;
}

// 按照中序遍历的规则非递归遍历二叉树中所有的节点
Status Traverse(BinaryTree *tree) {
    Stack S;
    BTNode *current;
    InitStack(&S, STACKSIZE);
    current = GetFirst(tree, &S);
    printf("Inorder traversal result: ");
    while(current) {
        printf("%c", current->data);
        current = GetNext(current, &S);
    }
    printf("\n");
}




int main() {
    BinaryTree tree = CreateDemoTree();
    Traverse(&tree);
    return 0;
}