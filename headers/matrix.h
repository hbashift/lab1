#ifndef MATRIX_PR_MATRIX_H
#define MATRIX_PR_MATRIX_H
#include "functions.h"
#include "math.h"


typedef struct Matrix{
    void *matrix;

    int length, height;
    size_t element_size;

    struct Functions* functions;
}Matrix;

Matrix *createMatrix(int length, int height, size_t element_size, const struct Functions *f);
Matrix *createMatrixIn(size_t element_size, const struct Functions *f);

void printMatrix();

void fillMatrix(Matrix *m, int toPrint);
void fillMatrixRand(Matrix *m, int toPrint);

int canMult(Matrix *m1, Matrix *m2);
Matrix *multipleMatrix(Matrix *m1, Matrix *m2);

int canSum(Matrix *m1, Matrix *m2);
Matrix *sumMatrix(Matrix *m1, Matrix *m2);

Matrix *scalarMatrix(Matrix *m1);

Matrix *matrixTrace();
#endif //MATRIX_PR_MATRIX_H