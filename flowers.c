/*

Condicional probability by Brenda Castro

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
	//CREATE VARIABLES
	int n, aux;
	double n2, aux2, probabilidad;

	//INITIALIZE VARIABLES
	n = 10;

	do {
		//INITIALIZE RANDOM NUMBER GENERATOR
		srand(time(NULL));

		for (int i = 0; i < n; i++) {
			//GET TWO RANDOM NUMBERS
			int semilla1 = (rand() % 15) + 1; //RANGE 1 - 15
			int semilla2 = (rand() % 14) + 1; //RANGE 1 - 14

			//CHECK NUMBERS
			if (semilla1 > 5 && semilla2 < 6) {
				aux++;
			}		
		}

		//CALCULATE CONDITIONAL PROBABILITY
		n2 = (double)n;
		aux2 = (double)aux;
		probabilidad = aux2 / n2;
		printf("Número de casos: %d Probabilidad condicional: %f\n", n, probabilidad);

		//INCREASE NUMBER OF CASES
		n = n * 10;
		
	} while (n != 10000000);
}
