#include "matroids.h"

void evaluateMatroids(struct matroid matroidsList[], int size) {
	struct matroid prueba;
	for (int i = 0; i < size; i++) {
		int tid = omp_get_thread_num();
		printf("Hello world from omp thread %d\n", tid);
		prueba = matroidsList[i];
		int(*numeros)[5] = prueba.MS;	
		for (int j = 0; j < prueba.size; j++) {
			int num = ((int*)numeros)[j];

			//bool result = (*prueba.func)(num);
			printf("%d \n", num);	
		}
		printf("\n");
	}
}