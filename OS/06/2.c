#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

// Function to sort the disk requests in ascending order
void sortRequests(int *requests, int totalRequests) {
    int i, j, temp;
    for (i = 0; i < totalRequests - 1; i++) {
        for (j = 0; j < totalRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

// Function to perform C-SCAN disk scheduling
void cscan(int *requests, int totalRequests, int startHeadPosition, int direction) {
    int totalHeadMovements = 0;
    int currentHeadPosition = startHeadPosition;
    int i, j;
    int headPositionIndex = -1;

    // Find the index where the current head position lies in the requests
    for (i = 0; i < totalRequests; i++) {
        if (requests[i] >= startHeadPosition) {
            headPositionIndex = i;
            break;
        }
    }

    // If not found, set to the last index
    if (headPositionIndex == -1) {
        headPositionIndex = totalRequests - 1;
    }

    printf("Order of requests served: ");

    // Move right
    if (direction == 1) {
        // Scan right from head position
        for (i = headPositionIndex; i < totalRequests; i++) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
        // Wrap around to the beginning and scan right again
        for (i = 0; i < headPositionIndex; i++) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
    }
    // Move left
    else if (direction == -1) {
        // Scan left from head position
        for (i = headPositionIndex; i >= 0; i--) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
        // Wrap around to the end and scan left again
        for (i = totalRequests - 1; i > headPositionIndex; i--) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
    }

    printf("\nTotal number of head movements: %d\n", totalHeadMovements);
}

int main() {
    int totalBlocks;
    int *requests;
    int startHeadPosition;
    int direction;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    requests = (int *)malloc(totalBlocks * sizeof(int));

    printf("Enter the disk request string:\n");
    for (int i = 0; i < totalBlocks; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &startHeadPosition);

    printf("Enter the direction (Left: -1, Right: 1): ");
    scanf("%d", &direction);

    // Perform C-SCAN disk scheduling
    cscan(requests, totalBlocks, startHeadPosition, direction);

    free(requests);

    return 0;
}
