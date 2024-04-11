#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;

// Function to initialize the arrays
void initialize() {
    for (int i = 0; i < num_resources; i++) {
        printf("Enter the number of instances for resource type %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    for (int i = 0; i < num_processes; i++) {
        printf("For process P%d:\n", i);
        for (int j = 0; j < num_resources; j++) {
            printf("Enter the allocation for resource type %d: ", j + 1);
            scanf("%d", &allocation[i][j]);
            printf("Enter the maximum requirement for resource type %d: ", j + 1);
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to display the need matrix
void displayNeedMatrix() {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a request can be granted immediately
int canGrantRequest(int process, int *request) {
    for (int i = 0; i < num_resources; i++) {
        if (request[i] > need[process][i] || request[i] > available[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resource types: ");
    scanf("%d", &num_resources);

    initialize();
    displayNeedMatrix();

    // Example: Check if process P0's request [1, 2, 1] can be granted immediately
    int process = 0;
    int request[MAX_RESOURCES] = {1, 2, 1};
    if (canGrantRequest(process, request)) {
        printf("Request can be granted immediately.\n");
    } else {
        printf("Request cannot be granted immediately.\n");
    }

    return 0;
}
