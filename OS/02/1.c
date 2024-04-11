#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *bitVector[MAX_BLOCKS] = {NULL};

// Function to initialize bit vector (linked list)
void initializeBitVector(int totalBlocks) {
    for (int i = 0; i < totalBlocks; i++) {
        bitVector[i] = NULL;
    }
}

// Function to mark a block as allocated
void allocateBlock(int block) {
    Node *newBlock = (Node *)malloc(sizeof(Node));
    newBlock->data = block;
    newBlock->next = NULL;

    if (bitVector[block] == NULL) {
        bitVector[block] = newBlock;
    } else {
        Node *temp = bitVector[block];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBlock;
    }
}

// Function to display the bit vector
void showBitVector(int totalBlocks) {
    printf("\nBit Vector (Linked List Representation):\n");
    for (int i = 0; i < totalBlocks; i++) {
        printf("%d: ", i);
        if (bitVector[i] == NULL) {
            printf("Free");
        } else {
            Node *temp = bitVector[i];
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

// Function to create a new file
void createNewFile(int totalBlocks) {
    int fileStart, fileSize;
    printf("\nEnter the starting block of the new file: ");
    scanf("%d", &fileStart);
    printf("Enter the size of the file (in blocks): ");
    scanf("%d", &fileSize);

    for (int i = fileStart; i < fileStart + fileSize; i++) {
        if (i >= totalBlocks) {
            printf("Error: File exceeds disk capacity.\n");
            return;
        }
        allocateBlock(i);
    }
    printf("New file created successfully.\n");
}

// Function to display directory
void showDirectory(int totalBlocks) {
    printf("\nDirectory:\n");
    for (int i = 0; i < totalBlocks; i++) {
        if (bitVector[i] != NULL) {
            printf("File starting at block %d\n", i);
        }
    }
}

int main() {
    int totalBlocks, choice;
    
    srand(time(NULL)); // Seed for random allocation
    
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    initializeBitVector(totalBlocks);

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
                showBitVector(totalBlocks);
                break;
            case 2:
                createNewFile(totalBlocks);
                break;
            case 3:
                showDirectory(totalBlocks);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
