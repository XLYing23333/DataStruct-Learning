#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int BOOL;
typedef int ElemType;

typedef struct Stack {
    int top;
    int maxsize;
    ElemType *data;
} Stack;

// 初始化栈
Status InitStack(Stack *S, int maxsize) {
    S->top = -1;
    S->maxsize = maxsize;
    S->data = (ElemType *)malloc(sizeof(ElemType)*maxsize);
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
Status Push(Stack *S, ElemType val) {
    if (IsFull(S)){
        printf("{Push} \033[31m[ERR]\033[0m Full Stack.\n");
        return ERR;
    }
    S->data[++S->top] = val;
    printf("{Push} Push %d into the Stack.\n", val);
    return OK;
}

// 出栈
Status Pop(Stack *S, ElemType *val) {
    if (IsEmpty(S)){
        printf("{Pop} \033[31m[ERR]\033[0m Empty Stack.\n");
        return ERR;
    }
    *val = S->data[S->top--];
    printf("{Pop} Pop %d from the Stack.\n", *val);
    return OK;
}

// 取栈顶元素
Status Top(Stack *S, ElemType *val) {
    if (IsEmpty(S)){
        printf("{Top} \033[31m[ERR]\033[0m Empty Stack.\n");
        return ERR;
    }
    *val = S->data[S->top];
    printf("{Top} Top data is %d\n", *val);
    return OK;
}

// 销毁栈
Status DestroyStack(Stack *S) {
    S->maxsize = 0;
    free(S->data);
    S->data = NULL;
    S->top = -1;
    printf("{DestroyStack} Success.\n");
    return OK;
}

// 清空栈 (不销毁内存)
Status ClearStack(Stack *S) {
    S->top = -1;
    printf("{ClearStack} Success.\n");
    return OK;
}

Status test() {
    Stack S;
    ElemType val;
    InitStack(&S, 5);
    Push(&S, 5);
    Push(&S, 4);
    Push(&S, 3);
    Push(&S, 2);
    Push(&S, 1);
    Push(&S, 0);
    Pop(&S, &val);
    Top(&S, &val);
    Pop(&S, &val);
    Top(&S, &val);
    ClearStack(&S);
    Top(&S, &val);
    DestroyStack(&S);
    return OK;
}


int main() {
    test(); 
    return 0;
}