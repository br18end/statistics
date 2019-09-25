/*
Percentile calculator
Formula
k(n+1)/100

meaning:
k> percentile
n> total data
*/

#include<stdio.h>
void percentilecalc(int v[], int n, int p) {
	int i, j, aux, r2;
	double r;

	for (i = 2; i < n; i++) {
		aux=v[i];
		j=i-1;
		while(j>=0 && v[j]>aux){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=aux;
	}

	//PRINT ORDERED DATA
	/*printf("Data in order\n");
	for (i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}*/

	//CALC AND PRINT PERCENTILE
	r=(n*p)/100.0;
	if (((n*p)%100)!=0)
	{
		r2=(int)r+1;
		printf("Percentile ne: %d\n",v[r2]);
	}
	else {
		r2=(int)r;
		r=(v[r2-1]+v[r2])/2.0;
		printf("Percentile e: %.2f\n",r);
	}
	
}

main(){
	//GET PERCENTILE
	int percentile;
	printf("Enter percentile to calc: ");
	scanf("%d", &percentile);

	//GET AMOUNT OF DATA
	int amount;
	printf("Enter quantity: ");
	scanf("%d", &amount);

	//CREATE ARRAY
	int data[amount];

	//GET DATA
	printf("Enter data: ");
	for (int i = 0; i < amount; ++i)
	{
		scanf("%d",&data[i]);
	}

	//CALL FUNCTION FOR CALC PERCENTILE
	percentilecalc(data, amount, percentile);
}
