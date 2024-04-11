#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalBlocks, startHead;
    int *requests;
    int headMovements = 0;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    requests = (int *)malloc(totalBlocks * sizeof(int));

    printf("Enter the disk request string: ");
    for (int i = 0; i < totalBlocks; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the start head position: ");
    scanf("%d", &startHead);

    printf("\nOrder of Requests Served:\n");
    printf("%d ", startHead);
    headMovements += abs(startHead - requests[0]);
    for (int i = 1; i < totalBlocks; i++) {
        printf("%d ", requests[i - 1]);
        headMovements += abs(requests[i] - requests[i - 1]);
    }
    printf("%d\n", requests[totalBlocks - 1]);

    printf("Total number of head movements: %d\n", headMovements);

    free(requests);
    return 0;
}