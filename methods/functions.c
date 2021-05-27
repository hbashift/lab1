#include "../headers/functions.h"

void *sumInt(void *n1, void *n2, void *res){
    *(int *)res = *(int *)n1 + *(int *)n2;
    return res;
}

void *multInt(void *n1, void *n2, void *res){
    *(int *)res =*(int *)res + *(int *)n1 * *(int *)n2 ;
    return res;
}

void *scalarInt(void *n1, int a, void *res){
    *(int *)res = *(int *)n1 * a;
    return res;
}

void *randInt(void* res){
    int left, right;
    int fl = int_rand(-100, 100);
    memcpy(res, &fl, sizeof(int));
    return res;
}

void printInt(void *num) {
    int *n = num;
    printf("%d  ", *n);
}