#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define S 1.644934067

double v(int i)
{
	return 1.0/pow(i, 2.0);
}

double *vector(int n)
{
	double *vector = malloc(n*sizeof(double));

	#pragma omp parallel for schedule(static)
	for (int i = 0; i < n; ++i)
	{
		vector[i] = v(i+1); 
	}
	return vector;
}

double sum(double *v, int n)
{
	double sum = 0.0;

	#pragma omp parallel for schedule(static) reduction(+:sum)
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
	}
	return sum;
}

void differencePrint()
{
	double *differenceVector = malloc(11*sizeof(double));

	#pragma omp parallel for schedule(static)
	for (int k = 4; k <= 14; ++k)
	{
		double *v = vector(pow(2, k));
		differenceVector[k-4] = S - sum(&v[0], pow(2, k));
		free(v);
	}
	//Non parallelized for loop made to print values in decending order.
	for (int i = 0; i < 11; ++i)
	{
		printf("%lf\n", differenceVector[i]);
	}
	free(differenceVector);
}

int main(int argc, char** argv)
{
	printf("Parallel Difference Print Test\n");
	printf("======================================\n");
	differencePrint();
	return 0;
}