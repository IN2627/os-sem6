#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 100

int bitVector[MAX_BLOCKS] = {0}; // 0 for free, 1 for allocated

void showBitVector(int n) {
    printf("Bit Vector (0 = Free, 1 = Allocated):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
}

void createNewFile(int n) {
    int startBlock = -1;
    int length = 0;

    // Find a free block to start the file
    for (int i = 0; i < n; i++) {
        if (bitVector[i] == 0) {
            startBlock = i;
            length = 1;
            bitVector[i] = 1; // Mark the block as allocated
            break;
        }
    }

    // If a free block is found, continue marking consecutive free blocks
    if (startBlock != -1) {
        for (int i = startBlock + 1; i < n; i++) {
            if (bitVector[i] == 0) {
                bitVector[i] = 1;
                length++;
            } else {
                break; // Stop if a block is already allocated
            }
        }
        printf("New file created starting from block %d with length %d\n", startBlock, length);
    } else {
        printf("No free blocks available to create a new file.\n");
    }
}

void showDirectory(int n) {
    printf("Directory Listing:\n");
    printf("Block\tStatus\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (bitVector[i] == 0) {
            printf("Free\n");
        } else {
            printf("Allocated\n");
        }
    }
}

int main() {
    int n;

    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &n);

    srand(time(NULL)); // Seed the random number generator

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File\n");
        printf("3. Show Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBitVector(n);
                break;
            case 2:
                createNewFile(n);
                break;
            case 3:
                showDirectory(n);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}