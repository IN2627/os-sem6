#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ARRAY_SIZE 1000
int main(int argc, char **argv)
{
 int rank, size;
 int array[ARRAY_SIZE], min, local_min;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 // Generate random numbers
 srand(rank);
 for (int i = 0; i < ARRAY_SIZE; i++) {
 array[i] = rand() % 100;
 }
 // Find local minimum
 local_min = array[0];
 for (int i = 1; i < ARRAY_SIZE; i++) {
 if (array[i] < local_min) {
 local_min = array[i];
 }
 }
 // Reduce to find global minimum
 MPI_Reduce(&local_min, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
 // Print results
 if (rank == 0) {
 printf("The minimum number is %d.\n", min);
 }
 MPI_Finalize();
 return 0;
}