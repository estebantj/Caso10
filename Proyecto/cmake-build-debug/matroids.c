//
// Created by esteb on 27/10/2019.
//

#include "matroids.h"

void evaluateMatroids(struct matroid matroidsList[2], int size) {
    struct matroid prueba;
    for (int i=0; i<size; i++) {
        prueba = matroidsList[i];
        int (*numeros)[prueba.size] = prueba.MS;
        for (int j=0; j<prueba.size; j++) {
            int num = ((int *)numeros)[j];
            printf("%d \n", num);
        }
        printf("\n");
    }
}