#include <stdio.h>

#define PROCESSES 6
#define RESOURCES 4

int available[RESOURCES] = {3, 4, 1, 2};
int allocation[PROCESSES][RESOURCES] = {
    {0, 3, 2, 4},
    {1, 2, 0, 1},
    {0, 0, 0, 0},
    {3, 3, 2, 2},
    {1, 4, 3, 2},
    {2, 4, 1, 4}
};
int max[PROCESSES][RESOURCES] = {
    {6, 5, 4, 4},
    {4, 4, 4, 4},
    {0, 0, 1, 2},
    {3, 9, 3, 4},
    {2, 5, 3, 3},
    {4, 6, 3, 4}
};
int need[PROCESSES][RESOURCES];

int work[RESOURCES];
int finish[PROCESSES];

void calculateNeed() {
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int checkSafeState() {
    int count = 0;
    for (int i = 0; i < PROCESSES; i++) {
        finish[i] = 0;
    }

    for (int i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    while (count < PROCESSES) {
        int found = 0;
        for (int i = 0; i < PROCESSES; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == RESOURCES) {
                    for (int k = 0; k < RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    printf("P%d ", i);
                    count++;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nUnsafe State: System cannot be in a safe state!\n");
            return 0;
        }
    }
    printf("\nSafe State: System is in a safe state!\n");
    return 1;
}

int main() {
    calculateNeed();
    printf("Need Matrix:\n");
    for (int i = 0; i < PROCESSES; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < RESOURCES; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    checkSafeState();

    return 0;
}