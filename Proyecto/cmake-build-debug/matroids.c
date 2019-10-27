//
// Created by esteb on 27/10/2019.
//

#include "matroids.h"

void evaluateMatroids(struct matroid matroidsList[2], int size) {
    printf("%p \n", &matroidsList);
    struct matroid prueba;
    for (int i=0; i<size; i++) {
        prueba = matroidsList[i];
        *prueba.MS[0] = 100;
        printf("a\n");
    }
}