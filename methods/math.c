#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/math.h"


int int_rand( int min, int max ){
    int scale = rand();
    return min + scale % ( max - min );
}

void getInt(void *res) {
    int num;
    printf("Input number: \n");
    scanf("%d", &num);
    memcpy(res, &num, sizeof(int));
}

int getIntNumber(int *n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    int num;

    do {
        err = scanf("%d", &num);
        if (err < 0)
        {
            exit(0);
        }
        if ((num < down || num > up) && k)
        {
            err = 0;
            printf("Wrong, try again\n");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}