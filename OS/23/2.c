#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void sstf(int queue[], int n, int head)
{
 int i, j, min, pos, count = 0;
 int visited[n];
 for (i = 0; i < n; i++) {
 visited[i] = 0;
 }
 printf("%d -> ", head);
 visited[head] = 1;
 count++;
 while (count < n) {
 min = INT_MAX;
 for (i = 0; i < n; i++) {
 if (!visited[i]) {
 if (abs(queue[i] - head) < min) {
 min = abs(queue[i] - head);
 pos = i;
 }
 }
 }
 visited[pos] = 1;
 count++;
 head = queue[pos];
 printf("%d -> ", head);
 }
}
int main()
{
 int n, i, head;
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n);
 int queue[n];
 printf("Enter the disk request string:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &queue[i]);
 }
 printf("Enter the current head position: ");
 scanf("%d", &head);
 sstf(queue, n, head);
 printf("\nTotal number of head movements: %d", n);
 return 0;
} 
