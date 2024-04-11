#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main()
{
 int n, head, i, j, temp, total_movement = 0;
 int queue[MAX], sequence[MAX];
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n);
 printf("Enter the disk request string:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &queue[i]);
 printf("Enter the current head position: ");
 scanf("%d", &head);
 printf("Enter the direction (1 for right, 0 for left): ");
 int direction;
 scanf("%d", &direction);
 // sort the request queue
 for (i = 0; i < n - 1; i++)
 {
 for (j = i + 1; j < n; j++)
 {
 if (queue[i] > queue[j])
 {
 temp = queue[i];
 queue[i] = queue[j];
 queue[j] = temp;
 }
 }
 }
 // find the head position in the request queue
 int start = 0;
 for (i = 0; i < n; i++)
 {
 if (queue[i] >= head)
 {
 start = i;
 break;
 }
 }
 // if direction is right
 if (direction == 1)
 {
 // add right end boundary
 sequence[0] = n - 1;
 for (i = 1, j = start; j < n; i++, j++)
 {
 sequence[i] = queue[j];
 }
 // add left end boundary
 sequence[i] = 0;
 for (j = start - 1; j >= 0; i++, j--)
 {
 sequence[i] = queue[j];
 }
 }
 // if direction is left
 else
 {
 // add left end boundary
 sequence[0] = 0;
 for (i = 1, j = start - 1; j >= 0; i++, j--)
 {
 sequence[i] = queue[j];
 }
 // add right end boundary
 sequence[i] = n - 1;
 for (j = start; j < n; i++, j++)
 {
 sequence[i] = queue[j];
 }
 }
 // print the sequence and calculate the total head movements
 printf("Sequence: ");
 for (i = 0; i <= n; i++)
 {
 printf("%d ", sequence[i]);
 if (i > 0)
 {
 total_movement += abs(sequence[i] - sequence[i - 1]);
 }
 }
 printf("\nTotal head movements: %d\n", total_movement);
 return 0;
}