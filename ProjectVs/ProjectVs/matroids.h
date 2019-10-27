#pragma once
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