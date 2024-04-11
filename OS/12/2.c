#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to simulate C-LOOK disk scheduling algorithm
void clook(int request[], int n, int head, int direction) {
    int total_head_movements = 0;

    // Sort the request array in ascending order
    sortArray(request, n);

    if (direction == 0) { // Direction is Right
        for (int i = 0; i < n; i++) {
            if (request[i] >= head) {
                total_head_movements += abs(request[i] - head);
                printf("%d ", request[i]);
                head = request[i];
            }
        }
        // Go to the beginning of the disk
        total_head_movements += abs(head - 0);
        printf("0 ");
        head = 0;
        // Continue moving right from 0 to serve remaining requests
        for (int i = 0; i < n; i++) {
            if (request[i] < head) {
                total_head_movements += abs(request[i] - head);
                printf("%d ", request[i]);
                head = request[i];
            }
        }
    } else { // Direction is Left
        for (int i = n - 1; i >= 0; i--) {
            if (request[i] <= head) {
                total_head_movements += abs(request[i] - head);
                printf("%d ", request[i]);
                head = request[i];
            }
        }
        // Go to the end of the disk
        total_head_movements += abs(head - 199); // Assuming disk size is 200
        printf("199 ");
        head = 199;
        // Continue moving left from 199 to serve remaining requests
        for (int i = n - 1; i >= 0; i--) {
            if (request[i] > head) {
                total_head_movements += abs(request[i] - head);
                printf("%d ", request[i]);
                head = request[i];
            }
        }
    }

    printf("\nTotal Head Movements: %d\n", total_head_movements);
}

int main() {
    int n, head, direction;
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for Right, 1 for Left): ");
    scanf("%d", &direction);

    printf("Order of service:\n");
    clook(request, n, head, direction);

    return 0;
}
