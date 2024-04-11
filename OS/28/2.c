#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ARRAY_SIZE 1000
int main(int argc, char *argv[]) {
 int rank, size, i;
 int array[ARRAY_SIZE];
 int local_sum = 0, global_sum = 0;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 if (rank == 0) {
 // Generate random numbers in array
 srand(12345);
 for (i = 0; i < ARRAY_SIZE; i++) {
 array[i] = rand() % 100;
 }
 }
 // Distribute the array to all processes
 MPI_Scatter(array, ARRAY_SIZE/size, MPI_INT, array, ARRAY_SIZE/size, MPI_INT, 0,
MPI_COMM_WORLD);
 // Calculate local sum
 for (i = 0; i < ARRAY_SIZE/size; i++) {
 local_sum += array[i];
 }
 // Calculate global sum using MPI_Reduce
 MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
 if (rank == 0) {
 printf("The sum of the %d numbers is %d\n", ARRAY_SIZE, global_sum);
 }
 MPI_Finalize();
 return 0;
} 