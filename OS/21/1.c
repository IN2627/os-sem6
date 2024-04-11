#include <stdio.h>
#include <stdlib.h>
int main()
{
 int i, n, head, total_head_movements = 0;
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n);
 int disk_queue[n];
 printf("Enter the disk request string: ");
 for (i = 0; i < n; i++) {
 scanf("%d", &disk_queue[i]);
 }
 printf("Enter the current head position: ");
 scanf("%d", &head);
 printf("The list of requests in the order in which it is served:\n");
 printf("%d ", head);
 for (i = 0; i < n; i++) {
 total_head_movements += abs(disk_queue[i] - head);
 head = disk_queue[i];
 printf("%d ", head);
 }
 printf("\nTotal number of head movements: %d\n", total_head_movements);
 return 0;
}