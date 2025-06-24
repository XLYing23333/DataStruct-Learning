#include <stdio.h>
#include <stdlib.h>

#define ERR 0
#define OK 1
#define NotPresent 2
#define Duplicate 3
#define IllegalIndex 4

typedef int ElemType;
typedef int Status;

typedef struct TripleArray{
    int m1;
    int m2;
    int m3;
    ElemType *array;
} TripleArray;

Status InitArray(TripleArray *Arr, int m1, int m2, int m3) {
    Arr->m1 = m1;
    Arr->m2 = m2;
    Arr->m3 = m3;
    Arr->array = (ElemType *)malloc((m1 * m2 * m3) * sizeof(ElemType));
    if (! Arr->array) {
        printf("{InitArray} \033[31m[ERR]\033[0m Fail to malloc array.\n");
        return ERR;
    }
    return OK;
}

Status DestroyArray(TripleArray *Arr) {
    if (!Arr) {
        printf("{DestroyArray} \033[31m[ERR]\033[0m TripleArray not present.\n");
        return ERR;
    }
    if (!Arr->array) {
        printf("{DestroyArray} \033[31m[ERR]\033[0m Array not present.\n");
        return NotPresent;
    }
    free(Arr->array);
    Arr->array = NULL;
    printf("{DestroyArray} Success.\n");
}

Status FindArray(TripleArray *Arr, int idx1, int idx2, int idx3, ElemType *val) {
    if (!Arr->array) {
        printf("{FindArray} \033[31m[ERR]\033[0m Array not present.\n");
        return NotPresent;
    }
    if (idx1<0 || idx2<0 || idx3<0 || idx1>=Arr->m1 || idx2>=Arr->m2 || idx3>=Arr->m3) {
        printf("{FindArray} \033[31m[ERR]\033[0m Illegal Index.\n");
        return IllegalIndex;
    }
    *val = Arr->array[idx1*Arr->m2*Arr->m3 + idx2*Arr->m3 + idx3];
    // *val = *(Arr->array + idx1*Arr->m2*Arr->m3 + idx2*Arr->m3 + idx3); BOOKVersion
    return OK;
}

Status InsertArray(TripleArray *Arr, int idx1, int idx2, int idx3, ElemType val) {
    if (!Arr->array) {
        printf("{InsertArray} \033[31m[ERR]\033[0m Array not present.\n");
        return NotPresent;
    }
    if (idx1<0 || idx2<0 || idx3<0 || idx1>=Arr->m1 || idx2>=Arr->m2 || idx3>=Arr->m3) {
        printf("{InsertArray} \033[31m[ERR]\033[0m Illegal Index.\n");
        return IllegalIndex;
    }
    Arr->array[idx1*Arr->m2*Arr->m3 + idx2*Arr->m3 + idx3] = val;
    // *(Arr->array + idx1*Arr->m2*Arr->m3 + idx2*Arr->m3 + idx3) = val; BOOKVersion
    return OK;
}

Status OutputArray(TripleArray *Arr) {
    int idx1, idx2, idx3;
    ElemType val;
    if (!Arr->array) {
        printf("{OutputArray} \033[31m[ERR]\033[0m Array not present.\n");
        return NotPresent;
    }
    printf("{OutputArray} [OUTPUT]\n");
    for (idx1=0; idx1<Arr->m1; idx1++) {
        for (idx2=0; idx2<Arr->m2; idx2++) {
            for (idx3=0; idx3<Arr->m3; idx3++) {
                FindArray(Arr, idx1, idx2, idx3, &val);
                printf("Arr[%d][%d][%d] = %d\n", idx1, idx2, idx3, val);
            }
        }
    }
    return OK;
}


Status CopyArray(TripleArray *ArrRaw, TripleArray *ArrNew) {
    int idx1, idx2, idx3;
    ElemType val;
    if (! ArrRaw->array || ! ArrNew->array) {
        printf("{CopyArray} \033[31m[ERR]\033[0m Array not present.\n");
        return NotPresent;
    }
    if (ArrRaw->m1 != ArrNew->m1 
        || ArrRaw->m2 != ArrNew->m2 
        || ArrRaw->m3 != ArrNew->m3) {
        printf("{CopyArray} \033[31m[ERR]\033[0m Different Arr Size.\n");
        return ERR;
    }
    if (ArrRaw->array == ArrNew->array) {
        printf("{CopyArray} \033[31m[ERR]\033[0m Duplicate Array\n");
        return Duplicate;
    }
    for (idx1=0; idx1<ArrRaw->m1; idx1++) {
        for (idx2=0; idx2<ArrRaw->m2; idx2++) {
            for (idx3=0; idx3<ArrRaw->m3; idx3++) {
                FindArray(ArrRaw, idx1, idx2, idx3, &val);
                InsertArray(ArrNew, idx1, idx2, idx3, val);
            }
        }
    }
    return OK;
}

Status test() {
    int idx1, idx2, idx3;
    TripleArray Arr1, Arr2;
    ElemType val;

    // UnInit Arr destroy test
    DestroyArray(&Arr1);

    InitArray(&Arr1, 2, 2, 2);
    InitArray(&Arr2, 2, 2, 2);
    for (idx1=0; idx1<Arr1.m1; idx1++) {
        for (idx2=0; idx2<Arr1.m2; idx2++) {
            for (idx3=0; idx3<Arr1.m3; idx3++) {
                InsertArray(&Arr1, idx1, idx2, idx3, 10);
                InsertArray(&Arr2, idx1, idx2, idx3, 5);
            }
        }
    }
    OutputArray(&Arr1);
    OutputArray(&Arr2);
    CopyArray(&Arr1, &Arr2);
    OutputArray(&Arr1);
    OutputArray(&Arr2);

    // Duplication test
    CopyArray(&Arr1, &Arr1);

    InsertArray(&Arr1, 1, 1, 1, 9);
    printf("{test} Insert 9 at [1][1][1]\n");
    FindArray(&Arr1, 1, 1, 1, &val);
    printf("{test} Find 9 at [1][1][1] = %d\n", val);
    OutputArray(&Arr1);
    
    // illegalindex test
    InsertArray(&Arr1, 1, 1, 3, 9);
    FindArray(&Arr1, 1, 1, 3, &val);
    
    DestroyArray(&Arr1);
    DestroyArray(&Arr2);

    // Delete Arr test
    InsertArray(&Arr1, 1, 1, 1, 9);

    return OK;
}


int main() {
    test();
    return 0;
}