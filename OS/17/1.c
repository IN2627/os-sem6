#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BLOCK_SIZE 1024
int *disk;
int *free_blocks;
int *index_table;
int n_blocks;
void initialize_disk(int n) {
 /*
 * Initializes a disk with n number of blocks and randomly marks some blocks as allocated.
 */
 int i;
 disk = (int *) malloc(n * sizeof(int));
 free_blocks = (int *) malloc(n * sizeof(int));
 index_table = (int *) calloc(10, sizeof(int)); // Assume we have 10 files
 n_blocks = n;
 srand(time(NULL));
 for (i = 0; i < n; i++) {
 if ((double) rand() / RAND_MAX < 0.5) {
 disk[i] = 1;
 } else {
 disk[i] = 0;
 free_blocks[free_blocks[0] + 1] = i;
 free_blocks[0]++;
 }
 }
}
void show_bit_vector() {
 /*
 * Shows the bit vector for the disk.
 */
 int i, j;
 printf("Bit Vector:\n");
 for (i = 0; i < n_blocks; i += 10) {
 for (j = i; j < i + 10; j++) {
 if (j >= n_blocks) {
 break;
 }
 printf("%d ", disk[j]);
 }
 printf("\n");
 }
}
void show_directory() {
 /*
 * Shows the directory for the disk.
 */
 int i, j;
 printf("Directory:\n");
 for (i = 0; i < 10; i++) {
 printf("%d: ", i);
 for (j = 0; j < index_table[i]; j++) {
 printf("%d ", index_table[i * BLOCK_SIZE + j]);
 }
 printf("\n");
 }
}
void delete_file(int file_index) {
 /*
 * Deletes a file from the disk by setting its blocks to free.
 */
 int i, block_index;
 for (i = 0; i < index_table[file_index]; i++) {
 block_index = index_table[file_index * BLOCK_SIZE + i];
 disk[block_index] = 0;
 free_blocks[free_blocks[0] + 1] = block_index;
 free_blocks[0]++;
 }
 index_table[file_index] = 0;
}
int main() {
 int choice, file_index;
 printf("Enter the number of blocks on the disk: ");
 scanf("%d", &n_blocks);
 initialize_disk(n_blocks);
 while (1) {
 printf("\nMenu:\n");
 printf("1. Show Bit Vector\n");
 printf("2. Show Directory\n");
 printf("3. Delete a File\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 show_bit_vector();
 break;
 case 2:
 show_directory();
 break;
 case 3:
 printf("Enter the index of the file to delete: ");
 scanf("%d", &file_index);
 delete_file(file_index);
 printf("File %d deleted.\n", file_index);
 break;
 case 4:
 return 0;
 default:
 printf("Invalid choice. Please try again.\n");
 break;
 }
 }
}