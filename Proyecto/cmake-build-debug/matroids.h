//
// Created by esteb on 27/10/2019.
//

#ifndef CASO10_MATROIDS_H
#define CASO10_MATROIDS_H

#include <stdio.h>
#include <stdbool.h>
#include <omp.h>

struct matroid {
    void *MS;
    void *MI;
    void *func;
    int size;
};

void evaluateMatroids();

#endif //CASO10_MATROIDS_H
