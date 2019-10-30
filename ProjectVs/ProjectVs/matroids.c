#include "matroids.h"

void evaluateMatroidsA(void* (*Matroids)[2][4], int size) {
	int amountOfMatroids, amountOfElements;

#pragma omp parallel for private(amountOfMatroids, amountOfElements)
	for (amountOfMatroids = 0; amountOfMatroids < size; amountOfMatroids++) {
		printf("amountOfMatroids = %d threadId = %d \n", amountOfMatroids, omp_get_thread_num());

		void* (*Matroid)[4] = (*Matroids)[amountOfMatroids];	// The matroid is obtained
		int arraySize = *((int*)((*Matroid)[2]));				// The size of the set S is obtained
		void* (*MS)[] = (*Matroid)[0];							// The set S is obtained
		bool (*func)(void*) = (*Matroid)[3];					// The function is obtained to evaluate the elements of the set S

		void* (*MI)[] = (*Matroid)[1];
		for (amountOfElements = 0; amountOfElements < arraySize; amountOfElements++) {
			// The element is passed to the function
			bool result = (*func)((*MS)[amountOfElements]);
			if (result) {
				(*MI)[amountOfElements] = (*MS)[amountOfElements];
			}
		}
	}
	printf("----------------- \n");
}

void evaluateMatroidsB(void* (*Matroids)[5][4], int size) {
	for (int amountOfMatroids = 0; amountOfMatroids < size; amountOfMatroids++) {

		void* (*Matroid)[4] = (*Matroids)[amountOfMatroids];	// The matroid is obtained
		int arraySize = *((int*)((*Matroid)[2]));				// The size of the set S is obtained
		void* (*MS)[] = (*Matroid)[0];							// The set S is obtained
		bool (*func)(void*) = (*Matroid)[3];					// The function is obtained to evaluate the elements of the set S

		void* (*MI)[] = (*Matroid)[1];
		for (int amountOfElements = 0; amountOfElements < arraySize; amountOfElements++) {
			bool result = (*func)((*MS)[amountOfElements]);		// The element is passed to the function
			if (result) {
				(*MI)[amountOfElements] = (*MS)[amountOfElements];
			}
		}
	}
	//#pragma omp parallel for private(amountOfMatroids, amountOfElements)
	//	for (int intersections = 0; intersections < size; intersections++) {
	//		printf("amountOfMatroids = %d threadId = %d \n", amountOfMatroids, omp_get_thread_num());
	//	}
	printf("----------------- \n");
}