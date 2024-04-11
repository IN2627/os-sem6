#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int array[ARRAY_SIZE];
    int localMax = 0, globalMax = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Seed for random number generation
    srand(rank);

    // Generate random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000; // Generate numbers between 0 and 999
    }

    // Find local max
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] > localMax) {
            localMax = array[i];
        }
    }

    // Reduce local max values to get global max
    MPI_Reduce(&localMax, &globalMax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Global Max: %d\n", globalMax);
    }

    MPI_Finalize();

    return 0;
}
