#include <climits>
#include <iostream>
#include <omp.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "la.h"


// #define RANDTOP INT_MAX
#define RANDTOP 10

int main(int argc, char *argv[])
{
	// Adjust number of threads
	int threads = 1;

	omp_set_num_threads(threads);

	int n;
	double *A;
	double *B;
	double *C;
	double *a;
	double *b;
	double *c;
	double result;
	int resultloc;

	std::cout << "Running with OMP max threads = " << omp_get_max_threads() << std::endl;

	if(argc == 1){

		// adjust input size
		n = 20;
	
		A =(double *) malloc(sizeof(double)*n*n);
		B =(double *) malloc(sizeof(double)*n*n);
		C = (double *) malloc(sizeof(double)*n*n);

		for(int i=0; i < n; i++)
			for(int j=0; j < n; j++)
			{
				A[loc(i,j,n)] = i + j;
				B[loc(i,j,n)] = (i == j) ? 1 : 0;
				C[loc(i,j,n)] = 9;
			}

		printf("A = \n");
		printMatrix(A, n);
		printf("B = \n");
		printMatrix(B, n);
		printf("C = \n");
		printMatrix(C, n);
		printf("A * B = \n");

		// Measure the elapsed time for matmul function
        double matmul_start_time, matmul_end_time;
        matmul_start_time = omp_get_wtime();
		matmul(A, B, C, n);
		matmul_end_time = omp_get_wtime();
		double matmul_elapsed_time = (matmul_end_time - matmul_start_time) * 1e4;

		printMatrix(C, n);
		std::cout << "Elapsed time for matmul: " << matmul_elapsed_time << " ms" << std::endl;

	} else if(argc == 2) {

		// adjust input size
		n = 200;
		int testnumber = atoi(argv[1]);
		A = (double*) malloc(sizeof(double)*n*n);
		B = (double*) malloc(sizeof(double)*n*n);
		C = (double*) malloc(sizeof(double)*n*n);
		a = (double*) malloc(sizeof(double)*n);
		b = (double*) malloc(sizeof(double)*n);
		c = (double*) malloc(sizeof(double)*n);
		
		std::random_device rd;  // a seed source for the random number engine
		std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> randint(1, RANDTOP);


		for(int i=0; i < n; i++)
		{
			for(int j=0; j < n; j++)
			{
				A[loc(i,j,n)] = B[loc(i,i,n)] = i + 2 * j;
				C[loc(i,j,n)] = 9;
			}
			a[i] = randint(gen);
			b[i] = randint(gen);
			c[i] = randint(gen);
		}

		// test here

        double prefix_start_time, prefix_end_time;
        prefix_start_time = omp_get_wtime();

		prefix(a, b, n);

		prefix_end_time = omp_get_wtime();
        double prefix_elapsed_time = (prefix_end_time - prefix_start_time) * 1e9;

		printVector(a, n);
		printVector(b, n);

		std::cout << "Elapsed time for prefix: " << prefix_elapsed_time << " nanoseconds" << std::endl;

	} else {
		std::cout << "This only takes the n dimension as an argument" << std::endl;
		return 1;
	}

	return 0;
}
