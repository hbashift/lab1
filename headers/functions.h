#ifndef MATRIX_PR_FUNCTIONS_H
#define MATRIX_PR_FUNCTIONS_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"


typedef struct Functions{
    void (*sum)(void *n1, void *n2, void *res);
    void (*mult)(void *n1, void *n2, void *res);
    void (*scalar)(void *n1, int a, void *res);
    void (*fillRand)(void *res);
    void (*getNumber)(void *res);

    void (*print)(void *n1);
}Functions;

void *sumInt(void *n1, void *n2, void *res);
void *multInt(void *n1, void *n2, void *res);
void *scalarInt(void *n1, int a, void *res);
void *randInt(void *res);

void printInt(void *n1);

#endif //MATRIX_PR_FUNCTIONS_H