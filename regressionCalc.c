/*
	Regression linear and non-linear calculator
*/
#include<stdio.h> /* Standard input/output definitions */
#include<string.h> /* String function definitions */
#include<math.h> /* Mathematical functions */
#include <stdlib.h> /* Standard General Utilities Library */

void simple(int n);
void multiple(int n);
void exponential(int n);
void logistic(int n);

void main(int argc, char const *argv[]) {
	//MENU
	printf("Regression calculator\n");
	printf("1...Simple\n");
	printf("2...Multiple\n");
	printf("3...Exponential\n");
	printf("4...Logistic\n");
  
	//GET OPTION
	printf("Select regression: ");
	int option;
	scanf("%d", &option);
	//GET NUMBER OF ELEMENTS	
	printf("Introduce number of elements: ");
	int n;
	scanf("%d", &n);
	//CHECK OPTION
	switch (option) {
		case 1:
			simple(n);
			break;
		case 2:
			multiple(n);
			break;
		case 3:
			exponential(n);
			break;
		case 4:
			logistic(n);
			break;
		default:
			printf("Invalid choice\n");	
	}
}

void simple(int n) {
	//MODEL Y=A+BX
	//GET ELEMENTS
	float x[n], y[n];
	printf("Introduce y elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &y[i]);
	}
	printf("Introduce x elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &x[i]);
	}
	//CALC VALUES
	float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, xy[n], x2[n];
	for (int i = 0; i < n; ++i)	{
		xy[i] = x[i] * y[i];
		x2[i] = x[i] * x[i];
		sumx = sumx + x[i];
		sumy = sumy + y[i];
		sumxy = sumxy + xy[i];
		sumx2 = sumx2 + x2[i];
	}
	//CALC B
	float b = (((float)n * sumxy) - (sumx * sumy))/ (((float)n * sumx2) - (sumx * sumx));
	//CALC A
	float a = (sumy/(float)n) - (b * (sumx/(float)n));
	//PRINT RESULT
	printf("y = a + bx; a = %.3f, b = %.3f\n", a, b);
}

void multiple(int n) {
	//MODEL Y=A+B_0X_0+B_1X_1
	//CREATE VARIABLES
	float f, sum=0.0, a[20][20], *x1, *x2, *y, p[10];
	float x_1=0, x_2=0, x12=0, x22=0, x1x2=0, y1=0, x1y1=0, x2y1=0;
	x1=(float*)malloc(n*4);
	x2=(float*)malloc(n*4);
	y=(float*)malloc(n*4);
	//GET ELEMENTS
	printf("Introduce y elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &y[i]);
	}
	printf("Introduce x_1 elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &x1[i]);
		x_1+=x1[i];
	}
	printf("Introduce x_2 elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &x2[i]);
		x_2+=x2[i];
	}
	//GET EQUATION SYSTEM
	for (int i = 0; i < n; ++i)	{
		x1x2+=x1[i]*x2[i];
		x12+=x1[i]*x1[i];
		x22+=x2[i]*x2[i];
		y1=y1+y[i];
		x1y1=x1y1+x1[i]*y[i];
		x2y1=x2y1+x2[i]*y[i];
	}
	a[1][1]=n;
	a[1][2]=a[2][1]=x_1;
	a[1][3]=a[3][1]=x_2;
	a[2][3]=a[3][2]=x1x2;
	a[2][2]=x12;
	a[3][3]=x22;
	a[1][4]=y1;
	a[2][4]=x1y1;
	a[3][4]=x2y1;
	//GAUSS ELIMINATION
	n=3;
	for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++){
            if(i > j) {
                f = a[i][j]/a[j][j];
                for(int k = 1; k <= n+1; k++) {
                    a[i][k] = a[i][k] - f * a[j][k];
                }
            }
        }
    }
    p[n] = a[n][n+1]/a[n][n];
    for(int i = n-1; i >= 1; i--) {
        sum = 0;
        for(int j = i+1; j <= n; j++) {
            sum = sum + a[i][j] * p[j];
        }
        p[i] = (a[i][n+1] - sum)/a[i][i];
    }
	//PRINT RESULT
	printf("y=a+b_0x_0+b_1x_1; a = %.3f, b_0 = %.3f b_1 = %.3f\n", p[1], p[2], p[3]);
}

void exponential(int n) {
	//MODEL Y=e^A+BX >> lnY=A+BX
	//GET ELEMENTS
	float x[n], y[n];
	printf("Introduce y elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &y[i]);
	}
	printf("Introduce x elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &x[i]);
	}
	//CALC VALUES
	float sumx = 0, sumly = 0, sumxly = 0, sumx2 = 0, xly[n], x2[n], ly[n];
	for (int i = 0; i < n; ++i)	{
		ly[i] = log(y[i]);
		xly[i] = x[i] * ly[i];
		x2[i] = x[i] * x[i];
		sumx = sumx + x[i];
		sumly = sumly + ly[i];
		sumxly = sumxly + xly[i];
		sumx2 = sumx2 + x2[i];
	}
	//CALC B
	float b = (((float)n * sumxly) - (sumx * sumly))/(((float)n * sumx2) - (sumx * sumx));
	//CALC A
	float a = (sumly/(float)n) - (b * (sumx/(float)n));
	//PRINT RESULT
	printf("y = e^(a+bx); a = %.3f, b = %.3f\n", a, b);
}

void logistic(int n) {
	//MODEL P = e^A+BX/1+e^A+BX >> ln(P/1-P)=A+BX
	//GET ELEMENTS
	float y0[n], y1[n], x[n];
	printf("Introduce y_0 elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &y0[i]);
	}
	printf("Introduce y_1 elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &y1[i]);
	}
	printf("Introduce x elements\n");
	for (int i = 0; i < n; ++i)	{
		scanf("%f", &x[i]);
	}
	//CALC VALUES
	float totaly[n], probability[n], odds[n], lodds[n],sumx = 0;
	for (int i = 0; i < n; ++i)	{
		totaly[i] = y0[i] + y1[i];
		probability[i] = y1[i]/totaly[i];
		odds[i] = y1[i]/y0[i];
		lodds[i] = log(odds[i]);
	}
	//CALC VALUES
	float  sumlodds = 0, sumxlodds = 0, sumx2 = 0, xlodds[n], x2[n];
	for (int i = 0; i < n; ++i)	{
		xlodds[i] = x[i] * lodds[i];
		x2[i] = x[i] * x[i];
		sumx = sumx + x[i];
		sumlodds = sumlodds + lodds[i];
		sumxlodds = sumxlodds + xlodds[i];
		sumx2 = sumx2 + x2[i];
	}
	//CALC B
	float b = (((float)n * sumxlodds) - (sumx * sumlodds))/ (((float)n * sumx2) - (sumx * sumx));
	//CALC A
	float a = (sumlodds/(float)n) - (b * (sumx/(float)n));
	//PRINT RESULT
	printf("ln(p/1-p) = a+bx; a = %.3f, b = %.3f\n", a, b);
}
