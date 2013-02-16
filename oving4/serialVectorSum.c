#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double getVectorElement(int n)
{
	return 1/pow(n,2.0);
}

double computeVectorSum(int n)
{
	int i;
	double sum;
	for (i=1;i<=n;i++)
		sum += getVectorElement(i);
	return sum;
}

double computeSumDifference(double sum)
{
	double pi = atan(1)*4;
	double s = pow(pi,2)/6;
	return s-sum;
}

void printSumDifference()
{
	int n;
	int k;
	for (k=4;k<=14;k++)
	{
		n = pow(2,k);
		printf("%lf\n",computeSumDifference(computeVectorSum(n)));
	}
}

int main(int argc, char** argv)
{
	printSumDifference();
	return 0;
}