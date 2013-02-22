#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define S 1.644934067

double v(int i)
{
	return 1.0/pow(i, 2.0);
}

double *vector(int n)
{
	double *vector = malloc(n*sizeof(double));

	for (int i = 0; i < n; ++i)
	{
		vector[i] = v(i+1); 
	}
	return vector;
}

double sum(double *v, int n)
{
	double sum = 0.0;

	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
	}
	return sum;
}

void differencePrint()
{
	int n = pow(2, 14);
	double *v = vector(n);

	for (int k = 4; k <= 14; ++k)
	{
		printf("%lf\n", S - sum(&v[0], pow(2, k)));
	}
	free(v);
}

int main(int argc, char** argv)
{
	printf("Serial Difference Print Test\n");
	printf("======================================\n");
	differencePrint();
	return 0;
}