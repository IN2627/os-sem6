#include<stdio.h>
#include<stdlib.h>
int main() {
 int queue[100], n, head, i, j, k, seek_time = 0, diff;
 float avg_seek_time;
 printf("Enter the number of disk blocks: ");
 scanf("%d", &n);
 printf("Enter the disk request string: ");
 for(i = 0; i < n; i++)
 scanf("%d", &queue[i]);
 printf("Enter the current head position: ");
 scanf("%d", &head);
 printf("Enter the direction (0 for left, 1 for right): ");
 scanf("%d", &k);
 // Sorting the request queue
 for(i = 0; i < n-1; i++) {
 for(j = i+1; j < n; j++) {
 if(queue[i] > queue[j]) {
 int temp = queue[i];
 queue[i] = queue[j];
 queue[j] = temp;
 }
 }
 }
 int index;
 for(i = 0; i < n; i++) {
 if(queue[i] >= head) {
 index = i;
 break;
 }
 }
 if(k == 0) { // Head moving towards left direction
 for(i = index-1; i >= 0; i--) {
 seek_time += abs(head - queue[i]);
 head = queue[i];
 }
 seek_time += head;
 head = 0;
 for(i = n-1; i >= index; i--) {
 seek_time += abs(head - queue[i]);
 head = queue[i];
 }
 }
 else { // Head moving towards right direction
 for(i = index; i < n; i++) {
 seek_time += abs(head - queue[i]);
 head = queue[i];
 }
 seek_time += abs(head - (n-1));
 head = n-1;
 for(i = index-1; i >= 0; i--) {
 seek_time += abs(head - queue[i]);
 head = queue[i];
 }
 }
 avg_seek_time = (float)seek_time / n;
 printf("\nOrder of disk requests served:\n");
 for(i = 0; i < n; i++)
 printf("%d ", queue[i]);
 printf("\n\nTotal number of head movements: %d", seek_time);
 printf("\nAverage seek time: %f", avg_seek_time);
 return 0;
}