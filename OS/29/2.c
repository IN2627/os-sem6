#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
 return (*(int*)a - *(int*)b);
}
int main() {
 int n, head, i, j, moves = 0;
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n);
 int requests[n];
 printf("Enter the disk request string:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &requests[i]);
 }
 printf("Enter the starting head position: ");
 scanf("%d", &head);
 qsort(requests, n, sizeof(int), compare);
 int index;
 for (i = 0; i < n; i++) {
 if (requests[i] >= head) {
 index = i;
 break;
 }
 }
 printf("Enter the direction (0 for left, 1 for right): ");
 int direction;
 scanf("%d", &direction);
 if (direction == 0) {
 for (i = index - 1; i >= 0; i--) {
 printf("%d ", requests[i]);
 moves += abs(head - requests[i]);
 head = requests[i];
 }
 moves += head;
 for (i = n - 1; i >= index; i--) {
 printf("%d ", requests[i]);
 moves += abs(head - requests[i]);
 head = requests[i];
 }
 }
 else if (direction == 1) {
 for (i = index; i < n; i++) {
 printf("%d ", requests[i]);
 moves += abs(head - requests[i]);
 head = requests[i];
 }
 moves += abs(requests[n - 1] - requests[index - 1]);
 head = requests[n - 1];
 for (i = index - 1; i >= 0; i--) {
 printf("%d ", requests[i]);
 moves += abs(head - requests[i]);
 head = requests[i];
 }
 }
 printf("\nTotal number of head movements: %d\n", moves);
 return 0;
}