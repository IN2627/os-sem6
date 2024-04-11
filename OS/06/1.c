#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BLOCKS 1000

bool allocated[MAX_BLOCKS] = {false}; // Represents whether each block is allocated or not
int fileStart[MAX_BLOCKS] = {-1};     // Represents the starting block of each file
int fileLength[MAX_BLOCKS] = {0};     // Represents the length of each file
int numBlocks;                         // Total number of blocks in the disk

// Function to display the bit vector
void showBitVector() {
    printf("Bit Vector:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("%c ", allocated[i] ? 'X' : '-');
    }
    printf("\n");
}

// Function to create a new file
void createNewFile() {
    int startBlock, length;
    printf("Enter the starting block for the new file: ");
    scanf("%d", &startBlock);
    printf("Enter the length of the new file: ");
    scanf("%d", &length);

    // Check if the blocks are available
    bool available = true;
    for (int i = startBlock; i < startBlock + length; i++) {
        if (i >= numBlocks || allocated[i]) {
            available = false;
            break;
        }
    }

    if (available) {
        // Mark the blocks as allocated
        for (int i = startBlock; i < startBlock + length; i++) {
            allocated[i] = true;
        }
        // Maintain the file start and length
        fileStart[startBlock] = startBlock;
        fileLength[startBlock] = length;
        printf("New file created successfully.\n");
    } else {
        printf("Error: Not enough space to create the file.\n");
    }
}

// Function to display the directory
void showDirectory() {
    printf("Directory:\n");
    for (int i = 0; i < numBlocks; i++) {
        if (fileStart[i] != -1) {
            printf("File at block %d, length: %d\n", fileStart[i], fileLength[i]);
        }
    }
}

int main() {
    printf("Enter the total number of blocks in the disk: ");
    scanf("%d", &numBlocks);

    srand(time(NULL)); // Seed for random number generation

    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File\n");
        printf("3. Show Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                showBitVector();
                break;
            case '2':
                createNewFile();
                break;
            case '3':
                showDirectory();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != '4');

    return 0;
}
