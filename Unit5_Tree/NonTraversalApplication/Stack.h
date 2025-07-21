#ifndef _STACK_H
#define _STACK_H

#include "BtTree.h"

#define OK 1
#define ERR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int BOOL;
typedef BTNode * S_ElemType;

typedef struct Stack {
    int top;
    int maxsize;
    S_ElemType *data;
} Stack;

// 声明函数
Status InitStack(Stack *S, int maxsize);
BOOL IsEmpty(Stack *S);
BOOL IsFull(Stack *S);
Status Push(Stack *S, S_ElemType val);
Status Pop(Stack *S, S_ElemType *val);
Status Top(Stack *S, S_ElemType *val);
Status DestroyStack(Stack *S);
Status ClearStack(Stack *S);

#endif