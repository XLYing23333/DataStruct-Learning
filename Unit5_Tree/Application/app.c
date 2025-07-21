#include <stdio.h>
#include <stdlib.h>
#include "BtTree.h"


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

// =============== 计算二叉树节点个数 ===============

int Size(BTNode *node) {
    if (!node) {
        return 0;
    }
    else {
        return Size(node->left_c) + Size(node->right_c) + 1;
    }
}

int TreeSize(BinaryTree *tree) {
    return Size(tree->root);
}

Status app_counter() {
    printf("\n[APP] ===== TreeSize =====\n");
    BinaryTree tree = CreateDemoTree();
    int tree_size = TreeSize(&tree);
    printf("Size of Tree: %d\n", tree_size);
    return OK;
}

// =============== 清空二叉树 ===============

Status Clear(BTNode *node) {
    if(!node) {
        return OK;
    }
    Clear(node->left_c);
    Clear(node->right_c);
    printf("{Clear} Clear node_%c\n", node->data);
    free(node);  // free node itself
}

Status TreeClear(BinaryTree *tree) {
    Clear(tree->root);
}

Status app_clear_tree() {
    printf("\n[APP] ===== TreeClear =====\n");
    BinaryTree tree = CreateDemoTree();
    TreeClear(&tree);
    return OK;
}

// =============== 先序构建二叉树 ===============

BTNode* PreCreateBt(BTNode *node) {
    char ch;
    ch = getchar();
    if (ch == '#') {
        node = NULL;
    }
    else {
        node = (BTNode *)malloc(sizeof(BTNode));
        node->data = ch;
        node->left_c = PreCreateBt(node->left_c);
        node->right_c = PreCreateBt(node->right_c);
    }
    return node;
}

Status PreMakeTree(BinaryTree *tree) {
    tree->root = PreCreateBt(tree->root);
    return OK;
}

Status app_pre_make_tree() {
    printf("\n[APP] ===== PreMakeTree =====\n");
    BinaryTree tree;
    InitTree(&tree);
    printf("PreTree > ");
    PreMakeTree(&tree);
    PreOrderTree(&tree);
    return OK;
}

// =============== MAIN ===============

int main() {
    app_counter();
    app_clear_tree();
    app_pre_make_tree();
    return 0;
}