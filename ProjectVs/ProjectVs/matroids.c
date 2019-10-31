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
}

void intersections(void* (*Matroids)[5][4], int numero) {
	void* (*Matroid1)[4] = (*Matroids)[0];
	void* (*Matroid2)[4] = (*Matroids)[1];
	void* (*Matroid3)[4] = (*Matroids)[2];
	void* (*Matroid4)[4] = (*Matroids)[3];
	void* (*Matroid5)[4] = (*Matroids)[4];

	void* (*MI1)[] = (*Matroid1)[1];
	void* (*MI2)[] = (*Matroid2)[1];
	void* (*MI3)[] = (*Matroid3)[1];
	void* (*MI4)[] = (*Matroid4)[1];
	void* (*MI5)[] = (*Matroid5)[1];

	int arraySize1 = *((int*)((*Matroid1)[2]));
	int arraySize2 = *((int*)((*Matroid2)[2]));
	int arraySize3 = *((int*)((*Matroid3)[2]));
	int arraySize4 = *((int*)((*Matroid4)[2]));
	int arraySize5 = *((int*)((*Matroid5)[2]));
	
	void* (*Intersections1)[] = malloc(arraySize1 * sizeof(void*));
	void* (*Intersections2)[] = malloc(arraySize4 * sizeof(void*));
	void* (*Intersections3)[] = malloc(arraySize4 * sizeof(void*));
	void* (*Intersections4)[] = malloc(arraySize5 * sizeof(void*));

	for (int i = 0; i < arraySize1; i++) {
		(*Intersections1)[i] = &(int) { 0 };
	}
	for (int i = 0; i < arraySize4; i++) {
		(*Intersections2)[i] = &(int) { 0 };
	}
	for (int i = 0; i < arraySize4; i++) {
		(*Intersections3)[i] = &(int) { 0 };
	}
	for (int i = 0; i < arraySize5; i++) {
		(*Intersections4)[i] = &(int) { 0 };
	}

	int interMI1, interMI2, cont = 0;

#pragma omp parallel 
	{
#pragma omp sections private(interMI1, interMI2)
		{
#pragma omp section
			for (interMI1 = 0; interMI1 < arraySize1; interMI1++) {
				printf("Section 1, Thread = %d \n", omp_get_thread_num());
				for (interMI2 = 0; interMI2 < arraySize2; interMI2++) {
					if (*(int*)((*MI1)[interMI1]) == *(int*)((*MI2)[interMI2]) && *(int*)((*MI1)[interMI1]) != 0) {
						(*Intersections1)[interMI1] = (*MI1)[interMI1];
						//printf("Prueba interseccion 1 %d \n", *(int*)((*Intersections1)[interMI1]));
						break;
					}
					else {
						(*Intersections1)[interMI1] = &(int) { 0 };
					}
				}
			}
#pragma omp section
			for (interMI1 = 0; interMI1 < arraySize4; interMI1++) {
				printf("Section 2, Thread = %d \n", omp_get_thread_num());
				for (interMI2 = 0; interMI2 < arraySize3; interMI2++) {
					if (*(int*)((*MI4)[interMI1]) == *(int*)((*MI3)[interMI2]) && *(int*)((*MI4)[interMI1]) != 0) {
						(*Intersections2)[interMI1] = (*MI4)[interMI1];
						//printf("Prueba interseccion 2 %d \n", *(int*)((*Intersections2)[interMI1]));
						break;
					}
					else {
						(*Intersections2)[interMI1] = &(int) { 0 };
					}
				}
			}
		}
	}

	for (interMI1 = 0; interMI1 < arraySize1; interMI1++) {
		for (interMI2 = 0; interMI2 < arraySize4; interMI2++) {
			if (*(int*)((*Intersections1)[interMI1]) == *(int*)((*Intersections2)[interMI2]) && *(int*)((*Intersections1)[interMI1]) != 0) {
				(*Intersections3)[interMI1] = (*Intersections1)[interMI1];
				//printf("Prueba interseccion 3 %d \n", *(int*)((*Intersections3)[interMI1]));			
				break;
			}
			else {
				(*Intersections3)[interMI1] = &(int) { 0 };
				//printf("Prueba interseccion 3 %d \n", *(int*)((*Intersections3)[interMI1]));
			}
		}
	}

	for (int interMI1 = 0; interMI1 < arraySize5; interMI1++) {
		for (int interMI2 = 0; interMI2 < arraySize4; interMI2++) {
			printf("Prueba interseccion 4 aqui %d \n", *(int*)((*Intersections3)[interMI2]));
			if (*(int*)((*MI5)[interMI1]) == *(int*)((*Intersections3)[interMI2]) && *(int*)((*MI5)[interMI1]) != 0) {
				(*Intersections4)[interMI1] = (*MI5)[interMI1];
				//printf("Prueba interseccion 4 %d \n", *(int*)((*Intersections4)[interMI1]));
				break;
			}
			else {
				(*Intersections4)[interMI1] = &(int) { 0 };
				//printf("Prueba interseccion 4 %d \n", *(int*)((*Intersections4)[interMI1]));
			}
		}	
	}
}