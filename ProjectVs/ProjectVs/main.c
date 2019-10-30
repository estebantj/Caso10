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

bool isBlackJack(void* pNumber) {
	int firstCard = rand() % 4 + 13;
	int secondCard = *(int*)(pNumber);

	if (firstCard + secondCard == 21) {
		// printf("Winner, You got BLACKJACK with %d and %d \n", firstCard, secondCard);
		return true;
	}
	else if (firstCard + secondCard < 21) {
		// printf("You did not get BLACKJACK either lose with %d and %d \n", firstCard, secondCard);
		return true;
	}
	else {
		// printf("Loser, You did not get BLACKJACK with %d and %d \n", firstCard, secondCard);
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
	void* MSB1[4] = { &(int) { 6 }, &(int) { 9 }, &(int) { 5 }, &(int) { 7 } };
	void* MIB1[4] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB2[3] = { &(int) { 5 }, &(int) { 6 }, &(int) { 7 } };
	void* MIB2[3] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB3[4] = { &(int) { 7 }, &(int) { 5 }, &(int) { 10 }, &(int) { 6 } };
	void* MIB3[4] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB4[5] = { &(int) { 11 }, &(int) { 8 }, &(int) { 6 }, &(int) { 9 }, &(int) { 5 } };
	void* MIB4[5] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MSB5[6] = { &(int) { 5 }, &(int) { 9 }, &(int) { 8 }, &(int) { 10 }, &(int) { 6 }, &(int) { 7 } };
	void* MIB5[6] = { &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 }, &(int) { 0 } };

	void* MatroidsB[5][4] = { {&MSB1, &MIB1, &(int) { 4 }, &isBlackJack}, {&MSB2, &MIB2, &(int) { 3 }, &isBlackJack}, {&MSB3, &MIB3, &(int) { 4 }, &isBlackJack}
																		,{&MSB4, &MIB4, &(int) { 5 }, &isBlackJack}, {&MSB5, &MIB5, &(int) { 6 }, &isBlackJack} };

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

	system("PAUSE");
	return 0;
}