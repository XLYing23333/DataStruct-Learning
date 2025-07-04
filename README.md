# DataStructure

>
> Date: 2025-03-01
> 
> Reproducer: [XLY23333](https://www.xly23333.xyz)
>
> Language: C
> 
> Code Platform: Visual Studio Code
> 
> OS: Debian GNU/Linux 12 (2C2G)
> 
> Compiler: gcc (Debian 12.2.0-14) 12.2.0
>
> >代码并非100%复现，中间更改了一些个人的想法，如有侵权，请联系Email: `xly@xly23333.xyz`删除。
> 
>![LOGO](https://i2.hdslb.com/bfs/space/4adb2c63ed4ba8950194316a08ec8cacbcf255ff.png)

## Contents

### Unit2_LinearList

1. [SqList.c](./Unit2_LinearList/SqList.c)
```c
typedef struct {
    ElemType *data;
    int length;
    int maxsize;
} SqList;
```

2. [HeadList.c](./Unit2_LinearList/HeadList.c)
```c
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;

typedef struct {  
    Node *head;
    int length;
} HeadList;
```

### Unit3_StackQueue

1. [Stack.c](./Unit3_StackQueue/Stack.c)
```c
typedef struct Stack {
    int top;
    int maxsize;
    ElemType *data;
} Stack;
```

2. [Queue.c](./Unit3_StackQueue/Queue.c)
```c
typedef struct {
    ElemType *data;
    int front;
    int rear;
    int maxsize;
} Queue;
```

3. [CalB](./Unit3_StackQueue/Cal/)
   - [Stack.h](./Unit3_StackQueue/Cal/Stack.h)
   - [Stack.c](./Unit3_StackQueue/Cal/Stack.c)
   - [CalB.c](./Unit3_StackQueue/Cal/CalB.c)
   - [build.sh](./Unit3_StackQueue/Cal/build.sh)

4. [Recursive.c](./Unit3_StackQueue/Recursive.c)

### Unit4_Arr

1. [TripleArray.c](./Unit4_Arr/TripleArray.c)
```c
typedef struct TripleArray{
    int m1;
    int m2;
    int m3;
    ElemType *array;
} TripleArray;
```

### Unit5_Tree

1. [BtTree.c](./Unit5_Tree/BtTree.c)
```c
typedef struct btnode {
    ElemType data;
    struct btnode *left_c;
    struct btnode *right_c;
} BTNode;

typedef struct {
    BTNode *root;
} BinaryTree;
```