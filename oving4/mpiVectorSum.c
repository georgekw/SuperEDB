#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>

#define S 1.644934067

double v(int i)
{
	return 1.0/pow(i, 2.0);
}

double *vectorStub(int n1, int vsize)
{
	double *vector = malloc(vsize*sizeof(double));

	#pragma omp parallel for schedule(static)
	for (int i = 0; i < vsize; ++i)
	{
		vector[i] = v(i+n1+1); 
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

int main(int argc, char **argv)
{
	int rank, size, nbyP;
	double subsum, globalsum;
	double *vector;
	
	MPI_Init (&argc, &argv);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	MPI_Comm_size (MPI_COMM_WORLD, &size);
	
	for (int k = 4; k <= 14; ++k)
	{
		nbyP = pow(2, k)/size;
		vector = vectorStub(rank*nbyP, nbyP);
		subsum = sum(&vector[0], nbyP);

		MPI_Reduce (&subsum, &globalsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

		if (rank == 0)
		{
			printf("%lf\n", S - globalsum);
		}
	}

	free(vector);
	MPI_Finalize();
	return 0;
}
