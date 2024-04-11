#include <stdio.h>
#include <stdlib.h>

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

// Function to perform FCFS disk scheduling
void fcfs(int *requests, int totalRequests, int startHeadPosition) {
    int totalHeadMovements = 0;
    int currentHeadPosition = startHeadPosition;

    printf("Serving requests in FCFS order:\n");
    printf("Start Head Position: %d\n", startHeadPosition);
    printf("Order of requests served: %d", currentHeadPosition);
    for (int i = 0; i < totalRequests; i++) {
        printf(" -> %d", requests[i]);
        totalHeadMovements += abs(requests[i] - currentHeadPosition);
        currentHeadPosition = requests[i];
    }
    printf("\nTotal number of head movements: %d\n", totalHeadMovements);
}

int main() {
    int totalBlocks, *requests, startHeadPosition;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    requests = (int *)malloc(totalBlocks * sizeof(int));

    printf("Enter the disk request string:\n");
    for (int i = 0; i < totalBlocks; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &startHeadPosition);

    sortRequests(requests, totalBlocks);

    fcfs(requests, totalBlocks, startHeadPosition);

    free(requests);

    return 0;
}
