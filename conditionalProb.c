/*
Condicional probability
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
	//CREATE VARIABLES
	int n, aux;
	double n2, aux2, probability;

	//INITIALIZE VARIABLES
	n = 10;

	do {
		//INITIALIZE RANDOM NUMBER GENERATOR
		srand(time(NULL));

		for (int i = 0; i < n; i++) {
			//GET TWO RANDOM NUMBERS
			int seed1 = (rand() % 15) + 1; //RANGE 1 - 15
			int seed2 = (rand() % 14) + 1; //RANGE 1 - 14

			//CHECK NUMBERS
			if (seed1 > 5 && seed2 < 6) {
				aux++;
			}		
		}

		//CALCULATE CONDITIONAL PROBABILITY
		n2 = (double)n;
		aux2 = (double)aux;
		probability = aux2 / n2;
		printf("Cases: %d Condicional probability: %f\n", n, probability);

		//INCREASE NUMBER OF CASES
		n = n * 10;
		
	} while (n != 10000000);
}
