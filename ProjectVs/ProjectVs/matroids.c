#include "matroids.h"

void evaluateMatroids(struct matroid matroidsList[], int size) {
	struct matroid test;
	for (int i = 0; i < size; i++) {
		int tid = omp_get_thread_num();
		printf("Hello world from omp thread %d\n", tid);
		test = matroidsList[i];
		int(*numeros)[5] = test.MS;
		for (int j = 0; j < test.size; j++) {
			int num = ((int*)numeros)[j];
			printf("%d \n", num);

		}
		printf("\n");
	}
}

void evaluate(struct matroid matroidsList[], int size) {
	struct matroid test;
#pragma omp parallel sections num_threads(size)
	{
		// -------------- Method #1 -------------- //
#pragma omp parallel section
		{
			for (int i = 0; i < size; i++) {
				printf("We´re in section 1, thread %d \n", omp_get_thread_num());
				test = matroidsList[i];
				char* buffer = (char*)malloc(sizeof(char) * size);
				buffer = test.MS;
				for (int j = 0; j < test.size; j++) {
					printf("The number of position %d is: %d \n", j, ((int*)buffer)[j]);
				}
				printf("\n");
			}
		}

		// -------------- Method #2 -------------- //
#pragma omp parallel section 
		{
			for (int i = 0; i < size; i++) {
				printf("We´re in section 2, thread %d \n", omp_get_thread_num());
				test = matroidsList[i];
				char* buffer = (char*)malloc(sizeof(char) * size);
				buffer = test.MS;
				//Curious behavior when changing the print, this is due to the type of buffer thinking about other solutions if you want to use how it is

				for (int j = 0; j < test.size; j++) {
					printf("The number of position %d is: %d \n", j, buffer[j]);
				}
				printf("\n");
			}
		}
	}
	//The change was made to work with N elements
	//In char buffer, we don't really care if it's character or not.
	//All we want is to have enough bytes to store something with size byte.
	//In other words, we need storage.
	//Check https://www.bogotobogo.com/cplusplus/pointers2_voidpointers_arrays.php
}