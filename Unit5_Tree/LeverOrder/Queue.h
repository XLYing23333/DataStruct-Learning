#ifndef _QUEUE_H
#define _QUEUE_H

#include "BtTree.h"

#define OK 1
#define ERR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int BOOL;
typedef BTNode* Q_ElemType;

typedef struct {
    Q_ElemType *data;
    int front;
    int rear;
    int maxsize;
} Queue;

Status InitQueue(Queue *Q, int maxsize);
BOOL IsEmpty(Queue *Q);
BOOL IsFull(Queue *Q);
Status EnQueue(Queue *Q, Q_ElemType val);
Status DeQueue(Queue *Q, Q_ElemType *val);
Status GetFront(Queue *Q, Q_ElemType *val);
Status DestroyQueue(Queue *Q);
Status ClearQueue(Queue *Q);

#endif