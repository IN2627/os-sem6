#include <stdio.h>
#include <stdlib.h>
int main() {
 int n, head, i, j, temp, total_head_movements = 0;
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n);
 int disk_queue[n];
 printf("Enter the disk request string: ");
 for(i = 0; i < n; i++) {
 scanf("%d", &disk_queue[i]);
 }
 printf("Enter the current head position: ");
 scanf("%d", &head);
 int direction;
 printf("Enter the direction (0 for left, 1 for right): ");
 scanf("%d", &direction);
 for(i = 0; i < n-1; i++) {
 for(j = i+1; j < n; j++) {
 if(disk_queue[i] > disk_queue[j]) {
 temp = disk_queue[i];
 disk_queue[i] = disk_queue[j];
 disk_queue[j] = temp;
 }
 }
 }
 int index;
 for(i = 0; i < n; i++) {
 if(disk_queue[i] >= head) {
 index = i;
 break;
 }
 }
 if(direction == 0) {
 for(i = index-1; i >= 0; i--) {
 printf("%d ", disk_queue[i]);
 total_head_movements += abs(disk_queue[i] - head);
 head = disk_queue[i];
 }
 for(i = index; i < n; i++) {
 printf("%d ", disk_queue[i]);
 total_head_movements += abs(disk_queue[i] - head);
 head = disk_queue[i];
 }
 }
 else {
 for(i = index; i < n; i++) {
 printf("%d ", disk_queue[i]);
 total_head_movements += abs(disk_queue[i] - head);
 head = disk_queue[i];
 }
 for(i = index-1; i >= 0; i--) {
 printf("%d ", disk_queue[i]);
 total_head_movements += abs(disk_queue[i] - head);
 head = disk_queue[i];
 }
 }
 printf("\nTotal number of head movements: %d", total_head_movements);
 return 0;
}
