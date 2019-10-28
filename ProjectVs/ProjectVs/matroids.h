#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <omp.h>

struct matroid {
	void *MS;
	void *MI;
	void (*func)(void*);
	int size;
};

void evaluateMatroids();