#include <stdio.h>
#include <stdlib.h>
int main()
{
 int total_blocks, head_pos, requests[100], n, i, j, temp, head_moves = 0;
 // Accepting user input
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &total_blocks);
 printf("Enter the disk request string (end with -1):\n");
 n = 0;
 while (1) {
 scanf("%d", &requests[n]);
 if (requests[n] == -1) {
 break;
 }
 n++;
 }
 printf("Enter the current head position: ");
 scanf("%d", &head_pos);
 printf("Enter the direction (L for Left, R for Right): ");
 char dir;
 scanf(" %c", &dir);
 // Sorting the requests in ascending order
 for (i = 0; i < n-1; i++) {
 for (j = 0; j < n-i-1; j++) {
 if (requests[j] > requests[j+1]) {
 temp = requests[j];
 requests[j] = requests[j+1];
 requests[j+1] = temp;
 }
 }
 }
 // Finding the index of the request closest to the head position
 int index;
 for (i = 0; i < n; i++) {
 if (head_pos <= requests[i]) {
 index = i;
 break;
 }
 }
 // Traversing right and then left
 if (dir == 'R') {
 for (i = index; i < n; i++) {
 printf("%d ", requests[i]);
 head_moves += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 for (i = index-1; i >= 0; i--) {
 printf("%d ", requests[i]);
 head_moves += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 }
 // Traversing left and then right
 else {
 for (i = index-1; i >= 0; i--) {
 printf("%d ", requests[i]);
 head_moves += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 for (i = index; i < n; i++) {
 printf("%d ", requests[i]);
 head_moves += abs(requests[i] - head_pos);
 head_pos = requests[i];
 }
 }
 // Displaying the total number of head movements
 printf("\nTotal number of head movements: %d\n", head_moves);
 return 0;
}