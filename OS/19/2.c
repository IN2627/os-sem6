#include <stdio.h>
#include <stdlib.h>

// Function to sort the request array
void sort(int request[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
}

// Function to perform C-SCAN disk scheduling
void cscan(int request[], int n, int start, char direction) {
    int totalHeadMovements = 0;

    // Sort the request array
    sort(request, n);

    int headPos = start;
    int currentIndex = 0;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Handle left direction
    if (direction == 'L') {
        printf("Head Movement Order: %d ", headPos);
        while (currentIndex < n) {
            if (request[currentIndex] >= headPos) {
                currentIndex++;
            } else {
                totalHeadMovements += abs(request[currentIndex] - headPos);
                headPos = request[currentIndex];
                visited[currentIndex] = 1;
                printf("%d ", headPos);
                currentIndex++;
            }
        }
        printf("0 ");

        // Move to the end of the disk and reverse direction
        totalHeadMovements += headPos;
        headPos = 0;
        printf("%d ", headPos);

        for (int i = n - 1; i >= 0; i--) {
            if (!visited[i]) {
                totalHeadMovements += abs(request[i] - headPos);
                headPos = request[i];
                printf("%d ", headPos);
            }
        }
    }
    printf("\nTotal Head Movements: %d\n", totalHeadMovements);
}

int main() {
    int n;
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    int start;
    printf("Enter the start head position: ");
    scanf("%d", &start);

    char direction;
    printf("Enter the direction (L for Left, R for Right): ");
    scanf(" %c", &direction);

    printf("\nDisk Scheduling using C-SCAN Algorithm:\n");
    cscan(request, n, start, direction);

    return 0;
}

// You can compile and run this program to simulate the C-SCAN disk scheduling algorithm. It takes input for the total number of disk blocks, the disk request string, the start head position, and the direction of movement (Left or Right). The program then displays the order in which requests are served and the total number of head movements incurred.