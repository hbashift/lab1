#include "test.h"


void intTest() {
    printf("Testing int\n");
    Functions *functionsInt = malloc(sizeof(Functions));
    functionsInt->sum = sumInt;
    functionsInt->mult = multInt;
    functionsInt->scalar = scalarInt;
    functionsInt->fillRand = randInt;
    functionsInt->print = printInt;
    functionsInt->getNumber = getInt;

    Matrix *m1 = createMatrix(2, 2, sizeof(int), functionsInt);
    Matrix *m2 = createMatrix(2, 2, sizeof(int), functionsInt);

    for (int i = 0; i < m1->height; ++i) {
        for (int j = 0; j < m1->length; ++j) {
            void *point = (void *) ((m1->matrix) + ((i * m1->length) + j) * m1->element_size);
            getInt(point);
        }
    }
    printf("\nFirst matrix\n");
    printMatrix(m1);

    for (int i = 0; i < m2->height; ++i) {
        for (int j = 0; j < m2->length; ++j) {
            void *point = (void *) ((m2->matrix) + ((i * m2->length) + j) * m2->element_size);
            getInt(point);
        }
    }

    printf("\nSecond matrix\n");
    printMatrix(m2);

    Matrix *mult1 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    void *mat1, *mat2, *res;
    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m2->height; ++j) {
            for (int k = 0; k < m1->height; ++k) {
                mat1 = (void *) (m1->matrix + ((i * m1->length) + k) * m1->element_size);
                mat2 = (void *) (m2->matrix + ((k * m2->length) + j) * m2->element_size);
                res = (void *) (mult1->matrix + ((i * mult1->length) + j) * mult1->element_size);
                *(int *) res = *(int *) res + *(int *) mat1 * *(int *) mat2;
            }
        }
    }
    printf("\nFirst multiplied matrix\n");
    printMatrix(mult1);

    Matrix *mult2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    mult2 = multipleMatrix(m1, m2);

    printf("\nSecond multiplied matrix\n");
    printMatrix(mult2);

    void *t1, *t2;
    if (mult1->length != mult2->length || mult1->height != mult2->height) {
        printf("Error, different size of multiplied matrices\n");
    } else {
        for (int i = 0; i < mult1->length; ++i) {
            for (int j = 0; j < mult1->height; ++j) {
                t1 = (void *) (mult1->matrix + ((i * mult1->length) + j) * mult1->element_size);
                t2 = (void *) (mult2->matrix + ((i * mult2->length) + j) * mult2->element_size);
                if (*(int *) t1 != *(int *) t2)
                    printf("Error, elements %d,%d in multiplied matrices aren't equal\n", i, j);
            }
        }
    }


    Matrix *sum1 = createMatrix(m1->length, m1->height, m1->element_size, m1->functions);

    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m1->height; ++j){
            mat1 = (void *) (m1->matrix + ((i * m1->length) + j) * m1->element_size);
            mat2 = (void *) (m2->matrix + ((i * m2->length) + j) * m2->element_size);
            res = (void *)(sum1->matrix+((i*sum1->length)+j)*sum1->element_size);
            *(int *)res = *(int *)mat1 + *(int *)mat2;
        }
    }
    printf("\nFirst summed matrix\n");
    printMatrix(sum1);

    Matrix *sum2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    sum2 = sumMatrix(m1, m2);

    printf("\nSecond summed matrix\n");
    printMatrix(sum2);

    if (sum1->length != sum2->length || sum1->height != sum2->height) {
        printf("Error, different size of summed matrices\n");
    } else {
        for (int i = 0; i < sum1->length; ++i) {
            for (int j = 0; j < sum1->height; ++j) {
                t1 = (void *) (sum1->matrix + ((i * sum1->length) + j) * sum1->element_size);
                t2 = (void *) (sum2->matrix + ((i * sum2->length) + j) * sum2->element_size);
                if (*(int *) t1 != *(int *) t2)
                    printf("Error, elements %d,%d in summed matrices aren't equal\n", i, j);
            }
        }
    }

    Matrix *scalar1 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m1->height; ++j){
            mat1 = (void *)(m1->matrix+((i*m1->length)+j)*m1->element_size);
            res = (void *)(scalar1->matrix+((i*scalar1->length)+j)*scalar1->element_size);
            *(int *)res = *(int *)mat1 * 5;
        }
    }

    printf("\nFirst scalar matrix\n");
    printMatrix(scalar1);

    Matrix *scalar2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    scalar2 = scalarMatrix(m1);

    printf("\nSecond scalar matrix\n");
    printMatrix(scalar2);

    if (scalar1->length != scalar2->length || scalar1->height != scalar2->height) {
        printf("Error, different size of summed matrices\n");
    } else {
        for (int i = 0; i < scalar1->length; ++i) {
            for (int j = 0; j < scalar1->height; ++j) {
                t1 = (void *) (scalar1->matrix + ((i * scalar1->length) + j) * scalar1->element_size);
                t2 = (void *) (scalar2->matrix + ((i * scalar2->length) + j) * scalar2->element_size);
                if (*(int *) t1 != *(int *) t2)
                    printf("Error, elements %d,%d in summed matrices aren't equal\n", i, j);
            }
        }
    }
}

