#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define STACK_SIZE 50
#define ITEM_SIZE 20
#define POSTFIX_SIZE 200

// 判断输入postfix是否合法
BOOL IsLegal(char *postfix) {
    int i;
    char c;
    for (i=0; i<strlen(postfix); i++) {
        c = postfix[i];
        if (!(
            (c>='0' && c<='9') 
            || c=='.' || c=='+' || c=='-' || c=='*' 
            || c=='/' || c=='^' || c==' '
        )) {
            printf("{IsLegal} \033[31m[ERR]\033[0m Postfix NOT LEGAL.\n");
            return FALSE;
        }
    }
    printf("{IsLegal} \033[32m[SUCCESS]\033[0m Postfix IS LEGAL.\n");
    return TRUE;
}

// 扫描当前元素的状态和结果
// |  Err -1  |  Num 0  |  Operator 1  |
int GetItem(char *postfix, int *curPos, char *item) {
    int i = 0;
    int idx = *curPos; // real val
    int flag;
    if (postfix[idx] == '.') {  // elem head != '.'
        flag = -1;
        printf("{GetItem} \033[31m[ERR]\033[0m Postfix NOT LEGAL.\n");
    }
    else if (postfix[idx] >= '0' && postfix[idx] <= '9')  {  // num
        while((postfix[idx] >= '0' && postfix[idx] <= '9')
                || postfix[idx] == '.'){
            item[i++] = postfix[idx++];
        }
        item[i]='\0';
        flag = 0;
    }
    else {  // operator
        item[0] = postfix[idx++];
        item[1] = '\0';
        flag = 1;
    }
    while (postfix[idx] == ' ') {  // del tail spaces
        idx ++;
    }
    *curPos = idx;  // refresh curPos val
    return flag;
}

// 执行运算操作
void DoOperator(Stack *S, char oper) {
    ElemType oper1, oper2;
    if (!Pop(S, &oper1)) {
        printf("{DoOperator} \033[31m[ERR]\033[0m More Operator.\n");
        exit(0);
    }
    if (!Pop(S, &oper2)) {
        printf("{DoOperator} \033[31m[ERR]\033[0m More Operator.\n");
        exit(0);
    }
    switch(oper) {
        case '+':
            Push(S, oper2 + oper1);
            break;
        case '-':
            Push(S, oper2 - oper1);
            break;
        case '*':
            Push(S, oper2 * oper1);
            break;
        case '/':
            if (fabs(oper1) < 1e-6) {  // \frac{x}{0}
                printf("{DoOperator} \033[31m[ERR]\033[0m The dividend cannot be 0.\n");
                exit(0);
            }
            else {
                Push(S, oper2 / oper1);
            }
            break;
        case '^':
            Push(S, pow(oper2, oper1));
            break;
    }
}

ElemType Caculating(char *postfix) {
    Stack S;
    char item[ITEM_SIZE];
    ElemType data;
    int flag = -1;
    int curPos = 0;
    while(postfix[curPos]==' ')  {  // filter front spaces
        curPos ++;
    }
    InitStack(&S, STACK_SIZE);
    while(curPos < strlen(postfix)) {
        flag = GetItem(postfix, &curPos, item);  // getitem
        if (flag == -1) {  // ERR
            exit(0);
        }
        else if (flag == 1) {  // Operator
            switch(item[0]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    DoOperator(&S, item[0]);
                    break;
            }
        }
        else {  // NUM
            data = atof(item);
            Push(&S, data);
        }
    }
    if (S.top == 0) {  // Stack's Last Elem
        Top(&S, &data);  // RESULT
    }
    else {
        printf("{Caculating} \033[31m[ERR]\033[0m More Operator OR More NUM.\n");
        exit(0);
    }
    DestroyStack(&S);
    return data;

}

Status Calc() {
    char postfix[POSTFIX_SIZE];
    ElemType res;
    printf("Input Postfix (Space Split Num)> ");
    fgets(postfix, sizeof(postfix), stdin);
    printf("[Input SUCCESS]\n");
    postfix[strlen(postfix) - 1] = '\0';
    printf("Input postfix is : \"%s\"\n", postfix);
    if (!IsLegal(postfix)) {
        return ERR;
    } 
    res = Caculating(postfix);
    printf("============ RES ============\n");
    printf("\033[32m[SUCCESS]\033[0m %s = %.2f\n", postfix, res);
    printf("=============================\n");
    return OK;
}

int main() {
    Calc();
    return 0;
}