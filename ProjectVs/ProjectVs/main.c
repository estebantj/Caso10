#include <stdio.h>
#include <stdbool.h>
#include "matroids.h"

bool isEven(int pNumber) {
	return pNumber % 2 == 0;
}

void* swap(void* vp1, void* vp2, const int size) { // Still with problems, see the link https://www.bogotobogo.com/cplusplus/pointers2_voidpointers_arrays.php
	char* buffer = (char*)malloc(sizeof(char) * size);
	memcpy(buffer, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, buffer, size);
	free(buffer);
}

int main() {

	// -------------- Test #1 -------------- //
	struct matroid test1;
	int numbers1[] = { 51, 23, 36, 74, 89 };
	int result[5] = { -1 };
	test1.MS = &numbers1;
	test1.MI = &result;
	test1.size = sizeof(numbers1) / sizeof(numbers1[0]);;

	// -------------- Pointer VOID tests -------------- //
	int(*p)[] = &numbers1;
	//printf("%p \n", &numbers1);

	// -------------- Test #2 -------------- //
	struct matroid test2;
	int numbers2[] = { 114, 253, 625, 789, 800, 194, 310, 811, 212 };
	int result2[9] = { -1 };
	test2.MS = &numbers2;
	test2.MI = &result;
	test2.size = sizeof(numbers2) / sizeof(numbers2[0]);
	test2.func = isEven;

	// -------------- Test #3 -------------- //
	struct matroid test3;
	char letters1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	char resultL1[6] = { -1 };
	test3.MS = &letters1;
	test3.MI = &resultL1;
	test3.size = sizeof(letters1) / sizeof(letters1[0]);
	test3.func = swap(&letters1[0], &letters1[0], sizeof(char));

	// -------------- Test #4 -------------- //
	struct matroid test4;
	char letters2[] = { 'z', 'y', 'x', 'w', 'v', 'u', 't' };
	char resultL2[7] = { -1 };
	test4.MS = &letters2;
	test4.MI = &resultL2;
	test4.size = sizeof(letters2) / sizeof(letters2[0]);
	test4.func = swap(&letters2[0], &letters2[0], sizeof(char));

	// -------------- Matroids -------------- //
	struct matroid matroids[2] = { test1, test2 };
	//struct matroid matroids2[2] = { test3, test4 };
	//printf("%p \n",&matroids);

	// -------------- Obtener el arreglo -------------- //
	int(*testing)[5] = test1.MS;

	// -------------- Evaluate -------------- //
	//evaluateMatroids(matroids, sizeof(matroids) / sizeof(matroids[0]));
	evaluate(matroids, sizeof(matroids) / sizeof(matroids[0]));
	//evaluate(matroids2, sizeof(matroids2) / sizeof(matroids2[0])); //To use this you must change the print from %d to %s

	// -------------- Pointer VOID tests -------------- //
	//int k[] = { 4, 5, 6, 7, 8 };
	//void* ptr = &k[1];
	//printf("%d \n", *(int*)ptr); // Shows number 5

	system("PAUSE");
	return 0;
}