#include <stdio.h>  // Basic IO
#include <stdlib.h>  //  malloc / free

#define OK 1  //  成功状态
#define ERR 0  // 错误状态

typedef int ElemType;  // 数据类型 <int>
typedef int Status;  // 状态 <int>

// 顺序表数据类型
typedef struct {
    ElemType *data;  // 顺序存储数据地址开始位置指针
    int length;  //  当前表长
    int maxsize;  // 最大表长
} SqList;  // 别名

// 初始化顺序表
Status InitList(SqList *L, int maxsize) {
    L->length = 0;  // 初始化表长为0
    // 分配一段连续的内存空间
    L->data = (ElemType*)malloc(sizeof(ElemType)*maxsize);
    L->maxsize = maxsize;  // 最大长度
    return OK;
}

// 表信息 (非必需)
Status InfoList(SqList *L) {
    printf("=====List INFO=====\n");
    printf("List length: %d\n", L->length);
    printf("List maxsize: %d\n", L->maxsize);
    printf("===================\n");
    return OK;
}

// 打印表中所有数据
Status ShowList(SqList *L) {
    int i = 0;
    // 判空
    if (L->length == 0){
        printf("{ShowList} \033[31m[ERR]\033[0m Empty List.\n");
        return ERR;
    }
    // 依次打印
    printf("{ShowList} ");
    for (i=0; i<L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
    return OK;
}

// 插入数据
Status Insert(SqList *L, int idx, ElemType val) {
    int i;
    // 边界判断
    if (idx<0 || idx>L->length){
        printf("{Insert} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    // 判满
    if (L->length == L->maxsize){
        printf("{Insert} \033[31m[ERR]\033[0m List is full.\n");
        return ERR;
    }
    // 元素后移
    for (i=L->length; i>idx; i--){
        L->data[i] = L->data[i-1];
    }
    L->data[idx] = val;  // 插入数据
    L->length++;  // 表长+1
    printf("{Insert} Insert %d to idx=%d\n", val, idx);
    return OK;
}

Status Delete(SqList *L, int idx) {
    int i;
    // 边界判断
    if (idx<0 || idx>L->length-1){
        printf("{Delete} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    // 判空
    if (L->length == 0){
        printf("{Delete} \033[31m[ERR]\033[0m List is empty.\n");
        return ERR;
    }
    // 元素前移
    for (i=idx; i<L->length-1; i++){
        L->data[i] = L->data[i+1];
    }
    L->length--;  // 表长-1
    printf("{Delete} Success Delete idx=%d\n", idx);
    return OK;
}

// 索引查找 (返回值)
Status IndexFind(SqList *L, int idx, ElemType *val) {
    // 边界判断
    if (idx<0 || idx>L->length-1){
        printf("{IndexFind} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    *val = L->data[idx];  // 索引数据并赋值给val
    printf("{IndexFind} SUCCESS.\n");
    return OK;
}

// 值查找 (返回索引)
Status ValueFind(SqList *L, ElemType val, int *idx) {
    int i;
    for(i=0; i<L->length; i++){
        if (val == L->data[i]){
            *idx = i;
            printf("{ValueFind} SUCCESS.\n");
            return OK;
        }
    }
    printf("{ValueFind} \033[31m[ERR]\033[0m Not found.\n");
    *idx = -1;  // 未找到则返回-1
    return ERR;
}

// 替换数据
Status Replace(SqList *L, int idx, ElemType val) {
    // 边界判断
    if (idx<0 || idx>L->length-1){
        printf("{Replace} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    L->data[idx] = val;  // 替换数据
    printf("{Replace} replace idx=%d to %d\n", idx, val);
    return OK;
}

// 销毁顺序表
Status DestroyList(SqList *L) {
    free(L->data);
    L->length = 0;
    L->maxsize = 0;
    L->data = NULL;  // 置空指针,防止指针悬空
    printf("{DestroyList} Success.\n");
    return OK;
}

//  测试片段
Status test() {
    SqList L;
    ElemType find_val;
    int find_idx;
    InitList(&L, 5);
    InfoList(&L);
    ShowList(&L);
    Insert(&L, 0, 3);
    Insert(&L, 0, 2);
    Insert(&L, 0, 1);
    Insert(&L, 3, 4);
    Insert(&L, 2, 5);
    ShowList(&L);
    InfoList(&L);
    Insert(&L, 1, 1);
    Delete(&L, 2);
    ShowList(&L);
    InfoList(&L);
    Delete(&L, 0);
    Delete(&L, 2);
    ShowList(&L);

    IndexFind(&L, 0, &find_val);
    printf("find_val[%d]=%d\n", 0, find_val);

    ValueFind(&L, 3, &find_idx);
    printf("find value %d at idx %d\n", 3, find_idx);

    Replace(&L, 1, 10);
    ShowList(&L);

    DestroyList(&L);
    return OK;
    
}

int main(){
    test();
    return 0;
}