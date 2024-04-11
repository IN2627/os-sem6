#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int num_processes, num_resources;

void acceptAvailable() {
    printf("Enter available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("Resource %c: ", 'A' + i);
        scanf("%d", &available[i]);
    }
}

void acceptData() {
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter max matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void displayAllocationMax() {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("Max Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
}

void displayNeed() {
    printf("Need Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

void displayAvailable() {
    printf("Available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("Resource %c: %d\n", 'A' + i, available[i]);
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    acceptAvailable();
    acceptData();

    int choice;
    char ch;
    do {
        printf("\nMenu:\n");
        printf("a) Accept Available\n");
        printf("b) Display Allocation, Max\n");
        printf("c) Display contents of need matrix\n");
        printf("d) Display Available\n");
        printf("Enter your choice: ");
        scanf(" %c", &ch);
        choice = ch - 'a' + 1;

        switch (choice) {
            case 1:
                acceptAvailable();
                break;
            case 2:
                displayAllocationMax();
                break;
            case 3:
                displayNeed();
                break;
            case 4:
                displayAvailable();
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
