#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 3

int available[MAX_RESOURCES] = {7, 2, 6};
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int num_processes;

// Function to accept available resources
void acceptAvailable() {
    printf("Available resources: ");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%c=%d ", 'A' + i, available[i]);
    }
    printf("\n");
}

// Function to display allocation and max matrices
void displayAllocationMax() {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%c=%d ", 'A' + j, allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%c=%d ", 'A' + j, max[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate and display the need matrix
void calculateNeedAndDisplay() {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%c=%d ", 'A' + j, need[i][j]);
        }
        printf("\n");
    }
}

// Function to display available resources
void displayAvailable() {
    printf("Available resources: ");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%c=%d ", 'A' + i, available[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("For process P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("For process P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("a) Accept Available\n");
        printf("b) Display Allocation, Max\n");
        printf("c) Find Need and display It\n");
        printf("d) Display Available\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                acceptAvailable();
                break;
            case 'b':
                displayAllocationMax();
                break;
            case 'c':
                calculateNeedAndDisplay();
                break;
            case 'd':
                displayAvailable();
                break;
            case 'e':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 'e');

    return 0;
}
