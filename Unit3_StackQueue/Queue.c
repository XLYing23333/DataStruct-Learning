/*
注意！此处适用于C版811数据机构，与王道版本有所差距
其中循环队列牺牲的元素为第一个位置
front指向队首的前一个元素
rear指向队尾
判满条件同王道数据结构相同
*/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int BOOL;
typedef int ElemType;

typedef struct {
    ElemType *data;
    int front;
    int rear;
    int maxsize;
} Queue;

// 初始化队列
Status InitQueue(Queue *Q, int maxsize) {
    Q->data = (ElemType*)malloc(sizeof(ElemType)*maxsize);
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
Status EnQueue(Queue *Q, ElemType val) {
    if (IsFull(Q)) {
        printf("{EnQueue} \033[31m[ERR]\033[0m Full Queue.\n");
        return ERR;
    }
    Q->rear = (Q->rear + 1) % Q->maxsize;
    Q->data[Q->rear] = val;
    printf("{EnQueue} PUSH %d into Queue.\n", val);
    return OK;
}

// 出队
Status DeQueue(Queue *Q, ElemType *val) {
    if (IsEmpty(Q)) {
        printf("{DeQueue} \033[31m[ERR]\033[0m Empty Queue.\n");
        return ERR;
    }
    Q->front = (Q->front + 1) % Q->maxsize;
    *val = Q->data[Q->front];
    printf("{DeQueue} POP %d from Queue.\n", *val);
    return OK;
}

// 获取队首元素
Status GetFront(Queue *Q, ElemType *val) {
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


Status test() {
    Queue Q;
    int val;
    InitQueue(&Q, 5);
    DeQueue(&Q, &val);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    GetFront(&Q, &val);
    DeQueue(&Q, &val);
    DeQueue(&Q, &val);
    ClearQueue(&Q);
    GetFront(&Q, &val);
    DestroyQueue(&Q);

    return OK;
}


int main() {
    test();
    return 0;
}