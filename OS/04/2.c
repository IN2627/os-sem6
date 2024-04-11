#include <stdio.h>
#include <stdlib.h>

// Function to perform SCAN disk scheduling
void scan(int *requests, int totalRequests, int startHeadPosition, int direction) {
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

    // Move left
    if (direction == -1) {
        // Scan left from head position
        for (i = headPositionIndex; i >= 0; i--) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
        // Scan right from the beginning
        for (i = headPositionIndex + 1; i < totalRequests; i++) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
    }
    // Move right
    else if (direction == 1) {
        // Scan right from head position
        for (i = headPositionIndex; i < totalRequests; i++) {
            printf("%d ", requests[i]);
            totalHeadMovements += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
        // Scan left from the beginning
        for (i = headPositionIndex - 1; i >= 0; i--) {
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

    // Perform SCAN disk scheduling
    scan(requests, totalBlocks, startHeadPosition, direction);

    free(requests);

    return 0;
}
