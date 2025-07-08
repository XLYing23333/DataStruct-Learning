#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化队列
Status InitQueue(Queue *Q, int maxsize) {
    Q->data = (Q_ElemType*)malloc(sizeof(Q_ElemType)*maxsize);
    Q->front = 0;
    Q->rear = 0;
    Q->maxsize = maxsize;   
    return OK; 
}

// 判空
BOOL IsEmpty(Queue *Q) {
    if (Q->front == Q->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// 判满
BOOL IsFull(Queue *Q) {
    if (((Q->rear + 1) % Q->maxsize) == Q->front) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// 入队
Status EnQueue(Queue *Q, Q_ElemType val) {
    if (IsFull(Q)) {
        printf("{EnQueue} \033[31m[ERR]\033[0m Full Queue.\n");
        return ERR;
    }
    Q->rear = (Q->rear + 1) % Q->maxsize;
    Q->data[Q->rear] = val;
    // printf("{EnQueue} PUSH Node_'%c' into Queue.\n", val->data);
    return OK;
}

// 出队
Status DeQueue(Queue *Q, Q_ElemType *val) {
    if (IsEmpty(Q)) {
        printf("{DeQueue} \033[31m[ERR]\033[0m Empty Queue.\n");
        return ERR;
    }
    Q->front = (Q->front + 1) % Q->maxsize;
    *val = Q->data[Q->front];
    // printf("{DeQueue} POP %c from Queue.\n", (*val)->data);
    return OK;
}

// 获取队首元素
Status GetFront(Queue *Q, Q_ElemType *val) {
    if (IsEmpty(Q)) {
        printf("{GetFront} \033[31m[ERR]\033[0m Empty Queue.\n");
        return ERR;
    }
    *val = Q->data[(Q->front + 1)%Q->maxsize];
    printf("{GetFront} Queue Front is %d.\n", *val);
    return OK;
}

// 销毁队列
Status DestroyQueue(Queue *Q) {
    free(Q->data);
    Q->data = NULL;
    Q->front = -1;
    Q->rear = -1;
    Q->maxsize = 0;
    printf("{DestroyQueue} Success.\n");
    return OK;
}

// 清空队列
Status ClearQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
    printf("{ClearQueue} Success.\n");
    return OK;
}