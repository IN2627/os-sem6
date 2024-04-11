#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100
int main()
{
 int requests[MAX_REQUESTS];
 int num_requests;
 int current_head_position;
 int total_head_movements = 0;

 printf("Enter the total number of disk blocks: ");
 scanf("%d", &num_requests);

 printf("Enter the disk request string: ");
 for(int i = 0; i < num_requests; i++)
 {
 scanf("%d", &requests[i]);
 }

 printf("Enter the current head position: ");
 scanf("%d", &current_head_position);

 printf("Order of request served:\n");
 for(int i = 0; i < num_requests; i++)
 {
 printf("%d ", requests[i]);
 total_head_movements += abs(current_head_position - requests[i]);
 current_head_position = requests[i];
 }

 printf("\nTotal number of head movements: %d\n", total_head_movements);

 return 0;
}