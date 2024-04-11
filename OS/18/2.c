#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
void sort(int arr[], int size) {
 for (int i = 0; i < size - 1; i++) {
 for (int j = i + 1; j < size; j++) {
 if (arr[i] > arr[j]) {
 swap(&arr[i], &arr[j]);
 }
 }
 }
}
int main() {
 int total_blocks, head_pos, num_requests, requests[MAX_SIZE], i, j, k, pos, direction,
head_moments;
 // Accept inputs from user
 printf("Enter total number of disk blocks: ");
 scanf("%d", &total_blocks);
 printf("Enter the disk request string (up to %d requests): ", MAX_SIZE);
 for (i = 0; i < MAX_SIZE; i++) {
 scanf("%d", &requests[i]);
 if (requests[i] == -1) {
 break;
 }
 }
 num_requests = i;
 printf("Enter current head position: ");
 scanf("%d", &head_pos);
 printf("Enter direction (0 for left, 1 for right): ");
 scanf("%d", &direction);
 // Add current head position to requests
 requests[num_requests++] = head_pos;
 // Sort requests in ascending order
 sort(requests, num_requests);
 // Find index of head position
 for (i = 0; i < num_requests; i++) {
 if (requests[i] == head_pos) {
 break;
 }
 }
 pos = i;
 // Serve requests in SCAN order
 head_moments = 0;
 printf("Order of request served:\n");
 if (direction == 1) { // Right
 for (i = pos; i < num_requests; i++) {
 printf("%d ", requests[i]);
 head_moments += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 for (i = num_requests - 2; i >= 0; i--) {
 printf("%d ", requests[i]);
 head_moments += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 } else { // Left
 for (i = pos; i >= 0; i--) {
 printf("%d ", requests[i]);
 head_moments += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 for (i = 1; i < num_requests; i++) {
 printf("%d ", requests[i]);
 head_moments += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 }
 printf("\nTotal number of head movements: %d\n", head_moments);
 return 0;
} 