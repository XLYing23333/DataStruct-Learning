#include "Queue.h"
#include "BtTree.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100

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


Status LevelOrder(BinaryTree *tree) {
    if (!tree->root) { // Tree IsEmpty
        printf("{LevelOrder} \033[31m[ERR]\033[0m Empty Queue.\n");
        return ERR;
    }
    Queue Q;
    InitQueue(&Q, QUEUESIZE);
    BTNode *node = tree->root;
    EnQueue(&Q, node); // root enqueue
    printf("{LevelOrder} Order: ");
    while (!IsEmpty(&Q)) {  // Q[Queue] IsEmpty
        DeQueue(&Q, &node);  // Or GetFront + DeQueue
        printf("%c", node->data);
        if (node->left_c) {
            EnQueue(&Q, node->left_c);
        }
        if (node->right_c) {
            EnQueue(&Q, node->right_c);
        }
    }
    printf("\n");
    DestroyQueue(&Q);
}

int main() {
    BinaryTree demo_tree = CreateDemoTree();
    BinaryTree empty_tree;
    InitTree(&empty_tree);
    LevelOrder(&empty_tree);
    LevelOrder(&demo_tree);

    return 0;
}