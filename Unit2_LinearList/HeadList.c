#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERR 0

typedef int ElemType;
typedef int Status;

// 由于Node结构体递归，struct后面添加名字，否则为匿名结构体
// 匿名结构体直接配合typedef使用
// 但是嵌套内部还没有typedef
// 所以需要使用typedef struct Node + struct Node * next;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;


// 简单结构体可以省略名字，直接匿名结构体+typedef
typedef struct {  
    Node *head;
    int length;
} HeadList;

// 初始化链表
Status InitList(HeadList *L) {
    L->length = 0;
    L->head = (Node*)malloc(sizeof(Node));
    L->head->next = NULL;
    return OK;
}

// 显示链表
Status ShowList(HeadList *L) {
    Node *p;
    if (L->length == 0){
        printf("{ShowList} \033[31m[ERR]\033[0m Empty List.\n");
        return ERR;
    }
    p = L->head;
    printf("{ShowList} ");
    while(p->next != NULL){
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
    return OK;
}

// 插入数据
Status Insert(HeadList *L, int idx, ElemType val) {
    int i;
    Node *p, *new_node;
    // 边界判断
    if (idx < 0 || idx > L->length){
        printf("{Insert} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    p = L->head;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    // 数据插入
    for(i=0; i<idx; i++){
        p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
    L->length ++;
    printf("{Insert} Insert %d to idx=%d\n", val, idx);
    return OK;
}

// 删除数据
Status Delete(HeadList *L, int idx) {
    int i;
    Node *p, *del_node;
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
    p = L->head;
    for (i=0; i<idx; i++){
        p = p->next;
    }
    del_node = p->next;
    p->next = del_node->next;
    free(del_node);
    L->length--;  // 表长-1
    printf("{Delete} Success Delete idx=%d\n", idx);
    return OK;
}

// 索引查找 (返回值)
Status IndexFind(HeadList *L, int idx, ElemType *val) {
    int i;
    Node *p;
    // 边界判断
    if (idx < 0 || idx > L->length-1){
        printf("{IndexFind} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    p = L->head;
    for (i=0; i<idx; i++){
        p = p->next;
    }
    *val = p->next->data;
    printf("{IndexFind} SUCCESS.\n");
    return OK;
}

// 值查找 (返回索引)
Status ValueFind(HeadList *L, ElemType val, int *idx) {
    int i;
    Node *p;
    p = L->head;
    i = 0;
    while(p->next != NULL){
        p = p->next;
        if (p->data == val){
            *idx = i;
            printf("{ValueFind} SUCCESS.\n");
            return OK;
        }
        i++;
    }
    printf("{ValueFind} \033[31m[ERR]\033[0m Not found.\n");
    *idx = -1;  // 未找到则返回-1
    return ERR;
}

// 替换数据
Status Replace(HeadList *L, int idx, ElemType val) {
    int i;
    Node *p;
    // 边界判断
    if (idx < 0 || idx > L->length-1){
        printf("{Replace} \033[31m[ERR]\033[0m Out of range.\n");
        return ERR;
    }
    p = L->head;
    for (i=0; i<idx; i++){
        p = p->next;
    }
    p->next->data = val;
    printf("{Replace} replace idx=%d to %d\n", idx, val);
    return OK;
}

// 销毁链表
Status DestroyList(HeadList *L) {
    Node *p ,*del_node;
    p = L->head;
    while (p != NULL) {
        del_node = p;
        p = p->next;
        free(del_node);
    }
    L->head = NULL;
    L->length = 0;
    printf("{DestroyList} Success.\n");
    return OK;
}

Status test() {
    HeadList L;
    ElemType find_val;
    int find_idx;
    InitList(&L);
    ShowList(&L);
    Insert(&L, 0, 3);
    Insert(&L, 0, 2);
    Insert(&L, 0, 1);
    Insert(&L, 3, 4);
    Insert(&L, 2, 5);
    ShowList(&L);
    Insert(&L, 1, 1);
    Delete(&L, 2);
    ShowList(&L);
    Delete(&L, 0);
    Delete(&L, 1);
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


int main() {
    test();
    return 0;
}