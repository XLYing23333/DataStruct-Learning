#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;


LL fib(LL n) {
    if (n==0 || n==1) return n;
    else {
        return (fib(n-1) + fib(n-2));
    } 
}

void ex2_1(char* s, int idx) {
    idx--;
    if (idx >= 0) {
        printf("%c", s[idx]);
        ex2_1(s, idx);
    }
    else printf("\n");
}

void ex2_2(char* s, int idx) {
    int i;
    for (i=idx; i>=0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}


int main(){
    LL fibc = 25;
    char strs[15] = "!dlroW olleH";
    int charlen = strlen(strs);
    // Fib
    printf("Fib(%lld) = %lld\n", fibc, fib(fibc));
    // Recursive -> not recursive
    ex2_1(strs, charlen);
    ex2_2(strs, charlen);
    return 0;
}