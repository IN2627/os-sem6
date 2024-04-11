#include <stdio.h>
#include <stdlib.h>
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
int abs(int x) {
 return x >= 0 ? x : -x;
}
int compare(const void *a, const void *b) {
 return *(int *) a - *(int *) b;
}
void print_request_order(int *request_order, int n) {
 /*
 * Prints the order in which the disk requests are served.
 */
 int i;
 printf("Order of requests served: ");
 for (i = 0; i < n; i++) {
 printf("%d ", request_order[i]);
 }
 printf("\n");
}
void print_head_movements(int head_movements) {
 /*
 * Prints the total number of head movements.
 */
 printf("Total number of head movements: %d\n", head_movements);
}
int main() {
 int n_blocks, head_pos, direction, n_requests, i, j, k, head_movements = 0, min_request,
max_request, *requests, *request_order;
 printf("Enter the total number of disk blocks: ");
 scanf("%d", &n_blocks);
 printf("Enter the current head position: ");
 scanf("%d", &head_pos);
 printf("Enter the disk request string (separated by spaces): ");
 scanf("%d", &n_requests);
 requests = (int *) malloc(n_requests * sizeof(int));
 request_order = (int *) malloc(n_requests * sizeof(int));
 for (i = 0; i < n_requests; i++) {
 scanf("%d", &requests[i]);
 }
 printf("Enter the direction (0 for left, 1 for right): ");
 scanf("%d", &direction);
 qsort(requests, n_requests, sizeof(int), compare);
 for (i = 0; i < n_requests; i++) {
 if (requests[i] >= head_pos) {
 break;
 }
 }
 k = i;
 if (direction == DIRECTION_LEFT) {
 min_request = 0;
 max_request = k - 1;
 for (i = k - 1; i >= 0; i--) {
 request_order[max_request - i] = requests[i];
 }
 for (i = k; i < n_requests; i++) {
 request_order[i] = requests[i];
 }
 } else {
 min_request = k;
 max_request = n_requests - 1;
 for (i = k; i < n_requests; i++) {
 request_order[i - k] = requests[i];
 }
 for (i = k - 1; i >= 0; i--) {
 request_order[n_requests - 1 - i] = requests[i];
 }
 }
 for (i = 0; i < n_requests; i++) {
 head_movements += abs(request_order[i] - head_pos);
 head_pos = request_order[i];
 }
 print_request_order(request_order, n_requests);
 print_head_movements(head_movements);
 return 0;
} 