#include <stdio.h>
#include <stdbool.h>
#include "cmake-build-debug/matroids.h"


bool isEven(int pNumber) {
    return pNumber % 2 == 0;
}

int main() {
    struct matroid prueba;
    *prueba.MS[0] = 1;
    *prueba.MS[1] = 2;
    *prueba.MS[2] = 3;
    *prueba.MS[3] = 4;
    *prueba.MS[4] = 5;
    prueba.func = isEven;

    struct matroid prueba1;
    prueba1.MS[0] = (int*)1;
    prueba1.MS[1] = (int*)2;
    prueba1.MS[2] = (int*)3;
    prueba1.MS[3] = (int*)4;
    prueba1.MS[4] = (int*)5;
    prueba1.func = isEven;

    struct matroid matroids[2] = {prueba, prueba1};

    printf("%p \n",&matroids);

    evaluateMatroids(matroids, sizeof(matroids) / sizeof(matroids[0]));
    return 0;
}