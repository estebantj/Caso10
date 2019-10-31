#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>
#include "matroids.h"

bool isMultFive(void* pNumber) {
	int number = *(int*)(pNumber);
	if (number % 10 == 5 || number % 10 == 0) {
		printf("The number %d is multiple of five \n", number);
		return true;
	}
	else {
		printf("The number %d is not multiple of five \n", number);
		return false;
	}
	// return (number % 10 == 5 || number % 10 == 0) ? true : false;
}

bool isEven(void* pNumber) {
	int number = *(int*)(pNumber);
	if (number % 2 == 0) {
		printf("The number %d is even \n", number);
		return true;
	}
	else {
		printf("The number %d is not even \n", number);
		return false;
	}
}

bool isAlphabet(void* pNumber) {
	int asciiLetter = *(int*)(pNumber);

	if ((asciiLetter >= 60 && asciiLetter <= 90) || (asciiLetter >= 97 && asciiLetter <= 122)) {
		printf("This is the letter %c \n", asciiLetter);
		return true;
	}
	else {
		printf("This is not a letter, it is %c \n", asciiLetter);
		return false;
	}
}

bool isUpper(void* pLetter) {
	char letter = *((char*)(pLetter));
	int num = (int)letter;
	if (num >= 60 && num <= 90) {
		printf("The letter %c is a capital letter \n", letter);
		return true;
	}
	printf("The letter %c is not a capital letter \n", letter);
	return false;
}

void printMI(void* (*MI)[], int size) {
	for (int printN = 0; printN < size; printN++) {
		int number = *(int*)((*MI)[printN]);
		(printN + 1 < size) ? printf("%d - ", number) : printf("%d \n", number);
	}
}

void printMI2(void* (*MI)[], int size) {
	for (int printL = 0; printL < size; printL++) {
		char letter = *(char*)((*MI)[printL]);
		(printL + 1 < size) ? printf("%c - ", letter) : printf("%c \n", letter);
	}
}

int main() {
	// FIRST PART
	void* MSA1[4] = { &(char) { 'E' }, &(char) { 'a' }, &(char) { 'S' }, &(char) { 'y' } };
	void* MIA1[4] = { &(char) { ' ' }, &(char) { ' ' }, &(char) { ' ' }, &(char) { ' ' } };

	void* MSA2[3] = { &(int) { 65 }, &(int) { 46 }, &(int) { 83 } };
	void* MIA2[3] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSA3[5] = { &(int) { 70 }, &(int) { 85 }, &(int) { 117 }, &(int) { 67 }, &(int) { 75 } };
	void* MIA3[5] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MatroidsA[3][4] = { {&MSA1, &MIA1, &(int) { 4 }, &isUpper}, {&MSA2, &MIA2, &(int) { 3 }, &isEven}, {&MSA3, &MIA3, &(int) { 5 }, &isMultFive} };

	// SECOND PART
	void* MSB1[4] = { &(int) { 72 }, &(int) { 101 }, &(int) { 108 }, &(int) { 80 } };
	void* MIB1[4] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB2[3] = { &(int) { 65 }, &(int) { 72 }, &(int) { 80 } };
	void* MIB2[3] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB3[4] = { &(int) { 109 }, &(int) { 101 }, &(int) { 80 }, &(int) { 191 } };
	void* MIB3[4] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB4[5] = { &(int) { 126 }, &(int) { 80 }, &(int) { 96 }, &(int) { 60 }, &(int) { 72 } };
	void* MIB4[5] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB5[6] = { &(int) { 37 }, &(int) { 175 }, &(int) { 72 }, &(int) { 59 }, &(int) { 63 }, &(int) { 80 } };
	void* MIB5[6] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MatroidsB[5][4] = { {&MSB1, &MIB1, &(int) { 4 }, &isAlphabet}, {&MSB2, &MIB2, &(int) { 3 }, &isAlphabet}, {&MSB3, &MIB3, &(int) { 4 }, &isAlphabet}
																		,{&MSB4, &MIB4, &(int) { 5 }, &isAlphabet}, {&MSB5, &MIB5, &(int) { 6 }, &isAlphabet} };

	//void* Matroids[4] = { &(void*) { MS }, &(void*){MI},&(void*) { MS2 }, &(void*){MI2} };

	// Resultados
	// Matroid1
	//printf("%d \n", *(int*)MI[0]);

	// --------------- PART A EVALUATION --------------- //
	evaluateMatroidsA(&MatroidsA, sizeof(MatroidsA) / sizeof(MatroidsA[0]));
	printMI2(&MIA1, 4);
	printMI(&MIA2, 3);
	printMI(&MIA3, 5);
	printf("----------------- \n");
	// --------------- PART B INTERSECTIONS --------------- //
	evaluateMatroidsB(&MatroidsB, sizeof(MatroidsB) / sizeof(MatroidsB[0]));
	printMI(&MIB1, 4);
	printMI(&MIB2, 3);
	printMI(&MIB3, 4);
	printMI(&MIB4, 5);
	printMI(&MIB5, 6);
	printf("----------------- \n");

	intersections(&MIB1, &MIB2, &MIB3, &MIB4, &MIB5, 2);
	system("PAUSE");
	return 0;
}