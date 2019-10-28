#include <stdio.h>
#include <stdbool.h>
#include "matroids.h"

bool isMultFive(int pNumber) {
	return (pNumber % 10 == 5 || pNumber % 10 == 0) ? true : false;
}

bool isEven(int pNumber) {
	return pNumber % 2 == 0;
}

bool isUneven(int pNumber) {
	return pNumber % 2 != 0;
}

bool isPalindrome() {
	return true;
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
	// -------------- Matroid 1.1 -------------- //
	struct matroid test1;
	int numbers1[] = { 55, 20, 35, 75, 89 };
	int resultN1[sizeof(numbers1) / sizeof(numbers1[0])] = { -1 };
	test1.MS = &numbers1;
	test1.MI = &resultN1;
	test1.size = sizeof(numbers1) / sizeof(numbers1[0]);
	test1.func = isMultFive;

	// -------------- Pointer VOID tests -------------- //
	int(*p)[] = &numbers1;
	//printf("%p \n", &numbers1);

	// -------------- Matroid 1.2 -------------- //
	struct matroid test2;
	int numbers2[] = { 114, 253, 625, 789, 800, 194, 310, 811, 212 };
	int resultN2[sizeof(numbers2) / sizeof(numbers2[0])] = { -1 };
	test2.MS = &numbers2;
	test2.MI = &resultN2;
	test2.size = sizeof(numbers2) / sizeof(numbers2[0]);
	test2.func = isEven;

	// -------------- Matroid 1.3 -------------- //
	struct matroid test3;
	int numbers3[] = { 4, 7, 6, 9, 0, 1 };
	int resultN3[sizeof(numbers3) / sizeof(numbers3[0])] = { -1 };
	test3.MS = &numbers3;
	test3.MI = &resultN3;
	test3.size = sizeof(numbers3) / sizeof(numbers3[0]);
	test3.func = isUneven;

	// -------------- Test #2 -------------- //
	// -------------- Matroid 2.1 -------------- //
	struct matroid test4;
	char letters1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	char resultL1[sizeof(letters1) / sizeof(letters1[0])] = { -1 };
	test4.MS = &letters1;
	test4.MI = &resultL1;
	test4.size = sizeof(letters1) / sizeof(letters1[0]);
	test4.func = swap(&letters1[0], &letters1[1], sizeof(char));

	// -------------- Matroid 2.2 -------------- //
	struct matroid test5;
	char letters2[] = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };
	char resultL2[sizeof(letters2) / sizeof(letters2[0])] = { -1 };
	test5.MS = &letters2;
	test5.MI = &resultL2;
	test5.size = sizeof(letters2) / sizeof(letters2[0]);
	test5.func = isPalindrome;

	// -------------- Matroid 2.3 -------------- //
	struct matroid test6;
	char letters3[] = { 'k', 'u', 's', 'h' };
	char resultL3[sizeof(letters3) / sizeof(letters3[0])] = { -1 };
	test6.MS = &letters3;
	test6.MI = &resultL3;
	test6.size = sizeof(letters3) / sizeof(letters3[0]);
	test6.func = NULL;

	// -------------- Matroid 2.4 -------------- //
	struct matroid test7;
	char letters4[] = { 'f', 'o', 'r' };
	char resultL4[sizeof(letters4) / sizeof(letters4[0])] = { -1 };
	test7.MS = &letters4;
	test7.MI = &resultL4;
	test7.size = sizeof(letters4) / sizeof(letters4[0]);
	test7.func = NULL;

	// -------------- Matroid 2.5 -------------- //
	struct matroid test8;
	char letters5[] = { 'm', 'e' };
	char resultL5[sizeof(letters5) / sizeof(letters5[0])] = { -1 };
	test8.MS = &letters5;
	test8.MI = &resultL5;
	test8.size = sizeof(letters5) / sizeof(letters5[0]);
	test8.func = NULL;

	// -------------- Matroids -------------- //
	struct matroid matroids[3] = { test1, test2, test3 };
	//struct matroid matroids2[5] = { test4, test5, test6, test7, test8 };
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
}}