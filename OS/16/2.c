#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define N 1000
int main(int argc, char **argv)
{
    int rank, size;
    int i, min = 0;
    int arr[N];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    srand(rank + 1); // Seed the random number generator with the rank to generate different
    numbers on each process for (i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    for (i = 0; i < N; i += size)
    {
        int j, end = i + size;
        if (end > N)
        {
            end = N;
        }
        int local_min = arr[i];
        for (j = i + 1; j < end; j++)
        {
            if (arr[j] < local_min)
            {
                local_min = arr[j];
            }
        }
        MPI_Reduce(&local_min, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    }
    if (rank == 0)
    {
        printf("The minimum number is %d\n", min);
    }
    MPI_Finalize();
    return 0;
}