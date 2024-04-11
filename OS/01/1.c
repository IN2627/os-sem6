#include <stdio.h>

int A[10][10], M[10][10], N[10][10];
int AV[10], nor, nop;

void AcceptAvailable() {
    int i;
    printf("Enter Available resources:\n");
    for (i = 0; i < nor; i++) {
        printf("%c:", 65 + i);
        scanf("%d", &AV[i]);
    }
}

void DisplayAllocationMax() {
    int i, j;
    printf("\n\tAllocation\t\tMax\n");
    printf("\t");
    for (j = 0; j < nor; j++) {
        printf("%4c", 65 + j);
    }
    printf("\t");
    for (j = 0; j < nor; j++) {
        printf("%4c", 65 + j);
    }
    for (i = 0; i < nop; i++) {
        printf("\nP%d\t", i);
        for (j = 0; j < nor; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\t");
        for (j = 0; j < nor; j++) {
            printf("%4d", M[i][j]);
        }
    }
}

void DisplayNeed() {
    int i, j;
    printf("\n\tNeed\n");
    printf("\t");
    for (j = 0; j < nor; j++) {
        printf("%4c", 65 + j);
    }
    for (i = 0; i < nop; i++) {
        printf("\nP%d\t", i);
        for (j = 0; j < nor; j++) {
            printf("%4d", N[i][j]);
        }
    }
}

void DisplayAvailable() {
    int i;
    printf("\nAvailable resources:\n");
    for (i = 0; i < nor; i++) {
        printf("%c: %d\n", 65 + i, AV[i]);
    }
}

int main() {
    int choice;
    printf("Enter Number of Process :");
    scanf("%d", &nop);
    printf("Enter Number of Resources :");
    scanf("%d", &nor);
    printf("Enter Allocation\n");
    for (int i = 0; i < nop; i++) {
        printf("P%d\n", i);
        for (int j = 0; j < nor; j++) {
            printf("%c:", 65 + j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter MAX Requirement\n");
    for (int i = 0; i < nop; i++) {
        printf("P%d\n", i);
        for (int j = 0; j < nor; j++) {
            printf("%c:", 65 + j);
            scanf("%d", &M[i][j]);
        }
    }

    // Calculate Need matrix
    for (int i = 0; i < nop; i++) {
        for (int j = 0; j < nor; j++) {
            N[i][j] = M[i][j] - A[i][j];
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation, Max\n");
        printf("3. Display Need matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AcceptAvailable();
                break;
            case 2:
                DisplayAllocationMax();
                break;
            case 3:
                DisplayNeed();
                break;
            case 4:
                DisplayAvailable();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
