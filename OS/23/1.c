#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **matrix, int m, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void calculateNeed(int **allocation, int **max, int **need, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int checkRequest(int *request, int **allocation, int **need, int *available, int m, int n, int process) {
    for (int i = 0; i < n; i++) {
        if (request[i] > need[process][i]) {
            printf("Request exceeds maximum claim. Cannot be granted immediately.\n");
            return 0;
        }
        if (request[i] > available[i]) {
            printf("Request cannot be granted immediately due to insufficient resources.\n");
            return 0;
        }
    }
    return 1;
}

int main() {
    int m, n;

    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resource types: ");
    scanf("%d", &n);

    // Allocate memory for matrices
    int **allocation = malloc(m * sizeof(int *));
    int **max = malloc(m * sizeof(int *));
    int **need = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        allocation[i] = malloc(n * sizeof(int));
        max[i] = malloc(n * sizeof(int));
        need[i] = malloc(n * sizeof(int));
    }

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input maximum requirement matrix
    printf("Enter the maximum requirement matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Calculate and display need matrix
    calculateNeed(allocation, max, need, m, n);
    printf("Need Matrix:\n");
    displayMatrix(need, m, n);

    // Input available resources
    int *available = malloc(n * sizeof(int));
    printf("Enter the number of instances for each resource type available: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &available[i]);
    }

    // Input request from a process
    int *request = malloc(n * sizeof(int));
    int process;
    printf("Enter the process number making the request: ");
    scanf("%d", &process);
    printf("Enter the request for process P%d: ", process);
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    // Check if request can be granted immediately
    if (checkRequest(request, allocation, need, available, m, n, process)) {
        printf("Request can be granted immediately.\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(allocation[i]);
        free(max[i]);
        free(need[i]);
    }
    free(allocation);
    free(max);
    free(need);
    free(available);
    free(request);

    return 0;
}