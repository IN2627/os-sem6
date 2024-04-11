#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of the nearest track to the current head position
int findNearestTrack(int tracks[], int n, int head) {
    int minDist = abs(tracks[0] - head);
    int index = 0;
    for (int i = 1; i < n; i++) {
        int dist = abs(tracks[i] - head);
        if (dist < minDist) {
            minDist = dist;
            index = i;
        }
    }
    return index;
}

int main() {
    int n, head, totalHeadMovements = 0;
    
    // Accepting total number of disk blocks
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);
    
    // Accepting disk request string
    int tracks[n];
    printf("Enter the disk request string:\n");
    for (int i = 0; i < n; i++) {
        printf("Track %d: ", i + 1);
        scanf("%d", &tracks[i]);
    }

    // Accepting current head position
    printf("Enter the current head position: ");
    scanf("%d", &head);
    
    // Sorting the tracks array in ascending order
    sort(tracks, n);

    // Displaying the sorted disk request string
    printf("\nSorted disk request string:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    printf("\nOrder of service:\n");
    int currentTrackIndex = findNearestTrack(tracks, n, head);
    while (currentTrackIndex != -1) {
        printf("%d ", tracks[currentTrackIndex]);
        totalHeadMovements += abs(head - tracks[currentTrackIndex]);
        head = tracks[currentTrackIndex];
        tracks[currentTrackIndex] = -1; // Marking the served track as visited
        currentTrackIndex = findNearestTrack(tracks, n, head);
    }
    printf("\n");

    // Displaying the total number of head movements
    printf("\nTotal number of head movements: %d\n", totalHeadMovements);

    return 0;
}
