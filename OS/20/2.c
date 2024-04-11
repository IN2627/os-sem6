#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 1000
int main(int argc, char** argv) {
 int world_rank, world_size;
 int array[ARRAY_SIZE];
 int i, max;
 // Initialize MPI environment
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
 MPI_Comm_size(MPI_COMM_WORLD, &world_size);
 // Generate random array in root process (rank 0)
 if (world_rank == 0) {
 srand(time(NULL));
 printf("Generated Array: ");
 for (i = 0; i < ARRAY_SIZE; i++) {
 array[i] = rand() % 100;
 printf("%d ", array[i]);
 }
 printf("\n");
 }
 // Scatter the array to all processes
 MPI_Scatter(array, ARRAY_SIZE / world_size, MPI_INT, array, ARRAY_SIZE / world_size,
MPI_INT, 0, MPI_COMM_WORLD);
 // Find the maximum element in each process
 max = array[0];
 for (i = 1; i < ARRAY_SIZE / world_size; i++) {
 if (array[i] > max) {
 max = array[i];
 }
 }
 // Find the maximum element across all processes using MPI_Reduce
 int global_max;
 MPI_Reduce(&max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
 // Print the maximum element in root process
 if (world_rank == 0) {
 printf("Maximum Element: %d\n", global_max);
 }
 // Finalize MPI environment
 MPI_Finalize();
 return 0;
} 