void complexTest() {
    printf("Testing complex\n");
    Functions *functionsComplex = malloc(sizeof(Functions));
    functionsComplex->sum = complexAdd;
    functionsComplex->mult = complexMult;
    functionsComplex->scalar = complexScalar;
    functionsComplex->fillRand = complexRand;
    functionsComplex->print = complexPrint;
    functionsComplex->getNumber = getComplex;

    Matrix *m1 = createMatrix(2, 2, sizeof(complex), functionsComplex);
    Matrix *m2 = createMatrix(2, 2, sizeof(complex), functionsComplex);

    for (int i = 0; i < m1->height; ++i) {
        for (int j = 0; j < m1->length; ++j) {
            void *point = (void *) ((m1->matrix) + ((i * m1->length) + j) * m1->element_size);
            getComplex(point);
        }
    }
    printf("\nFirst matrix\n");
    printMatrix(m1);

    for (int i = 0; i < m2->height; ++i) {
        for (int j = 0; j < m2->length; ++j) {
            void *point = (void *) ((m2->matrix) + ((i * m2->length) + j) * m2->element_size);
            getComplex(point);
        }
    }

    printf("\nSecond matrix\n");
    printMatrix(m2);

    Matrix *mult1 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    void *mat1, *mat2, *res;
    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m2->height; ++j) {
            for (int k = 0; k < m1->height; ++k) {
                mat1 = (void *) (m1->matrix + ((i * m1->length) + k) * m1->element_size);
                mat2 = (void *) (m2->matrix + ((k * m2->length) + j) * m2->element_size);
                res = (void *) (mult1->matrix + ((i * mult1->length) + j) * mult1->element_size);
                complex *n1 = mat1;
                complex *n2 = mat2;
                complex *r = res;
                complex *n3 = newComplex(n1->realPart * n2->realPart - n1->implicitPart * n2->implicitPart + r->realPart,
                                         n1->realPart * n2->implicitPart + n1->implicitPart * n2->realPart + r->implicitPart);
                memcpy(res, n3, sizeof(complex));

                free(n3);
            }
        }
    }
    printf("\nFirst multiplied matrix\n");
    printMatrix(mult1);

    Matrix *mult2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    mult2 = multipleMatrix(m1, m2);

    printf("\nSecond multiplied matrix\n");
    printMatrix(mult2);

    void *t1, *t2;
    if (mult1->length != mult2->length || mult1->height != mult2->height) {
        printf("Error, different size of multiplied matrices\n");
    } else {
        for (int i = 0; i < mult1->length; ++i) {
            for (int j = 0; j < mult1->height; ++j) {
                t1 = (void *) (mult1->matrix + ((i * mult1->length) + j) * mult1->element_size);
                t2 = (void *) (mult2->matrix + ((i * mult2->length) + j) * mult2->element_size);
                complex *n1 = t1;
                complex *n2 = t2;
                if (n1->realPart != n2->realPart || n1->implicitPart != n2->implicitPart)
                    printf("Error, elements %d,%d in multiplied matrices aren't equal\n", i, j);
            }
        }
    }


    Matrix *sum1 = createMatrix(m1->length, m1->height, m1->element_size, m1->functions);

    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m1->height; ++j){
            mat1 = (void *) (m1->matrix + ((i * m1->length) + j) * m1->element_size);
            mat2 = (void *) (m2->matrix + ((i * m2->length) + j) * m2->element_size);
            res = (void *)(sum1->matrix+((i*sum1->length)+j)*sum1->element_size);
            complex *n1 = mat1;
            complex *n2 = mat2;
            complex *n3 = newComplex(n1->realPart + n2->realPart, n1->implicitPart + n2->implicitPart);
            memcpy(res, n3, sizeof(complex));
            free(n3);
        }
    }
    printf("\nFirst summed matrix\n");
    printMatrix(sum1);

    Matrix *sum2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    sum2 = sumMatrix(m1, m2);

    printf("\nSecond summed matrix\n");
    printMatrix(sum2);

    if (sum1->length != sum2->length || sum1->height != sum2->height) {
        printf("Error, different size of summed matrices\n");
    } else {
        for (int i = 0; i < sum1->length; ++i) {
            for (int j = 0; j < sum1->height; ++j) {
                t1 = (void *) (sum1->matrix + ((i * sum1->length) + j) * sum1->element_size);
                t2 = (void *) (sum2->matrix + ((i * sum2->length) + j) * sum2->element_size);
                complex *n1 = t1;
                complex *n2 = t2;
                if (n1->realPart != n2->realPart || n1->implicitPart != n2->implicitPart)
                    printf("Error, elements %d,%d in multiplied matrices aren't equal\n", i, j);
            }
        }
    }

    Matrix *scalar1 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    for (int i = 0; i < m1->length; ++i) {
        for (int j = 0; j < m1->height; ++j){
            mat1 = (void *)(m1->matrix+((i*m1->length)+j)*m1->element_size);
            res = (void *)(scalar1->matrix+((i*scalar1->length)+j)*scalar1->element_size);
            complex *n1 = mat1;
            complex *n2 = newComplex(n1->realPart*5, n1->implicitPart*5);
            memcpy(res, n2, sizeof(complex));
            free(n2);        }
    }

    printf("\nFirst scalar matrix\n");
    printMatrix(scalar1);

    Matrix *scalar2 = createMatrix(m2->length, m1->height, m1->element_size, m1->functions);

    scalar2 = scalarMatrix(m1);

    printf("\nSecond scalar matrix\n");
    printMatrix(scalar2);

    if (scalar1->length != scalar2->length || scalar1->height != scalar2->height) {
        printf("Error, different size of summed matrices\n");
    } else {
        for (int i = 0; i < scalar1->length; ++i) {
            for (int j = 0; j < scalar1->height; ++j) {
                t1 = (void *) (scalar1->matrix + ((i * scalar1->length) + j) * scalar1->element_size);
                t2 = (void *) (scalar2->matrix + ((i * scalar2->length) + j) * scalar2->element_size);
                complex *n1 = t1;
                complex *n2 = t2;
                if (n1->realPart != n2->realPart || n1->implicitPart != n2->implicitPart)
                    printf("Error, elements %d,%d in multiplied matrices aren't equal\n", i, j);            }
        }
    }
}
