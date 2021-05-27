#include "../headers/menu.h"


int getNum(int *n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf("%d", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Wrong, try again\n");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

Matrix *createIntMatrix(){
    Functions *functionsInt = malloc(sizeof(Functions));
    functionsInt->sum = sumInt;
    functionsInt->mult = multInt;
    functionsInt->scalar = scalarInt;
    functionsInt->fillRand = randInt;
    functionsInt->print = printInt;
    functionsInt->getNumber = getInt;
    Matrix *matrix = createMatrixIn(sizeof(int), functionsInt);
    return matrix;
}

Matrix *createComplexMatrix(){
    Functions *functionsComplex = malloc(sizeof(Functions));
    functionsComplex->sum = complexAdd;
    functionsComplex->mult = complexMult;
    functionsComplex->scalar = complexScalar;
    functionsComplex->fillRand = complexRand;
    functionsComplex->print = complexPrint;
    functionsComplex->getNumber = getComplex;
    Matrix *matrix = createMatrixIn(sizeof(complex), functionsComplex);
    return matrix;
}

Matrix *getMatrix(){
    int n;
    printf("Input number: \n"
           "  1) int matrix\n"
           "  2) complex matrix\n");
    getNum(&n, 1, 2);

    Matrix *matrix;
    switch (n) {
        case 1: matrix = createIntMatrix(); break;
        case 2: matrix = createComplexMatrix(); break;
        default: matrix = NULL; break;
    }

    printf("How do you want to fill matrix: \n"
           "  1) random\n"
           "  2) by yourself\n");
    getNum(&n, 1, 2);
    switch (n) {
        case 1: fillMatrixRand(matrix, 1); break;
        case 2: fillMatrix(matrix, 1); break;
        default: matrix = NULL; break;
    }

    return matrix;
}

void printMenu(){
    Matrix *m1;
    Matrix *m2;
    printf("1: Multiply two matrices \n"
           "2: Sum two matrices\n"
           "3: Scalar multiply matrix\n"
           "Input number: ");
    int n;
    getNum(&n,1, 3 );
    switch (n) {
        case 1:
            printf("\nFirst matrix\n");
            m1 = getMatrix();
            printf("\nSecond matrix\n");
            m2 = getMatrix();
            if(m1->element_size!=m2->element_size){
                printf("Matrices types aren't equal\n");
                break;
            }
            if (canMult(m1, m2)) break;
            printf("\n ...multiplying matrices...\n");
            Matrix *mult = multipleMatrix(m1, m2);
            printf("\nDone, multiplied matrix:\n");
            printMatrix(mult);
            break;
        case 2:
            printf("\nFirst matrix\n");
            m1 = getMatrix();
            printf("\nSecond matrix\n");
            m2 = getMatrix();
            if(m1->element_size!=m2->element_size){
                printf("Matrices types aren't equal\n");
                break;
            }
            if (canSum(m1, m2)) break;
            printf("\n ...summing matrices...\n");
            Matrix *sum = sumMatrix(m1, m2);
            printf("\nDone, summed matrix:\n");
            printMatrix(sum);
            break;
        case 3:
            m1 = getMatrix();
            Matrix *scalar = scalarMatrix(m1);
            printMatrix(scalar);
            break;
        default:  break;
    }
}