/*Multiple Regression */
//https://sites.google.com/site/vikrantsinghbisen/numerical-analysis-and-computation/c-program-for-multiple-regression

#include<stdio.h>
//#include<curses.h>
//#include<alloc.h>
#include<math.h>
#include <stdlib.h>

void main(){
	int i,j,k,n;
	float f,/*k,*/sum=0.0,a[20][20],*x1,*x2,*y,/*n,i,j,*/p[10];
	float x_1=0,x_2=0,x12=0,x22=0,x1x2=0,y1=0,x1y1=0,x2y1=0,a1,a0,e;
	
	//clrscr();
	
	printf("Multiple Regression");
	printf("\nHow many values You are Entering");
	scanf("%d",&n);
	x1=(float*)malloc(n*4);
	x2=(float*)malloc(n*4);
	y=(float*)malloc(n*4);
	
	puts("Enter coressponding Elements X1,X2 & Y");
	
	for(i=0;i<n;i++){
		scanf("%f %f %f",&x1[i],&x2[i],&y[i]);
		x_1+=x1[i];
		x_2+=x2[i];
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

	puts("\nMatrix");
	n=3;
	for(i=1; i<=n; i++)
    {
        for(j=1; j<=n+1; j++)
        {
			printf("\t%6.6f",a[i][j]);
		}
		printf("\n");
	}

	/* Gauss Elimination */
	for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                f=a[i][j]/a[j][j];
                for(k=1; k<=n+1; k++)
                {
                    a[i][k]=a[i][k]-f*a[j][k];
                }
            }
        }
    }
    p[n]=a[n][n+1]/a[n][n];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+a[i][j]*p[j];
        }
        p[i]=(a[i][n+1]-sum)/a[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\np%d=%f\t",i,p[i]); /* x1, x2, x3 are the required solutions*/
    }
} 