#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int safeSequence[MAX_PROCESSES];
int numProcesses, numResources;

// Function to check if the system is in a safe state
int isSafe() {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSeqIndex = 0;

    // Initialize work with available resources
    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    // Find an unfinished process whose needs can be satisfied with available resources
    for (int i = 0; i < numProcesses; i++) {
        if (!finish[i]) {
            int j;
            for (j = 0; j < numResources; j++) {
                if (need[i][j] > work[j]) {
                    break;
                }
            }
            if (j == numResources) {
                // Process i can finish
                for (int k = 0; k < numResources; k++) {
                    work[k] += allocation[i][k];
                }
                finish[i] = 1;
                safeSequence[safeSeqIndex++] = i;
                i = -1; // Start over to check from beginning
            }
        }
    }

    // Check if all processes are finished
    for (int i = 0; i < numProcesses; i++) {
        if (!finish[i]) {
            return 0; // System is not in safe state
        }
    }

    return 1; // System is in safe state
}

// Function to calculate and display the content of the need matrix
void calculateNeedMatrix() {
    printf("Need Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input allocation matrix
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input maximum matrix
    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("Enter the Available Resources:\n");
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate and display the content of the need matrix
    calculateNeedMatrix();

    // Check if the system is in a safe state
    if (isSafe()) {
        printf("System is in safe state.\nSafe Sequence: ");
        for (int i = 0; i < numProcesses; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("System is not in safe state.\n");
    }

    return 0;
}
