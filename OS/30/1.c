#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#define ARRAY_SIZE 1000
int main(int argc, char** argv) {
 int rank, size, i;
 int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));
 int min = 0, global_min;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 srand(time(NULL) + rank); // seed the random number generator with rank-dependent seed
 for (i = 0; i < ARRAY_SIZE; i++) {
 array[i] = rand();
 }
 MPI_Reduce(&array, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
 if (rank == 0) {
 printf("The minimum number is %d\n", min);
 }
 MPI_Finalize();
 free(array);
 return 0;
}