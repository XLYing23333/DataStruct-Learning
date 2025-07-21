#ifndef _STACK_H
#define _STACK_H

#define OK 1
#define ERR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int BOOL;
typedef double ElemType;

typedef struct Stack {
    int top;
    int maxsize;
    ElemType *data;
} Stack;

// 声明函数
// 这里的声明可以同时用于Stack.c和CalB.c
Status InitStack(Stack *S, int maxsize);
BOOL IsEmpty(Stack *S);
BOOL IsFull(Stack *S);
Status Push(Stack *S, ElemType val);
Status Pop(Stack *S, ElemType *val);
Status Top(Stack *S, ElemType *val);
Status DestroyStack(Stack *S);
Status ClearStack(Stack *S);

#endif