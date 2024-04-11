#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int array[ARRAY_SIZE];
    int localSum = 0, globalSum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Seed for random number generation
    srand(rank);

    // Generate random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Calculate local sum
    for (int i = 0; i < ARRAY_SIZE; i++) {
        localSum += array[i];
    }

    // Reduce local sums to get global sum
    MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Global Sum: %d\n", globalSum);
    }

    MPI_Finalize();

    return 0;
}


// mpicc mpi_sum.c -o mpi_sum
// mpiexec -n <num_processes> ./mpi_sum
