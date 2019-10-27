//
// Created by esteb on 27/10/2019.
//

#ifndef CASO10_MATROIDS_H
#define CASO10_MATROIDS_H

#include <stdio.h>

struct matroid {
    int *MS[5];
    void *MI[5];
    void *func;
};

void evaluateMatroids();

#endif //CASO10_MATROIDS_H
