#ifndef MATRIX_PR_COMPLEX_H
#define MATRIX_PR_COMPLEX_H
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "math.h"

typedef struct complex {
    int realPart;
    int implicitPart;

    size_t size;
} complex;

complex *newComplex(int realPart, int implicitPart);

void* complexAdd(void *num1, void*num2, void *res);
void* complexMult(void *num1, void *num2, void *res);
void* complexScalar(void *num1, int a, void *res);
void* complexRand(void *res);

void complexPrint(void *num);
void getComplex(void *res);
#endif //MATRIX_PR_COMPLEX_H