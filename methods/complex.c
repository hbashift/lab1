#include "../headers/complex.h"

complex *newComplex(const int realPart, const int implicitPart) {
    complex *res = (complex*) malloc(sizeof(complex));
    res->realPart = realPart;
    res->implicitPart = implicitPart;
    res->size = sizeof(complex);
    return res;
}

void* complexAdd(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart + n2->realPart, n1->implicitPart + n2->implicitPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}


void* complexMult(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *r = res;
    complex *n3 = newComplex(n1->realPart * n2->realPart - n1->implicitPart * n2->implicitPart + r->realPart,
                             n1->realPart * n2->implicitPart + n1->implicitPart * n2->realPart + r->implicitPart);
    memcpy(res, n3, sizeof(complex));

    free(n3);
    return res;
}
void *complexScalar(void *num1, int a, void *res){
    complex *n1 = num1;
    complex *n2 = newComplex(n1->realPart*a, n1->implicitPart*a);
    memcpy(res, n2, sizeof(complex));
    free(n2);
    return num1;
}
void* complexRand(void *res){
    int flr = int_rand(-100, 100);
    int flc = int_rand(-100, 100);
    complex *complex = newComplex(flr, flc);
    memcpy(res, complex, sizeof(complex));
    free(complex);
    return res;
}

void complexPrint(void *num) {
    complex *n = num;

    printf("%d", n->realPart);
    if(n->implicitPart>=0){
        printf("+%di", n->implicitPart);
    }else printf("%di", n->implicitPart);

    printf("  ");
}

void getComplex(void *res) {
    printf("Input real part: ");
    int a = getIntNumber(NULL, 0, 0);
    printf("Input complex part: ");
    int b = getIntNumber(NULL, 0, 0);
    complex *r = newComplex(a, b);
    memcpy(res, r, sizeof(complex));
}