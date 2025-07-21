#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化栈
Status InitStack(Stack *S, int maxsize) {
    S->top = -1;
    S->maxsize = maxsize;
    S->data = (S_ElemType *)malloc(sizeof(S_ElemType)*maxsize);
    return OK;
}

// 判空
BOOL IsEmpty(Stack *S){
    if (S->top == -1){
        return TRUE;
    }else {
        return FALSE;
    }
}

// 判满
BOOL IsFull(Stack *S){
    if (S->top == S->maxsize-1){
        return TRUE;
    }else {
        return FALSE;
    }
}

// 入栈
Status Push(Stack *S, S_ElemType val) {
    if (IsFull(S)){
        printf("{Stack.Push} \033[31m[ERR]\033[0m Full Stack.\n");
        return ERR;
    }
    S->data[++S->top] = val;
    // printf("{Stack.Push} Push %.2f into the Stack.\n", val);
    return OK;
}

// 出栈
Status Pop(Stack *S, S_ElemType *val) {
    if (IsEmpty(S)){
        printf("{Stack.Pop} \033[31m[ERR]\033[0m Empty Stack.\n");
        return ERR;
    }
    *val = S->data[S->top--];
    // printf("{Stack.Pop} Pop %.2f from the Stack.\n", *val);
    return OK;
}

// 取栈顶元素
Status Top(Stack *S, S_ElemType *val) {
    if (IsEmpty(S)){
        printf("{Stack.Top} \033[31m[ERR]\033[0m Empty Stack.\n");
        return ERR;
    }
    *val = S->data[S->top];
    printf("{Stack.Top} Top data is %.2f\n", *val);
    return OK;
}

// 销毁栈
Status DestroyStack(Stack *S) {
    S->maxsize = 0;
    free(S->data);
    S->data = NULL;
    S->top = -1;
    printf("{Stack.DestroyStack} Success.\n");
    return OK;
}

// 清空栈 (不销毁内存)
Status ClearStack(Stack *S) {
    S->top = -1;
    printf("{Stack.ClearStack} Success.\n");
    return OK;
}