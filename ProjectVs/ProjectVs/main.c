#include <stdio.h>
#include <stdbool.h>
#include "matroids.h"


bool isEven(int pNumber) {
	return pNumber % 2 == 0;
}

int main() {
	struct matroid prueba;
	int numeros[] = { 1 ,2, 3 ,4, 5 };
	int result[5] = { -1 };
	prueba.MS = &numeros;
	prueba.MI = &result;
	prueba.size = 5;

	int(*p)[] = &numeros;

	//printf("%p \n", &numeros);

	struct matroid prueba1;
	int numeros1[] = { 4,4,5,6,7 };
	int result2[5] = { -1 };
	prueba1.MS = &numeros1;
	prueba1.MI = &result;
	prueba1.size = 5;
	prueba1.func = isEven;

	struct matroid matroids[2] = { prueba, prueba1 };

	//printf("%p \n",&matroids);

	// De esta manera se puede obtener el arreglo
	int(*numeros3)[5] = prueba.MS;

	evaluateMatroids(matroids, sizeof(matroids) / sizeof(matroids[0]));
	system("PAUSE");
	return 0;
}