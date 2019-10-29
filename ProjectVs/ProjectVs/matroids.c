#include "matroids.h"

void evaluateMatroids(void* (*Matroids)[2][4], int size) {
	//void* Matroid;
	for (int i = 0; i < size; i++) {
		void* (*Matroid)[4] = (*Matroids)[i];	// Se saca la matroid
		int arraySize = *((int*)((*Matroid)[2]));	// Se saca el tama�o del conjunto S
		void* (*Elements)[3] = (*Matroid)[0];	// Se saca el conjunto S
		for (int amountOfElements = 0; amountOfElements < arraySize; amountOfElements++) {
			//void* func = (*Matroid)[3];
			//(*func)();
			printf("");
		}
	}

	/*
	struct matroid test;
	for (int i = 0; i < size; i++) {
		int tid = omp_get_thread_num();

		printf("Hello world from omp thread %d\n", tid);
		test = (matroidsList)[i];
		int sizeN = sizeof(test.MS);
		int(*numbers)[10] = test.MS;
		//void* p = (*test.func)(test.MS, test.size, &test.MI);
		//test.MI = p;
		printf("pausa\n");
	}
	test = matroidsList[0];
	test = matroidsList[1];
	*/
}

void evaluate(struct matroid matroidsList[], int size) {
	struct matroid test;

	// -------------- Method #1 -------------- //
	int i = 0, j = 0, arrayNumber = 0;
#pragma omp parallel
	{
#pragma omp for
		for (i = 0; i < size; i++) {
			printf("We are in section 1, thread %d \n", omp_get_thread_num());
			test = matroidsList[i];
			char* buffer = (char*)malloc(sizeof(char) * size);
			buffer = test.MS;
			for (j = 0; j < test.size; j++) {
				printf("The number of position %d is: %d \n", arrayNumber, ((int*)buffer)[j]);
			}
			printf("\n");
			arrayNumber++;
		}
	}

	// -------------- Method #2 -------------- //
		//int k = 0, h = 0, arrayNumber2 = 0;
		//#pragma omp parallel
		//{
		//	#pragma omp for
		//	for (k = 0; k < size; k++) {
		//		printf("We�re in section 2, thread %d \n", omp_get_thread_num());
		//		test = matroidsList[k];
		//		char* buffer = (char*)malloc(sizeof(char) * size);
		//		buffer = test.MS;
		//		//Curious behavior when changing the print, this is due to the type of buffer thinking about other solutions if you want to use how it is
		//		for (h = 0; h < test.size; h++) {
		//			printf("The number of position %d is: %d \n", arrayNumber2, buffer[h]);
		//		}
		//		printf("\n");
		//	}
		//}
		//The change was made to work with N elements
		//In char buffer, we don't really care if it's character or not.
		//All we want is to have enough bytes to store something with size byte.
		//In other words, we need storage.
		//Check https://www.bogotobogo.com/cplusplus/pointers2_voidpointers_arrays.php
}